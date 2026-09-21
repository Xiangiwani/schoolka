// Opdracht 22 - Wat mag je vandaag op het gebied van motorrijden? (Nederland)
#include <ctime>
#include <iostream>
using namespace std;

int main() {
    int dag, maand, jaar;
    char s1, s2;
    cout << "Geef je geboortedatum (dd-mm-jjjj): ";
    cin >> dag >> s1 >> maand >> s2 >> jaar;

    time_t nu = time(nullptr);
    tm *vandaag = localtime(&nu);
    int leeftijd = (vandaag->tm_year + 1900) - jaar;
    if ((vandaag->tm_mon + 1) < maand || ((vandaag->tm_mon + 1) == maand && vandaag->tm_mday < dag)) leeftijd--;

    if (maand < 1 || maand > 12 || dag < 1 || dag > 31 || leeftijd < 0) {
        cout << "Dat is geen geldige geboortedatum." << endl;
        return 1;
    }
    cout << "Je bent " << leeftijd << " jaar oud." << endl;
    if (leeftijd < 16) {
        cout << "Je mag nog niet op een motor of bromfiets rijden." << endl;
    } else {
        cout << "- Rijbewijs AM (brommer/snorfiets, tot 45 km/u): toegestaan (vanaf 16)." << endl;
        if (leeftijd >= 18) {
            cout << "- Rijbewijs A1 (motor tot 125cc / 11 kW): toegestaan (vanaf 18)." << endl;
            cout << "- Rijbewijs A2 (motor tot 35 kW): toegestaan (vanaf 18)." << endl;
        }
        if (leeftijd >= 24)
            cout << "- Rijbewijs A (alle motoren): toegestaan (vanaf 24)." << endl;
        else if (leeftijd >= 20)
            cout << "- Rijbewijs A (alle motoren): toegestaan na 2 jaar rijbewijs A2 (vanaf 20)." << endl;
        if (leeftijd < 18) cout << "Motoren (A1/A2/A) mogen pas vanaf 18 jaar." << endl;
    }
    return 0;
}
