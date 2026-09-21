// Opdracht 25 - Quick sort
// Idee: kies een pivot, zet kleinere getallen links en grotere rechts,
// en sorteer daarna links en rechts opnieuw op dezelfde manier (recursie).
#include <iostream>
#include <sstream>
#include <string>
#include <utility>
#include <vector>
using namespace std;

int verdeel(vector<int> &v, int laag, int hoog) {
    int pivot = v[hoog];
    int i = laag - 1;
    for (int j = laag; j < hoog; j++)
        if (v[j] <= pivot) swap(v[++i], v[j]);
    swap(v[i + 1], v[hoog]);
    return i + 1;
}

void quickSort(vector<int> &v, int laag, int hoog) {
    if (laag < hoog) {
        int p = verdeel(v, laag, hoog);
        quickSort(v, laag, p - 1);
        quickSort(v, p + 1, hoog);
    }
}

int main() {
    cout << "Geef getallen, gescheiden door een spatie: ";
    string regel;
    getline(cin, regel);
    istringstream in(regel);
    vector<int> v;
    int x;
    while (in >> x) v.push_back(x);
    if (v.empty()) {
        cout << "Geen getallen ingevoerd." << endl;
        return 1;
    }
    quickSort(v, 0, (int)v.size() - 1);
    cout << "Gesorteerd (quick sort):";
    for (int g : v) cout << " " << g;
    cout << endl;
    return 0;
}
