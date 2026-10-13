#pragma once
#include "TimeController.h"
#include "DateController.h"

/*------------------------------------------------
ЕКРАН: відображає інформацію годинника в консолі
------------------------------------------------*/
class Screen
{
public:
    Screen();
    ~Screen();

    // Повне табло годинника
    void show(const TimeController& t, const DateController& d) const;

    // Компактний рядок (для імітації ходу часу)
    void showLine(const TimeController& t, const DateController& d) const;
};
