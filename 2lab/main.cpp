#include <iostream>
#include "DigitalClock.h"
#include "ConsolIO.h"

#ifdef _WIN32
#include <windows.h>
#endif

using namespace std;

void printMenu()
{
    cout << "\n\t========== МЕНЮ ==========" << endl;
    cout << "\t1 - Встановити дату і час" << endl;
    cout << "\t2 - Встановити будильник" << endl;
    cout << "\t3 - Скасувати будильник" << endl;
    cout << "\t4 - Показати годинник" << endl;
    cout << "\t5 - Імітація ходу часу (N секунд)" << endl;
    cout << "\t0 - Вихід" << endl;
}

int main()
{
#ifdef _WIN32
    SetConsoleOutputCP(65001);      // UTF-8 у консолі Windows
    SetConsoleCP(65001);
#endif

    DigitalClock clock;

    int choice;
    do
    {
        printMenu();
        choice = ConsolIO::GetInt("\tВаш вибір: ", 0, 5);

        switch (choice)
        {
        case 1:
            clock.inputDateTime();
            break;
        case 2:
            clock.inputAlarm();
            break;
        case 3:
            clock.cancelAlarm();
            cout << "\n\tБудильник скасовано." << endl;
            break;
        case 4:
            clock.show();
            break;
        case 5:
        {
            int n = ConsolIO::GetInt("\tСкільки секунд імітувати (1-3600): ", 1, 3600);
            clock.simulate(n, 200);     // пауза 200 мс між кроками
            break;
        }
        }
    } while (choice != 0);

    return 0;
}