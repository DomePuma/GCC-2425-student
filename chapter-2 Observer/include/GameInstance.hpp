#ifndef GAMEINSTANCE_HPP
#define GAMEINSTANCE_HPP

#include <vector>
#include <algorithm>

#include "ISubject.hpp"

class GameInstance : public ISubject
{

    private :
        std::vector<IObserver*> observerPtrArray;
        int m_state;
    public :
        ~GameInstance()
        {
            for(auto* observer:this->observerPtrArray)
            {
                observer = nullptr;
                delete observer;
            }
        }
        
        int GetState() override
        {
            return this->m_state;
        }

        void SetState(int state) override
        {
            this->m_state = state;
            NotifyAllObserver(); 
        }

        void NotifyAllObserver() override
        {
            for(auto* observer:this->observerPtrArray)
            {
                observer->Update();
            }
        }

        void Attach(IObserver* observerPtr)
        {
            this->observerPtrArray.push_back(observerPtr);
        }

        void Dettach(IObserver* observerPtr)
        {
            auto interator = std::remove(this->observerPtrArray.begin(), this->observerPtrArray.end(), observerPtr);
            this->observerPtrArray.erase(interator, this->observerPtrArray.end());
        }
};

#endif //GAMEINSTANCE_HPP