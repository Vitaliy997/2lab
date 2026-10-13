#include "Screen.h"
#include <iostream>

using namespace std;

Screen::Screen()
{
}

Screen::~Screen()
{
}

void Screen::show(const TimeController& t, const DateController& d) const
{
    cout << "\n\t+------------------------------+" << endl;
    cout << "\t|      ЦИФРОВИЙ ГОДИННИК       |" << endl;
    cout << "\t+------------------------------+" << endl;
    cout << "\t  Час:        " << t.timeToString() << endl;
    cout << "\t  Дата:       " << d.toString() << endl;
    cout << "\t  Будильник:  " << t.alarmToString() << endl;
    cout << "\t+------------------------------+" << endl;
}

void Screen::showLine(const TimeController& t, const DateController& d) const
{
    cout << "\t[ " << t.timeToString() << " | " << d.toString()
        << " | будильник: " << t.alarmToString() << " ]";

    if (t.isRinging())
        cout << "  *** БУДИЛЬНИК! БІП-БІП-БІП! ***";

    cout << endl;
}