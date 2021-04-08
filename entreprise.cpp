#include "entreprise.h"

Entreprise::Entreprise(QString &name, QList<QString> &holders, double income, double area, int NumberEmp)
{
    EntName = name;
    EntHolders = holders;
    EntIncome = income;
    EntArea= area;
    EmployeerNumber = NumberEmp;
}

Entreprise::~Entreprise() {}

QString Entreprise::getEntName()
{
    return EntName;
}

QList<QString> Entreprise::getEntHolders()
{
    return EntHolders;
}

double Entreprise::getEntIncome()
{
    return EntIncome;
}

double Entreprise::getEntArea()
{
    return EntArea;
}

int Entreprise::getEmployeerNumber()
{
    return EmployeerNumber;
}















