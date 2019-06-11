#include "ChatSession.h"

void ChatSession::addMessage(Message message)
{
    messages.push_back(message);
    notify();
}

std::vector<Message> ChatSession::getMessages()
{
    return messages;
}
