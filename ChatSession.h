#ifndef CHATWINDOWS_CHATSESSION_H
#define CHATWINDOWS_CHATSESSION_H


#include "Observable.h"
#include "Message.h"
#include <vector>

class ChatSession : public Observable
{
    std::vector<Message> messages;
public:
    void addMessage(Message message);

    std::vector<Message> getMessages();
};


#endif //CHATWINDOWS_CHATSESSION_H
