// Opdracht 12 - PeterPeterPeterPeter 2
#include <iostream>
#include <string>
using namespace std;

int main() {
    string naam;
    int aantal;
    cout << "Wat is je voornaam? ";
    getline(cin, naam);
    cout << "Hoe vaak moet de naam achter elkaar? ";
    cin >> aantal;
    for (int i = 0; i < aantal; i++) cout << naam;
    cout << endl;
    return 0;
}
