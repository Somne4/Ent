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
int main(int argc, char *argv[])
{
      QCoreApplication a(argc, argv);
      QList<QString> h1, h2, h3, h4;
      QString n1, n2, n3 , n4;

      n1 = "Royal Dutch Shell";
      h1 << "Ben van Beurden" << "Charles Halliday";
      Entreprise* e1 = new NationalEntreprise(n1, h1, 13425000000, 7886, 82000);

      n2 = "British American Tobacco";
      h2 << "Jack Bowles";
      Entreprise* e2 = new NationalEntreprise(n2, h2, 4600000000, 5664, 55000);

      n3 = "Amazon";
      h3 << "Jeff Bezos";
      Entreprise* e3 = new ForeignEntreprise(n3, h3, 21300000000, 18923, 1298000);

      n4 = "Sberbank";
      h4 << "German Gref" << "Sergey Ignatiev";
      Entreprise* e4 = new MixedEntreprise(n4, h4, 1125000000, 5234, 281000);

      reg.AddEnt(*e1);
      reg.AddEnt(*e2);
      reg.AddEnt(*e3);
      reg.AddEnt(*e4);

      int p = 0;

      cout << "Select the type of enterprise: 1) National, 2) Foreign, 3) Mixed" << Qt::endl;
      cout << "Enter type: ";
      cin >> p;

      EntNameByType(Entreprise::type(p));

      EntByHolder("Jeff Bezos");

      cout << Qt::endl;

      EntDataByType();

      return a.exec();
}
