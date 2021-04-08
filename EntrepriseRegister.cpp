#include "Register.h"

EntRegister::EntRegister()
{}

EntRegister::~EntRegister()
{
    while(!EntList.empty())
    {
        delete EntList.takeFirst();
    }
}

void EntRegister::AddEnt(Entreprise& entreprise)
{
    EntList.append(&entreprise);
}

Entreprise* EntRegister::getEntInd(int index)
{
    return EntList.at(index);
}

int EntRegister::getRegSize()
{
    return EntList.size();
}

EntRegister& EntRegister::getReg()
{
    static EntRegister reg;
    return reg;
}
