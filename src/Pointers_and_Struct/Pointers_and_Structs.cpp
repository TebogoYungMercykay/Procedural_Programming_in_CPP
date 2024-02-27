#include <iostream>
using namespace std;
// STRUCTS AND POINTERS.

// Carriages Structure:
struct Carriages {
    int wagonNumber;
    Carriages* tail; // Works like the next ptr!!
};
// Departure Time Structure:
struct departureTime {
    int hour; // 0 <= hour <= 23
    int minu; // 0 <= min <= 59
};
// Gautrain Structure:
struct Gautrain {
    departureTime t;
    Carriages front;
};
// Train Management:
void trainManagement(Gautrain& dest, char c) {
    switch (c) {
        case 'T': { // Code for Timing
            cout << "Enter the Departure Hour: ";
            for (; !(cin >> dest.t.hour) || dest.t.hour < 0 || dest.t.hour >= 24; ) {
                cout << "Enter valid Departure Hour: ";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }
            cout << "Enter the Departure minutes: ";
            for (; !(cin >> dest.t.minu) || dest.t.minu < 0 || dest.t.minu >= 60; ) {
                cout << "Enter valid Departure minutes: ";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }
            break;
        }
        case 'L': { // Code for Length
            if (dest.front.wagonNumber != 0) {
                int counter = 1;
                Carriages* temp = dest.front.tail;
                while (temp != NULL) {
                    counter += 1;
                    temp = temp->tail;
                }
                cout << "There are " << counter << " Chained Carriages";
            } else {
                cout << "There are no Chained Carriages";
            }
            break;
        }
        case 'C': { // Code for Composition
            cout << "How many Carriages do you have: ";
            int size = 0;
            cin >> size;
            for (int k = 0; k < size; k++) {
                int wagonID;
                cout << "Enter the Wagon ID: ";
                cin >> wagonID;
                // Creating a Carriage dynamically
                Carriages* carriage = new Carriages;
                carriage->wagonNumber = wagonID;
                carriage->tail = NULL;
                // Storing the Carriage:
                if (dest.front.wagonNumber != 0) { // last (tail)
                    if (dest.front.tail == NULL) {
                        dest.front.tail = carriage;
                    } else {
                        Carriages* temp = dest.front.tail;
                        while (temp->tail != NULL) {
                            temp = temp->tail;
                        }
                        temp->tail = carriage;
                    }
                } else { // When there are no carriages so far.
                    dest.front.wagonNumber = wagonID;
                }
            }
            break;
        }
        default: {
            cout << "Incorrect opCode character Entered!!" << endl;
            break;
        }
    }
}
// Testing Main
int main() {
    // Variables
    Gautrain toHatfield;
    Gautrain toRosebank;
    // User Inputs
    char opCode, destination;
    cout << "Please enter the opCode: ";
    cin >> opCode;
    cout << "Please enter the destination: ";
    cin >> destination;
    // Conditions
    switch (destination) {
        case 'H':
            trainManagement(toHatfield, opCode);
            break;
        case 'R':
            trainManagement(toRosebank, opCode);
            break;
        default:
            cout << "Invalid Destination Entered!!!" << endl;
            break;
    }
    return 0;
}