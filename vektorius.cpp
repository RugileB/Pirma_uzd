// vektorius.cpp : This file contains the 'main' function. Program execution begins and ends there.
//



#include <iostream>
#include <iomanip>
#include <string>
#include <algorithm>
#include <vector>
#include <numeric>
#include <time.h>
using std::sort;
using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::setprecision;
using std::setw;
using std::left;
using std::vector;


struct studentas {
    string vard, pavard;
    vector <float> nd;
    float egzam{};
    float gal{};
    float med{};
};


void printas(studentas);
double mediana(vector <float>& vec);
int random_sk();

int main() {
    int budas = 0;
    cout << "Pasirinkite ar pazymius norite pildyti automatiskai (0), ar rankiniu budu (1)" << endl;
    cin >> budas;
    if (budas > 0)
    {
        budas = 1;
       }
       cout << "Iveskite studetu skaiciu: " << endl;
        int n;
        cin >> n;
        vector<studentas> grupe;
        studentas tempas;
        grupe.reserve(n);
        float sum = 0, laik, vid, med;
        for (int i = 0; i < n; i++) {
            cout << "Iveskite " << i + 1 << "-o studento varda ir pavarde: "<< endl;
            cin >> tempas.vard >> tempas.pavard;
            sum = 0;
            if (budas == 0)
            {
                int j = 0; // paz sk.
                cout << "Iveskite norima paz. skaiciu studentui" << " " << tempas.vard << " " << tempas.pavard << endl;
                cin >> j;
                    tempas.egzam = random_sk();
                cout << tempas.egzam << endl;
                    for (int x = 0; x < j; x++)
                    {
                   // tempas.nd[x] = random_sk();
                   // cout << tempas.nd[x] << endl;
                        }
                tempas.gal = tempas.gal / j;
                tempas.gal = tempas.gal * 0.4 + 0.6 * tempas.egzam;
                break;
            }
            cout << "Iveskite namu darbu pazymius, baige vesti pazymius padekite '.':"<< endl;
            while (cin >> laik) {
                tempas.nd.push_back(laik);
                sum += laik;
            }
            cin.clear();
            cin.ignore(10000, '\n');
            cout << "Iveskite " << i + 1 << "-o studento egzamino pazymi: "<< endl;
            cin >> tempas.egzam;
            vid = std::accumulate(tempas.nd.begin(), tempas.nd.end(), 0.0) / tempas.nd.size();
            tempas.med = mediana(tempas.nd);
            tempas.gal = 0.4 * vid + 0.6 * tempas.egzam;
            grupe.push_back(tempas);
            tempas.nd.clear();
        }

    studentas studentai[10];
    cout << "\n";
    cout << left
         << setw(10) << "Vardas"
         << setw(10) << "Pavarde"
         << setw(12) << "Egzaminas"
         << setw(20) << "Galutinis (vid.)"
         << setw(15) << "Galutinis (med.)"
         << endl;
    cout << "-----------------------------------------------------------------" << endl;

    for (const auto& kint : grupe) {
        printas(kint);
    }
    
}

double mediana(vector <float>& vec) {
    typedef vector <float>::size_type vecSize;
    vecSize size = vec.size();
    if (size == 0)
        throw std::domain_error("Negalima skaiciuoti medianos tusciam vektoriui");
    sort(vec.begin(), vec.end());  //surusiuojame vektoriu i variacine eilute
    vecSize vid = size / 2;  //vidurinis vektoriaus elementas
    return size % 2 == 0 ? (vec[vid] + vec[vid - 1]) / 2 : vec[vid];
}

int random_sk() //sugeneruoja bet koki skaiciu nuo 1 iki 10
{
    srand(time(NULL));
    return rand() % 10 + 1;
}

/*void auto_paz(studentas::nd[], studentas::egzam[], j;) //funckija automatiskai suveda pazymius ir egzamino pazymi
{
    tempas.egzam = random_sk();
    for (int x = 0; x < j; x++)
    {
        tempas.nd[x] = random_sk();
    }
    tempas.gal = tempas.gal / j;
    tempas.gal = tempas.gal * 0.4 + 0.6 * Eil[i].egzam;

}
*/
void printas(studentas kint) {
    cout << left
        << setw(10) << kint.vard
        << setw(10) << kint.pavard
        << setw(12) << kint.egzam
        << setw(20) << setprecision(3) << kint.gal
        << setw(15) << setprecision(3) << kint.med
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
