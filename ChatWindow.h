#ifndef CHATWINDOW_H
#define CHATWINDOW_H

#include <QWidget>
#include "ChatSession.h"

namespace Ui {
class ChatWindow;
}

class ChatWindow : public QWidget, public Observer
{
    Q_OBJECT
    ChatSession &session;
    std::string username;
    int row = -1;
public:


    ChatWindow(ChatSession &session, std::string username, QWidget *parent = nullptr);
    ~ChatWindow() override;

    void update() override;

    void sendMessage();

    void listClicked();

private:
    Ui::ChatWindow *ui;
};

#endif // CHATWINDOW_H
