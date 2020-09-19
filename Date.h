#ifndef DATE_H
#define DATE_H


class Date
{
    public:
        Date();
        Date(int, int, int);
        int getDay();
        int getMonth();
        int getYear();
        void setDay(int day);
        void setMonth(int month);
        void setYear(int year);
        bool operator>(Date d);
        int operator-(Date d);

    private:
        int day;
        int month;
        int year;
};

#endif // DATE_H
