#pragma once
#include "TimeController.h"
#include "DateController.h"
#include "Screen.h"

/*------------------------------------------------
ЦИФРОВИЙ ГОДИННИК: містить об'єкти контролера
часу (АСУ), контролера дати та екрана
------------------------------------------------*/
class DigitalClock
{
private:
    TimeController timeCtrl;    // КОНТРОЛЕР АСУ
    DateController dateCtrl;    // КОНТРОЛЕР ДАТИ
    Screen screen;              // ЕКРАН
    int ringCounter;            // скільки секунд уже дзвонить будильник

    static const int RING_DURATION = 5;     // тривалість дзвінка, с

public:
    DigitalClock();
    DigitalClock(int d, int mo, int y, int h, int mi, int s);
    ~DigitalClock();

    // Встановлення поточних дати і часу
    bool setDateTime(int d, int mo, int y, int h, int mi, int s);

    // Встановлення / скасування будильника
    bool setAlarm(int h, int mi);
    void cancelAlarm();

    // Один крок годинника (+1 с)
    void tick();

    // Відображення
    void show() const;

    // Імітація ходу часу на seconds секунд, delayMs - пауза між кроками
    void simulate(int seconds, int delayMs);

    // Введення даних з консолі
    void inputDateTime();
    void inputAlarm();
};
