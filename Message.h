#ifndef CHATWINDOWS_MESSAGE_H
#define CHATWINDOWS_MESSAGE_H

#include <string>
class Message
{
    std::string message;
    std::string username;
    std::string forward;
public:
    const std::string &getForward() const;

    void setForward(const std::string &forward);

public:
    Message(const std::string &message, const std::string &username, std::string forward = std::string{});

public:
    const std::string &getMessage() const;

    const std::string &getUsername() const;
};


#endif //CHATWINDOWS_MESSAGE_H
