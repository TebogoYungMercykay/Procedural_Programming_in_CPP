#include <iostream>
using namespace std;

struct Carriages
{
    int wagonNumber;
    Carriages* tail;
}; // recursion!

struct DepartureTime
{
    int hour; // between 0 and < 24
    int minu; // between 0 and < 60
};

struct GauTrain
{
    DepartureTime t;
    Carriages front;
};

bool isValidTime(int hours, int minutes)
{
    if (hours < 0 || hours > 24)
    {
        return false;
    }
    if (minutes < 0 || minutes > 60)
    {
        return false;
    }
    return true;
}

void trainManagement(GauTrain &dest, char c) // header line may NOT be modified !
{
    // Body to be implemented by you
    if (c == 'T') // code for Timing
    {
        int hours = 0;
        int minutes = 0;
        cout << "Enter an int-number for hours: ";
        while(cin >> hours && !isValidTime(hours, 1))
        {
            cout << "Enter a valid int-number for hours: ";
        }

        cout << "Enter an int-number for minutes: ";
        while(cin >> minutes && !isValidTime(hours, minutes))
        {
            cout << "Enter a valid int-number for minutes: ";
        }
        dest.t.hour = hours;
        dest.t.minu = minutes;
    }
    else if (c == 'L') // code for Length
    {
        int counter = 0;
        if (dest.front.wagonNumber != 0)
        {
            counter++;
            Carriages* t;
            t = dest.front.tail;
            while (t != NULL)
            {
                t = t->tail;
                counter++;
            }
        }
        cout << "Chained Carriages: " << counter << endl;
    }
    else if (c == 'C') // code for Composition
    {
        cout << "Enter an int-number n, new Carriages: ";
        int n = 0;
        cin >> n;
        Carriages d;
        for (int k = 0; k < n; k++)
        {
            int i;
            cout << "Enter an int-number i, for a wagonID: ";
            cin >> i;
            d = dest.front;
            if (d.wagonNumber != 0)
            {
                Carriages* c;
                c = new Carriages;
                c->tail = NULL;
                c->wagonNumber = i;

                if (d.tail == NULL)
                {
                    d.tail = c;
                    dest.front.tail = c;
                }
                else
                {
                    Carriages* t;
                    t = d.tail;
                    while (t->tail != NULL)
                    {
                        t = t->tail;
                    }
                    t->tail = c;
                }
            }
            else
            {
                d.wagonNumber = i;
                dest.front = d;
            }
        }
    }
    return;
}

int main()
{
    GauTrain toHatfield; // values are not yet initialized!
    GauTrain toRosebank; // values are not yet initialized!

    char opCode;
    char destination;

    cin >> opCode;
    cin >> destination;

    if (destination == 'H') { trainManagement(toHatfield, opCode); }
    if (destination == 'R') { trainManagement(toRosebank, opCode); }

    return 0;
}