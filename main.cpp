#include <iostream>
#include <QApplication>
#include "ChatSession.h"
#include "ChatWindow.h"

int main(int argc, char** argv)
{
    QApplication application{argc, argv};
    ChatSession session{};
    ChatWindow window1{session, "Andu"};
    ChatWindow window2{session, "Hori"};
    ChatWindow window3{session, "Răzvan"};
    window1.show();
    window2.show();
    window3.show();
    return QApplication::exec();
}