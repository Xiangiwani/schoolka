// Opdracht 17 - Palindroom
#include <algorithm>
#include <cctype>
#include <iostream>
#include <string>
using namespace std;

int main() {
    string woord, schoon;
    cout << "Geef een woord: ";
    getline(cin, woord);
    for (char c : woord)
        if (isalnum((unsigned char)c)) schoon += tolower((unsigned char)c);
    string omgekeerd(schoon.rbegin(), schoon.rend());
    if (schoon == omgekeerd)
        cout << "\"" << woord << "\" is een palindroom." << endl;
    else
        cout << "\"" << woord << "\" is geen palindroom." << endl;
    return 0;
}
