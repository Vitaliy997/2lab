#include "TimeController.h"
#include <sstream>
#include <iomanip>

TimeController::TimeController()
    : hours(0), minutes(0), seconds(0),
    alarmHours(0), alarmMinutes(0), alarmSet(false), ringing(false)
{
}

TimeController::TimeController(int h, int m, int s)
    : hours(0), minutes(0), seconds(0),
    alarmHours(0), alarmMinutes(0), alarmSet(false), ringing(false)
{
    setTime(h, m, s);
}

TimeController::~TimeController()
{
    // динамічної пам'яті немає - нічого звільняти
}

int  TimeController::getHours() const { return hours; }
int  TimeController::getMinutes() const { return minutes; }
int  TimeController::getSeconds() const { return seconds; }
int  TimeController::getAlarmHours() const { return alarmHours; }
int  TimeController::getAlarmMinutes() const { return alarmMinutes; }
bool TimeController::isAlarmSet() const { return alarmSet; }
bool TimeController::isRinging() const { return ringing; }

bool TimeController::setTime(int h, int m, int s)
{
    if (h < 0 || h > 23 || m < 0 || m > 59 || s < 0 || s > 59)
        return false;
    hours = h;
    minutes = m;
    seconds = s;
    ringing = false;
    return true;
}

bool TimeController::setAlarm(int h, int m)
{
    if (h < 0 || h > 23 || m < 0 || m > 59)
        return false;
    alarmHours = h;
    alarmMinutes = m;
    alarmSet = true;
    return true;
}

void TimeController::cancelAlarm()
{
    alarmSet = false;
    ringing = false;
}

void TimeController::stopAlarm()
{
    ringing = false;
}

bool TimeController::tick()
{
    bool newDay = false;

    seconds++;
    if (seconds == 60)
    {
        seconds = 0;
        minutes++;
        if (minutes == 60)
        {
            minutes = 0;
            hours++;
            if (hours == 24)
            {
                hours = 0;
                newDay = true;
            }
        }
    }

    // Перевірка спрацьовування будильника (на початку потрібної хвилини)
    if (alarmSet && hours == alarmHours && minutes == alarmMinutes && seconds == 0)
        ringing = true;

    return newDay;
}

std::string TimeController::timeToString() const
{
    std::ostringstream os;
    os << std::setfill('0') << std::setw(2) << hours << ":"
        << std::setw(2) << minutes << ":"
        << std::setw(2) << seconds;
    return os.str();
}

std::string TimeController::alarmToString() const
{
    if (!alarmSet)
        return "не встановлено";
    std::ostringstream os;
    os << std::setfill('0') << std::setw(2) << alarmHours << ":"
        << std::setw(2) << alarmMinutes;
    return os.str();
}