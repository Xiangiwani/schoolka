// Opdracht 29 - Nachtjes slapen
#include <cmath>
#include <ctime>
#include <iostream>
using namespace std;

int main() {
    int jaar, maand, dag;
    cout << "Jaar: ";
    cin >> jaar;
    cout << "Maand: ";
    cin >> maand;
    cout << "Dag: ";
    cin >> dag;

    tm doel = {};
    doel.tm_year = jaar - 1900;
    doel.tm_mon = maand - 1;
    doel.tm_mday = dag;
    doel.tm_hour = 12;   // midden op de dag: voorkomt problemen met zomertijd
    doel.tm_isdst = -1;

    time_t nu = time(nullptr);
    tm vandaag = *localtime(&nu);
    vandaag.tm_hour = 12;
    vandaag.tm_min = 0;
    vandaag.tm_sec = 0;
    vandaag.tm_isdst = -1;

    time_t t1 = mktime(&doel), t2 = mktime(&vandaag);
    if (t1 == (time_t)-1 || maand < 1 || maand > 12 || dag < 1 || dag > 31) {
        cout << "Ongeldige datum." << endl;
        return 1;
    }
    long verschil = lround(difftime(t1, t2) / 86400.0);
    if (verschil > 0) cout << "+" << verschil << " dagen (in de toekomst)" << endl;
    else if (verschil < 0) cout << verschil << " dagen (" << -verschil << " dagen geleden)" << endl;
    else cout << "Dat is vandaag!" << endl;
    return 0;
}
