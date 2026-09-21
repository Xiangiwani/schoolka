// Opdracht 7 - Woorden draaien
#include <algorithm>
#include <iostream>
#include <string>
using namespace std;

int main() {
    string woord;
    cout << "Geef een woord: ";
    getline(cin, woord);
    reverse(woord.begin(), woord.end());
    cout << "Omgedraaid: " << woord << endl;
    return 0;
}
