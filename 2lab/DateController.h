#pragma once
#include <string>

/*------------------------------------------------
КОНТРОЛЕР ДАТИ: зберігає та змінює календарну дату
------------------------------------------------*/
class DateController
{
private:
    int day;
    int month;
    int year;

public:
    DateController();                           // 01.01.2026
    DateController(int d, int m, int y);
    ~DateController();

    int getDay() const;
    int getMonth() const;
    int getYear() const;

    // Статичні допоміжні методи
    static bool isLeapYear(int y);
    static int  daysInMonth(int m, int y);

    // Встановлення дати (false, якщо дата некоректна)
    bool setDate(int d, int m, int y);

    // Перехід на наступний день
    void nextDay();

    std::string toString() const;               // "DD.MM.YYYY"
};
