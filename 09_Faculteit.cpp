// Opdracht 9 - Faculteit
#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Van welk getal wil je de faculteit? ";
    cin >> n;
    if (n < 0) {
        cout << "Een faculteit bestaat niet voor negatieve getallen." << endl;
        return 1;
    }
    if (n > 20) {
        cout << "Dat getal is te groot (maximaal 20)." << endl;
        return 1;
    }
    unsigned long long uitkomst = 1;
    for (int i = 2; i <= n; i++) uitkomst *= i;
    cout << n << "! = " << uitkomst << endl;
    return 0;
}
