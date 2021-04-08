#ifndef TYPES_H
#define TYPES_H
#include "entreprise.h"

/*
Далее, требуется реализовать три класса предприятий различных типов.
Чистые виртуальные методы в них должны быть переопределены.
Формула вычисления налога может быть любой, но она должна быть уникальной для каждого типа предприятий.
Также, каждое из свойств (доход, площадь, число сотрудников) должно быть использовано для вычисления налога хотя бы в одном из типов предприятий.
(т.е., не должно остаться свойства, которое нигде не использовалось для вычисления налога).
*/

class NationalEntreprise : public Entreprise
{
public:
    NationalEntreprise(QString &name, QList<QString> &holders, double income, double area, int NumberEmp);
    type getEntType();
    double getEntTax();
};

class ForeignEntreprise : public Entreprise
{
public:
    ForeignEntreprise(QString &name, QList<QString> &holders, double income, double area, int NumberEmp);
    type getEntType();
    double getEntTax();
};

class MixedEntreprise : public Entreprise
{
public:
    MixedEntreprise(QString &name, QList<QString> &holders, double income, double area, int NumberEmp);
    type getEntType();
    double getEntTax();
};


#endif // TYPES_H
