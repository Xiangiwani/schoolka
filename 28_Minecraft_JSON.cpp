// Opdracht 28 - Minecraft JSON
// Leest gras_blok.json, zet "snow" op true, schuift y met +66 op en maakt z drie keer zo groot.
// Resultaat wordt opgeslagen als sneeuw_blok.json.
// (Zonder externe JSON-bibliotheek: de waarden worden in de tekst aangepast.)
#include <fstream>
#include <iostream>
#include <regex>
#include <sstream>
#include <string>
using namespace std;

// Vervang het getal achter "sleutel": met f(oud)
template <typename F>
bool pasGetalAan(string &tekst, const string &sleutel, F f) {
    regex re("\"" + sleutel + "\"\\s*:\\s*(-?[0-9]+(\\.[0-9]+)?)");
    smatch m;
    if (!regex_search(tekst, m, re)) return false;
    string oud = m[1];
    double nieuw = f(stod(oud));
    ostringstream uit;
    if (oud.find('.') == string::npos) uit << (long long)nieuw;
    else uit << nieuw;
    size_t pos = m.position(1);
    tekst.replace(pos, oud.size(), uit.str());
    return true;
}

int main() {
    ifstream in("gras_blok.json");
    if (!in) {
        cout << "Kan gras_blok.json niet openen. Zet het bestand in dezelfde map als het programma." << endl;
        return 1;
    }
    stringstream buffer;
    buffer << in.rdbuf();
    string tekst = buffer.str();

    // 1. snow -> true
    regex snow("\"snow\"\\s*:\\s*(true|false|True|False)");
    if (regex_search(tekst, snow)) {
        tekst = regex_replace(tekst, snow, "\"snow\": true");
    } else {
        size_t einde = tekst.rfind('}');
        if (einde != string::npos) tekst.insert(einde, ", \"snow\": true ");
    }

    // 2. y + 66 en z * 3
    if (!pasGetalAan(tekst, "y", [](double v) { return v + 66; })) cout << "Waarschuwing: geen \"y\" gevonden." << endl;
    if (!pasGetalAan(tekst, "z", [](double v) { return v * 3; })) cout << "Waarschuwing: geen \"z\" gevonden." << endl;

    ofstream uit("sneeuw_blok.json");
    uit << tekst;
    cout << "Opgeslagen als sneeuw_blok.json:\n" << tekst << endl;
    return 0;
}
