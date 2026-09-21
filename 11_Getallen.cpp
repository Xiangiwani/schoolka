// Opdracht 11 - Getallen sorteren van groot naar klein
#include <algorithm>
#include <functional>
#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<double> getallen(5);
    cout << "Geef 5 getallen, gescheiden door een spatie: ";
    for (double &g : getallen) cin >> g;
    sort(getallen.begin(), getallen.end(), greater<double>());
    cout << "Van groot naar klein:";
    for (double g : getallen) cout << " " << g;
    cout << endl;
    return 0;
}
