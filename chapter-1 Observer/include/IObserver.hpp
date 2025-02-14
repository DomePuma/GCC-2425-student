#ifndef IOBSERVER_HPP
#define IOBSERVER_HPP

struct IObserver
{
    virtual void Update() = 0;
    virtual ~IObserver() = default;
};

#endif //IOBSERVER_HPP