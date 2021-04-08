#ifndef ENTREPRISE_H
#define ENTREPRISE_H

#include <QString>
#include <QList>

/*Для этого потребуется реализовать абстрактный класс предприятия, который будет содержать следующие данные:
- название предприятия (QString);
- список владельцев предприятия (QList<QString>);
- доход предприятия (double);
- площадь предприятия (double);
- количество сотрудников предприятия (int).
Для каждого из этих свойств должны быть реализованы методы их получения/удаления.
Помимо этого, в базовом классе содержится объявление перечисления (enum), значениями которого являются возможные типы предприятий.
Следующие методы должны быть объявлены как чистые виртуальные:
- получение тип предприятия;
- получение налога в месяц с предприятия.
*/


class Entreprise
{
private:
    QString EntName; // название
    QList<QString> EntHolders; // владельцы
    double EntIncome; // доход
    double EntArea; // площадь
    int EmployeerNumber; // кол-во сотрудников
public:
    enum type
    {
        National = 1,
        Foreign = 2,
        Mixed = 3
    };
    Entreprise(QString &name, QList<QString> &holders, double income, double area, int NumberEmp);
    virtual ~Entreprise();
    virtual type getEntType() = 0; // тип предприятия
    virtual double getEntTax() = 0; // налог в месяц предприятия
    QString getEntName();
    QList<QString> getEntHolders();
    double getEntIncome();
    double getEntArea();
    int getEmployeerNumber();
};

#endif



