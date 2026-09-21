// Opdracht 18 - Wie mag er beginnen?
#include <iostream>
#include <random>
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
    for (int i = 0; i < aantal; i++) {
        cout << "Naam van speler " << i + 1 << ": ";
        getline(cin, namen[i]);
    }
    mt19937 gen(random_device{}());
    uniform_int_distribution<int> kies(0, aantal - 1);
    cout << namen[kies(gen)] << " mag beginnen!" << endl;
    return 0;
}
