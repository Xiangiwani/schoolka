// Opdracht 16 - Vermenigvuldigen met een functie
#include <iostream>
using namespace std;

// De functie zelf toont niets op het scherm
double vermenigvuldig(double a, double b) {
    return a * b;
}

int main() {
    double x, y;
    cout << "Geef 2 getallen: ";
    cin >> x >> y;
    cout << x << " x " << y << " = " << vermenigvuldig(x, y) << endl;
    return 0;
}
