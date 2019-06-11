#include <QtWidgets/QShortcut>
#include "ChatWindow.h"
#include "ui_chatwindow.h"

ChatWindow::ChatWindow(ChatSession &session, std::string username, QWidget *parent) : QWidget(parent),
                                                                                      ui(new Ui::ChatWindow),
                                                                                      session{session},
                                                                                      username{username}
{
    ui->setupUi(this);
    session.attach(this);
    QObject::connect(ui->sendButton, &QPushButton::clicked, this, &ChatWindow::sendMessage);
    setWindowTitle(QString::fromStdString(username + "'s chat window"));
    QShortcut *shortcut = new QShortcut(Qt::Key_Return, this);
    QObject::connect(shortcut, &QShortcut::activated, this, &ChatWindow::sendMessage);
    QObject::connect(ui->messageList, &QListWidget::clicked, this, &ChatWindow::listClicked);
}

void ChatWindow::update()
{
    auto messages = session.getMessages();
    ui->messageList->clear();
    for (auto &message : messages)
    {
        QListWidgetItem *item;
        if (message.getForward().empty())
        {
            item = new QListWidgetItem(
                    QString::fromStdString(message.getMessage()));
        }
        else
        {
            item = new QListWidgetItem(
                    QString::fromStdString(
                            "\"" + message.getForward() + "\" -> \n" +
                            message.getMessage()));
        }
        if (username == message.getUsername())
        {
            item->setForeground(Qt::magenta);
            item->setTextAlignment(Qt::AlignRight);
        }
        else
        {
            item->setText(QString::fromStdString("[" + message.getUsername() + "]: ") + item->text());
        }
        ui->messageList->addItem(item);
    }
}

ChatWindow::~ChatWindow()
{
    delete ui;
    session.detach(this);
}

void ChatWindow::sendMessage()
{
    if (ui->editMessage->text().isEmpty())
    {
        return;
    }
    std::string forward{};
    if (row >= 0)
    {
        forward = session.getMessages()[row].getMessage();
    }
    session.addMessage(Message{ui->editMessage->text().toStdString(), username, forward});
    ui->editMessage->clear();
    row = -1;
}

void ChatWindow::listClicked()
{
    row = ui->messageList->currentRow();
    ui->editMessage->setFocus();
}
