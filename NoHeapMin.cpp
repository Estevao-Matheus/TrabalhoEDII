
#include <iostream>
#include "NoHeapMin.h"


using namespace std;

NoHeapMin::NoHeapMin(char inf, int frenq)
{

    info=inf;
    frenquencia=frenq;
    esqu= nullptr;
    dir = nullptr;
}

bool NoHeapMin::vericaFolha()
{

    if(esqu== nullptr&&dir== nullptr)
    {
        return true;
    }else
        return false;


}
