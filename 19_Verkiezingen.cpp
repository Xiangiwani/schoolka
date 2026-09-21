// Opdracht 19 - Verkiezingen (hoofdletters maken geen verschil)
#include <algorithm>
#include <cctype>
#include <iostream>
#include <map>
#include <string>
#include <vector>
using namespace std;

string klein(string s) {
    for (char &c : s) c = tolower((unsigned char)c);
    return s;
}

int main() {
    map<string, int> stemmen;          // kleine letters -> aantal
    map<string, string> weergave;      // kleine letters -> eerste schrijfwijze
    string invoer;
    while (true) {
        cout << "Naam (of UITSLAG! om te stoppen): ";
        getline(cin, invoer);
        string k = klein(invoer);
        if (k == "uitslag!") break;
        if (k.empty()) continue;
        stemmen[k]++;
        if (!weergave.count(k)) weergave[k] = invoer;
    }
    if (stemmen.empty()) {
        cout << "Er zijn geen namen ingevoerd." << endl;
        return 0;
    }
    int max = 0;
    for (auto &p : stemmen) max = std::max(max, p.second);
    vector<string> winnaars;
    for (auto &p : stemmen)
        if (p.second == max) winnaars.push_back(weergave[p.first]);
    if (winnaars.size() == 1)
        cout << "De winnaar is " << winnaars[0] << " met " << max << " stem(men)!" << endl;
    else {
        cout << "Gelijkspel tussen:";
        for (auto &w : winnaars) cout << " " << w;
        cout << " (elk " << max << " stem(men))" << endl;
    }
    return 0;
}
