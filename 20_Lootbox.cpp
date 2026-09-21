// Opdracht 20 - Lootbox (Common vaak ... Legendary zeldzaam)
#include <iostream>
#include <map>
#include <random>
#include <string>
#include <vector>
using namespace std;

int main() {
    vector<string> niveaus = {"Common", "Uncommon", "Rare", "Epic", "Legendary"};
    vector<double> kansen = {60, 25, 10, 4, 1};   // in procenten
    mt19937 gen(random_device{}());
    discrete_distribution<int> kies(kansen.begin(), kansen.end());

    int aantal;
    cout << "Hoeveel lootboxen wil je openen? ";
    cin >> aantal;
    map<string, int> teller;
    for (int i = 1; i <= aantal; i++) {
        string loot = niveaus[kies(gen)];
        teller[loot]++;
        cout << "Lootbox " << i << ": " << loot << endl;
    }
    cout << "\nOverzicht:" << endl;
    for (auto &n : niveaus) cout << n << ": " << teller[n] << endl;
    return 0;
}
