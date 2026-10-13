#include "DigitalClock.h"
#include "ConsolIO.h"
#include <iostream>
#include <thread>
#include <chrono>

using namespace std;

DigitalClock::DigitalClock() : ringCounter(0)
{
    cout << "\tГодинник створено (00:00:00, 01.01.2026)" << endl;
}

DigitalClock::DigitalClock(int d, int mo, int y, int h, int mi, int s)
    : ringCounter(0)
{
    setDateTime(d, mo, y, h, mi, s);
}

DigitalClock::~DigitalClock()
{
    cout << "\n\tГодинник вимкнено." << endl;
}

bool DigitalClock::setDateTime(int d, int mo, int y, int h, int mi, int s)
{
    // Перевіряємо обидві частини ДО зміни стану
    DateController testDate;
    TimeController testTime;
    if (!testDate.setDate(d, mo, y) || !testTime.setTime(h, mi, s))
        return false;

    dateCtrl.setDate(d, mo, y);
    timeCtrl.setTime(h, mi, s);
    ringCounter = 0;
    return true;
}

bool DigitalClock::setAlarm(int h, int mi)
{
    return timeCtrl.setAlarm(h, mi);
}

void DigitalClock::cancelAlarm()
{
    timeCtrl.cancelAlarm();
    ringCounter = 0;
}

void DigitalClock::tick()
{
    // Якщо настала нова доба - контролер дати переходить на наступний день
    if (timeCtrl.tick())
        dateCtrl.nextDay();

    // Будильник дзвонить RING_DURATION секунд, потім вимикається
    if (timeCtrl.isRinging())
    {
        ringCounter++;
        if (ringCounter > RING_DURATION)
        {
            timeCtrl.stopAlarm();
            ringCounter = 0;
        }
    }
}

void DigitalClock::show() const
{
    screen.show(timeCtrl, dateCtrl);
}

void DigitalClock::simulate(int seconds, int delayMs)
{
    cout << "\n\tІмітація ходу годинника (" << seconds << " с):\n" << endl;

    for (int i = 0; i < seconds; i++)
    {
        tick();
        screen.showLine(timeCtrl, dateCtrl);
        this_thread::sleep_for(chrono::milliseconds(delayMs));
    }
}

void DigitalClock::inputDateTime()
{
    while (true)
    {
        cout << "\n\tВстановлення дати і часу" << endl;
        int d = ConsolIO::GetInt("\tДень (1-31): ", 1, 31);
        int mo = ConsolIO::GetInt("\tМісяць (1-12): ", 1, 12);
        int y = ConsolIO::GetInt("\tРік (1900-2100): ", 1900, 2100);
        int h = ConsolIO::GetInt("\tГодини (0-23): ", 0, 23);
        int mi = ConsolIO::GetInt("\tХвилини (0-59): ", 0, 59);
        int s = ConsolIO::GetInt("\tСекунди (0-59): ", 0, 59);

        if (setDateTime(d, mo, y, h, mi, s))
        {
            cout << "\n\tДату і час встановлено." << endl;
            return;
        }
        cout << "\n\tТакої дати не існує (наприклад, 31.04 або 29.02 у "
            "невисокосному році). Повторіть." << endl;
    }
}

void DigitalClock::inputAlarm()
{
    cout << "\n\tВстановлення будильника" << endl;
    int h = ConsolIO::GetInt("\tГодини (0-23): ", 0, 23);
    int mi = ConsolIO::GetInt("\tХвилини (0-59): ", 0, 59);

    if (setAlarm(h, mi))
        cout << "\n\tБудильник встановлено на " << timeCtrl.alarmToString() << endl;
}