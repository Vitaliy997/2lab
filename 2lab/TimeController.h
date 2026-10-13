#pragma once
#include <string>

/*------------------------------------------------
КОНТРОЛЕР АСУ: зберігає час (год:хв:с),
час будильника та керує ходом годинника
------------------------------------------------*/
class TimeController
{
private:
    int hours;          // 0..23
    int minutes;        // 0..59
    int seconds;        // 0..59
    int alarmHours;     // година будильника
    int alarmMinutes;   // хвилина будильника
    bool alarmSet;      // чи встановлено будильник
    bool ringing;       // чи дзвонить будильник зараз

public:
    TimeController();                       // 00:00:00
    TimeController(int h, int m, int s);    // з параметрами
    ~TimeController();

    // Методи доступу
    int  getHours() const;
    int  getMinutes() const;
    int  getSeconds() const;
    int  getAlarmHours() const;
    int  getAlarmMinutes() const;
    bool isAlarmSet() const;
    bool isRinging() const;

    // Встановлення значень (повертають false при некоректних даних)
    bool setTime(int h, int m, int s);
    bool setAlarm(int h, int m);
    void cancelAlarm();
    void stopAlarm();

    // Один крок годинника (+1 секунда).
    // Повертає true, якщо настала нова доба (перехід через 00:00:00)
    bool tick();

    // Рядкове представлення
    std::string timeToString() const;       // "HH:MM:SS"
    std::string alarmToString() const;      // "HH:MM" або "не встановлено"
};
