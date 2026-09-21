// Opdracht 5 - PeterPeterPeterPeter
#include <iostream>
#include <string>
using namespace std;

int main() {
    string naam;
    cout << "Wat is je voornaam? ";
    getline(cin, naam);
    for (int i = 0; i < 4; i++) cout << naam;
    cout << endl;
    return 0;
}
