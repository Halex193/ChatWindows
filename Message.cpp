#include "Message.h"

const std::string &Message::getMessage() const
{
    return message;
}

const std::string &Message::getUsername() const
{
    return username;
}

Message::Message(const std::string &message, const std::string &username, std::string forward)
        : message(message), username(username), forward(forward)
{}

const std::string &Message::getForward() const
{return forward;

}

void Message::setForward(const std::string &forward)
{
    Message::forward = forward;
}
