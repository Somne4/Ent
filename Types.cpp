#include "entreprise.h"
#include "Types.h"

NationalEntreprise::NationalEntreprise(QString &name, QList<QString> &holders, double income, double area, int NumberEmp):
    Entreprise(name, holders, income, area, NumberEmp)
{
}

Entreprise::type NationalEntreprise::getEntType()
{
    return type::National;
}

double NationalEntreprise::getEntTax()
{
    double Income = getEntIncome()*0.08;
    double AreaIncome = getEntIncome()*0.04;
    double EmpIncome = getEntIncome()*0.02;
    return Income + AreaIncome + EmpIncome;
}

ForeignEntreprise::ForeignEntreprise(QString &name, QList<QString> &holders, double income, double area, int NumberEmp):
    Entreprise(name, holders, income, area, NumberEmp)
{
}

Entreprise::type ForeignEntreprise::getEntType()
{
    return type::Foreign;
}

double ForeignEntreprise::getEntTax()
{
    double Income = getEntIncome()*0.4;
    double AreaIncome = getEntIncome()*0.3;
    double EmpIncome = getEntIncome()*0.2;
    return EmpIncome*AreaIncome/Income;
}


MixedEntreprise::MixedEntreprise(QString &name, QList<QString> &holders, double income, double area, int NumberEmp):
    Entreprise(name, holders, income, area, NumberEmp)
{
}

Entreprise::type MixedEntreprise::getEntType()
{
    return type::Mixed;
}

double MixedEntreprise::getEntTax()
{
    double Income = getEntIncome()*0.5;
    return Income/3;
}


