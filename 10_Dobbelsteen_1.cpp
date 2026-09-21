// Opdracht 10 - Dobbelsteen nr 1
#include <iostream>
#include <random>
using namespace std;

int main() {
    int aantal;
    cout << "Hoeveel dobbelstenen wil je gooien? ";
    cin >> aantal;
    if (aantal < 1) {
        cout << "Je moet minstens 1 dobbelsteen gooien." << endl;
        return 1;
    }
    mt19937 gen(random_device{}());
    uniform_int_distribution<int> dobbel(1, 6);
    int som = 0;
    cout << "De dobbelstenen worden gegooid..." << endl;
    for (int i = 1; i <= aantal; i++) {
        int worp = dobbel(gen);
        som += worp;
        cout << "Dobbelsteen " << i << ": " << worp << endl;
    }
    cout << "Totaal aantal ogen: " << som << endl;
    return 0;
}
