#include "DateController.h"
#include <sstream>
#include <iomanip>

DateController::DateController() : day(1), month(1), year(2026)
{
}

DateController::DateController(int d, int m, int y) : day(1), month(1), year(2026)
{
    setDate(d, m, y);
}

DateController::~DateController()
{
}

int DateController::getDay() const { return day; }
int DateController::getMonth() const { return month; }
int DateController::getYear() const { return year; }

bool DateController::isLeapYear(int y)
{
    return (y % 4 == 0 && y % 100 != 0) || (y % 400 == 0);
}

int DateController::daysInMonth(int m, int y)
{
    switch (m)
    {
    case 4: case 6: case 9: case 11:
        return 30;
    case 2:
        return isLeapYear(y) ? 29 : 28;
    default:
        return 31;
    }
}

bool DateController::setDate(int d, int m, int y)
{
    if (y < 1900 || y > 2100) return false;
    if (m < 1 || m > 12) return false;
    if (d < 1 || d > daysInMonth(m, y)) return false;

    day = d;
    month = m;
    year = y;
    return true;
}

void DateController::nextDay()
{
    day++;
    if (day > daysInMonth(month, year))
    {
        day = 1;
        month++;
        if (month > 12)
        {
            month = 1;
            year++;
        }
    }
}

std::string DateController::toString() const
{
    std::ostringstream os;
    os << std::setfill('0') << std::setw(2) << day << "."
        << std::setw(2) << month << "."
        << std::setw(4) << year;
    return os.str();
}