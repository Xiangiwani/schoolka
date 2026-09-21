// Opdracht 13 - Rijbewijs nr 1
#include <iostream>
using namespace std;

int main() {
    int leeftijd;
    cout << "Hoe oud ben je? ";
    cin >> leeftijd;
    if (leeftijd >= 18)
        cout << "Je mag zelfstandig autorijden." << endl;
    else if (leeftijd >= 17)
        cout << "Je mag alleen autorijden met begeleid rijden (met een begeleider)." << endl;
    else
        cout << "Je mag nog niet autorijden." << endl;
    return 0;
}
