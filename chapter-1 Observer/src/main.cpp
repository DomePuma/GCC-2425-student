#include <iostream>

#include "Scoreboard.hpp"
#include "GameInstance.hpp"

int main()
{
    ISubject* a = new GameInstance();
    IObserver* o = new Scoreboard(a);

    a->SetState(10);

    a->Dettach(o);

    a->SetState(10);

    return 0;
}