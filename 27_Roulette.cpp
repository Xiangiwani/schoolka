// Opdracht 27 - Roulette
#include <iostream>
#include <random>
#include <string>
using namespace std;

int main() {
    int chips = 10;
    mt19937 gen(random_device{}());
    uniform_int_distribution<int> wiel(0, 36);
    char doorgaan = 'j';

    while (chips > 0 && (doorgaan == 'j' || doorgaan == 'J')) {
        cout << "\nJe hebt " << chips << " chips." << endl;
        int inzet, gekozen;
        do {
            cout << "Hoeveel chips zet je in (1-" << chips << ")? ";
            cin >> inzet;
        } while (inzet < 1 || inzet > chips);
        do {
            cout << "Op welk getal zet je in (0-36)? ";
            cin >> gekozen;
        } while (gekozen < 0 || gekozen > 36);

        int uitslag = wiel(gen);
        cout << "Het wiel draait... het getal is " << uitslag << "!" << endl;
        if (uitslag == gekozen) {
            chips += 35 * inzet;
            cout << "GEWONNEN! Je wint " << 35 * inzet << " chips." << endl;
        } else {
            chips -= inzet;
            cout << "Helaas, je verliest " << inzet << " chips." << endl;
        }
        if (chips <= 0) {
            cout << "Je hebt geen chips meer. Game over!" << endl;
            break;
        }
        cout << "Doorgaan? (j/n): ";
        cin >> doorgaan;
    }
    cout << "Je eindigt met " << chips << " chips. Bedankt voor het spelen!" << endl;
    return 0;
}
