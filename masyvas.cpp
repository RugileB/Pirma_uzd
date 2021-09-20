// masyvas.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <iomanip>
#include <string>
using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::setprecision;
using std::setw;
using std::left;


struct studentas {
    string vard, pavard;
    float nd[10]{};
    float egzam{};
    float gal{};
};


void pild(studentas& kint);
void printas(studentas& kin);


int main()
{
    studentas studentai[10];
    for (int i = 0; i < 2; i++)
        pild(studentai[i]);
    cout << "\n";
    cout << left
        << setw(10) << "Vardas"
        << setw(10) << "Pavarde"
        << setw(10) << "Egzaminas"
        << setw(10) << "Galutinis (vid.)"
        << endl;
    cout << "-----------------------------------------------------------------" << endl;
    for (int i = 0; i < 2; i++)
        printas(studentai[i]);
}

void pild(studentas& kint) {
    int n;
    cout << "Iveskite studento varda ir pavarde: "; cin >> kint.vard >> kint.pavard;
    cout << "Kiek namu darbu bus? (1-10)"; cin >> n;
    cout << "Iveskite pazymius (1-10):"<<endl;
    float sum = 0, vid = 0;
    for (int i = 0; i < n; i++) {
        cin >> kint.nd[i];
        if ((kint.nd[i] < 1) || (kint.nd[i] > 10)) {
            cout << "Neteisingas pazymys, iveskite dar karta";
            exit(EXIT_SUCCESS);
        }
        sum += kint.nd[i];
 
    }
    vid = sum / n;
    cout << "Iveskite egzamino pazymi:"; cin >> kint.egzam;
    kint.gal = vid * 0.4 + kint.egzam * 0.6;
}

void printas(studentas& kin) {
    cout << left
        << setw(10) << kin.vard
        << setw(10) << kin.pavard
        << setw(10) << kin.egzam
        << setw(10) << setprecision(3) << kin.gal
        << endl;
    cout << "\n";
      }


// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
