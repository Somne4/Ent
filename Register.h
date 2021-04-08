#ifndef REGISTER_H
#define REGISTER_H
#include "entreprise.h"
#include <QList>

class EntRegister
{
private:
    QList<Entreprise*> EntList;
    EntRegister();
public:
    ~EntRegister();
    EntRegister(const EntRegister&) = delete;
    void AddEnt(Entreprise& entreprise);
    Entreprise* getEntInd(int index);
    int getRegSize();
    static EntRegister& getReg();
};

#endif
