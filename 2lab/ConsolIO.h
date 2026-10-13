#pragma once
#include <iostream>
#include <string>
#include <limits>

/*------------------------------------------------
Статичний клас для безпечного введення з консолі
------------------------------------------------*/
class ConsolIO
{
public:
    // Зчитує ціле число з діапазону [min, max].
    // Якщо введено щось інше - просить повторити.
    static int GetInt(const std::string& prompt, int min, int max)
    {
        int value;
        while (true)
        {
            std::cout << prompt;
            if (std::cin >> value && value >= min && value <= max)
            {
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                return value;
            }
            std::cout << "\n\tНЕКОРЕКТНИЙ ВВІД! Очікується ціле число від "
                << min << " до " << max << ". Повторіть.\n";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
    }
};