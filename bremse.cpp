#include "bremse.h"

Bremse::Bremse()
{

}

bool Bremse::getBremse()
{
    return bremse;
}

void Bremse::setBremse(bool b)
{
    bremse = b;
}
