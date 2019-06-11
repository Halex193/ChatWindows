#ifndef CHATWINDOWS_OBSERVER_H
#define CHATWINDOWS_OBSERVER_H


class Observer
{
public:
    virtual void update() = 0;
    virtual ~Observer()
    = default;;
};


#endif //CHATWINDOWS_OBSERVER_H
