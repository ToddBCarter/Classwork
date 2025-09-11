#include <conio.h>
#include <iostream>
using namespace std;

#define KEY_UP    72
#define KEY_LEFT  75
#define KEY_RIGHT 77
#define KEY_DOWN  80

int main()
{
    int c, ex;

    while (1)
    {
        c = _getch();

        if (c && c != 224)
        {
            cout << endl << "Not arrow: " << (char)c << endl;
        }
        else
        {
            switch (ex = _getch())
            {
            case KEY_UP     /* H */:
                cout << endl << "Up" << endl;   //key up
                break;
            case KEY_DOWN   /* K */:
                cout << endl << "Down" << endl;  // key down
                break;
            case KEY_LEFT   /* M */:
                cout << endl << "Left" << endl;  // key left
                break;
            case KEY_RIGHT: /* P */
                cout << endl << "Right" << endl;  // key right
                break;
            default:
                cout << endl << (char)ex << endl;  // not arrow
                break;
            }
        }
    }

    return 0;
}