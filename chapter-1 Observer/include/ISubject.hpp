#ifndef ISUBJECT_HPP
#define ISUBJECT_HPP

#include "IObserver.hpp"

struct ISubject
{
    virtual int GetState() = 0;
    virtual void SetState(int nb) = 0;
    virtual void Attach(IObserver* observer) = 0;
    virtual void Dettach(IObserver* observer) = 0;
    virtual void NotifyAllObserver() = 0;
    virtual ~ISubject() = default;
};

#endif //SUBJECT_HPP