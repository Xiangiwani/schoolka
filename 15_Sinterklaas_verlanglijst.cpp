// Opdracht 15 - Sinterklaas verlanglijst
#include <algorithm>
#include <cctype>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

string klein(string s) {
    for (char &c : s) c = tolower((unsigned char)c);
    return s;
}

int main() {
    vector<string> lijst;
    string item;
    while (true) {
        cout << "Wat wil je van Sinterklaas? (typ KLAAR! om te stoppen): ";
        getline(cin, item);
        if (item == "KLAAR!") break;
        if (!item.empty()) lijst.push_back(item);
    }
    sort(lijst.begin(), lijst.end(), [](const string &a, const string &b) { return klein(a) < klein(b); });
    cout << "\nJouw verlanglijst (alfabetisch):" << endl;
    for (const string &s : lijst) cout << "- " << s << endl;
    return 0;
}
