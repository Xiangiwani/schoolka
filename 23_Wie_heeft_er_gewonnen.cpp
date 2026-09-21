// Opdracht 23 - Wie heeft er gewonnen? (hoogste score wint)
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
    int aantal;
    cout << "Hoeveel spelers zijn er? ";
    cin >> aantal;
    cin.ignore(1000, '\n');
    if (aantal < 1) {
        cout << "Er moet minstens 1 speler zijn." << endl;
        return 1;
    }
    vector<string> namen(aantal);
    vector<double> scores(aantal);
    for (int i = 0; i < aantal; i++) {
        cout << "Naam van speler " << i + 1 << ": ";
        getline(cin, namen[i]);
        cout << "Score van " << namen[i] << ": ";
        cin >> scores[i];
        cin.ignore(1000, '\n');
    }
    double hoogste = scores[0];
    for (double s : scores) if (s > hoogste) hoogste = s;
    cout << "\nHoogste score: " << hoogste << endl;
    int winnaars = 0;
    for (int i = 0; i < aantal; i++)
        if (scores[i] == hoogste) winnaars++;
    if (winnaars == 1) {
        for (int i = 0; i < aantal; i++)
            if (scores[i] == hoogste) cout << namen[i] << " heeft gewonnen!" << endl;
    } else {
        cout << "Gelijkspel! Winnaars:";
        for (int i = 0; i < aantal; i++)
            if (scores[i] == hoogste) cout << " " << namen[i];
        cout << endl;
    }
    return 0;
}
