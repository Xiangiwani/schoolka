// Opdracht 14 - Fibonacci (eerste 15 getallen)
#include <iostream>
using namespace std;

int main() {
    long long a = 0, b = 1;
    for (int i = 1; i <= 15; i++) {
        cout << a << " ";
        long long volgende = a + b;
        a = b;
        b = volgende;
    }
    cout << endl;
    return 0;
}
