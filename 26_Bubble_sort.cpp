// Opdracht 26 - Bubble sort
// Idee: vergelijk steeds twee buren en wissel ze als ze in de verkeerde volgorde staan.
// Herhaal dit tot er niets meer gewisseld hoeft te worden.
#include <iostream>
#include <sstream>
#include <string>
#include <utility>
#include <vector>
using namespace std;

void bubbleSort(vector<int> &v) {
    bool gewisseld = true;
    for (size_t pas = 0; pas + 1 < v.size() && gewisseld; pas++) {
        gewisseld = false;
        for (size_t i = 0; i + 1 < v.size() - pas; i++) {
            if (v[i] > v[i + 1]) {
                swap(v[i], v[i + 1]);
                gewisseld = true;
            }
        }
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
    bubbleSort(v);
    cout << "Gesorteerd (bubble sort):";
    for (int g : v) cout << " " << g;
    cout << endl;
    return 0;
}
