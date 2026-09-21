// Opdracht 8 - Delen (3 getallen door elkaar delen, 4 decimalen)
#include <iomanip>
#include <iostream>
using namespace std;

int main() {
    double a, b, c;
    cout << "Geef 3 getallen (gescheiden door een spatie): ";
    cin >> a >> b >> c;
    if (b == 0 || c == 0) {
        cout << "Delen door nul kan niet!" << endl;
        return 1;
    }
    cout << fixed << setprecision(4);
    cout << a << " / " << b << " / " << c << " = " << a / b / c << endl;
    return 0;
}
