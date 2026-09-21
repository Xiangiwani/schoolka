// Opdracht 21 - Rekenmachine
#include <iostream>
using namespace std;

int main() {
    double resultaat, getal;
    cout << "Geef een getal: ";
    cin >> resultaat;
    while (true) {
        char actie;
        cout << "Actie (+, -, *, /, =): ";
        cin >> actie;
        if (actie == '=') {
            cout << "Uitkomst: " << resultaat << endl;
            break;
        }
        if (actie != '+' && actie != '-' && actie != '*' && actie != '/') {
            cout << "Onbekende actie, probeer opnieuw." << endl;
            continue;
        }
        cout << "Geef een nieuw getal: ";
        cin >> getal;
        if (actie == '+') resultaat += getal;
        else if (actie == '-') resultaat -= getal;
        else if (actie == '*') resultaat *= getal;
        else {
            if (getal == 0) cout << "Delen door nul kan niet, getal genegeerd." << endl;
            else resultaat /= getal;
        }
    }
    return 0;
}
