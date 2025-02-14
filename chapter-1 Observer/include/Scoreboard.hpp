#ifndef SCOREBOARD_HPP
#define SCOREBOARD_HPP

#include <iostream>

#include "ISubject.hpp"
#include "IObserver.hpp"

class Scoreboard : public IObserver
{
    private :
        ISubject* SBsubject;
    public :
        Scoreboard(ISubject* subject)
        {
            this->SBsubject = subject;
            this->SBsubject->Attach(this); 
        }
        
        ~Scoreboard()
        {
            this->SBsubject = nullptr;
            delete this->SBsubject;
        }
        void Update() override
        {
            std::cout<<"Updated"<<std::endl;
        }
};

#endif //SCOREBOARD_HPP