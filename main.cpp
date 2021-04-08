#include <QTextStream>
#include <QCoreApplication>
#include "Types.h"
#include "Register.h"

QTextStream cout(stdout);
QTextStream cin(stdin);
EntRegister& reg = EntRegister::getReg();

// 1. Вывести на консоль информацию о предприятиях определённого типа.

void EntNameByType(Entreprise::type EntType) // Название предприятия по типу
{
    switch (EntType)
    {
    case Entreprise::type::National:
        cout << "National Entreprise: ";
        break;
    case Entreprise::type::Foreign:
        cout << "Foreign Entreprise: ";
        break;
    case Entreprise::type::Mixed:
        cout << "Mixed Entreprise: ";
        break;
    }

    cout << Qt::endl;

    for (int i = 0; i < reg.getRegSize(); i++)
    {
        Entreprise* ind = reg.getEntInd(i);
        if (ind -> getEntType() == EntType)
        {
            cout << ind -> getEntName() << Qt::endl;
        }
    }
}

// 2. Вывести на консоль все предприятия, принадлежащие определённому владельцу.

void EntByHolder(QString&& h)
{
    cout << h << "'s entreprises: "<< Qt::endl;
    for(int i = 0; i < reg.getRegSize(); i++)
    {
        Entreprise* ind = reg.getEntInd(i);
        if(ind->getEntHolders().contains(h))
        {
            cout << ind -> getEntName() << Qt::endl;
        }
    }
}
// 3. Вывести на консоль средние показатели (доход, площадь, число сотрудников) предприятий для каждого из типов.
void EntDataByType() // Название предприятия по типу
{
    for(int p = Entreprise::type::National; p <= Entreprise::type::Mixed; p++)
    {
        int t = 0;
        double AvIncome = 0;
        double AvArea = 0;
        double AvNumber = 0;

        switch (p)
        {
        case Entreprise::type::National:
            cout << "National Entreprise Data: ";
            break;
        case Entreprise::type::Foreign:
            cout << "Foreign Entreprise Data: ";
            break;
        case Entreprise::type::Mixed:
            cout << "Mixed Entreprise Data: ";
            break;
        }
        cout << Qt::endl;

        for (int i = 0; i < reg.getRegSize(); i++)
        {
            Entreprise* ind = reg.getEntInd(i);
            if (p == ind -> getEntType())
            {
                AvIncome += ind -> getEntIncome();
                AvArea += ind -> getEntArea();
                AvNumber += ind -> getEmployeerNumber();
                t++;
            }
        }
        cout << "Avg Income = " << AvIncome / t << Qt::endl;
        cout << "Avg Area = " << AvArea / t << Qt::endl;
        cout << "Avg Number of employees = " << AvNumber / t << Qt::endl;
        cout << Qt::endl;
    }
}
