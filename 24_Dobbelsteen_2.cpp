// Opdracht 24 - Dobbelsteen nr 2 ('AdX' notatie, bijv. 3d6 of 2d20)
#include <iostream>
#include <random>
#include <regex>
#include <string>
using namespace std;

int main() {
    regex patroon("^\\s*([0-9]+)[dD]([0-9]+)\\s*$");
    smatch m;
    string invoer;
    int A = 0, X = 0;
    while (true) {
        cout << "Welke dobbelstenen moeten er gegooid worden? (bijv. 3d6): ";
        getline(cin, invoer);
        if (regex_match(invoer, m, patroon)) {
            A = stoi(m[1]);
            X = stoi(m[2]);
            if (A >= 1 && A <= 1000 && X >= 2 && X <= 1000000) break;
        }
        cout << "Ongeldig formaat! Gebruik AdX, waarbij A het aantal dobbelstenen is en X het aantal zijden (bijv. 2d10)." << endl;
    }
    mt19937 gen(random_device{}());
    uniform_int_distribution<int> dobbel(1, X);
    long long som = 0;
    for (int i = 1; i <= A; i++) {
        int worp = dobbel(gen);
        som += worp;
        cout << "Dobbelsteen " << i << " (d" << X << "): " << worp << endl;
    }
    cout << "Som: " << som << endl;
    return 0;
}
