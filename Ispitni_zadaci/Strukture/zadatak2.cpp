/*Redovi dvodimenzionalnog niza predstavljaju razlièite firme a u kolone razlièita vozila u tim firmama. (radi jednostavnosti rješenja podrazumijevati da 
svaka firma ima isti broj vozila). Omoguæiti korisniku unos svih podataka za sva vozila.*/
#include <iostream>
using namespace std;

struct vozilo
{
    char* markaVozila;
    char* brojSasije;   
    char* tipVozila; 
    int* kubnihCM;

    vozilo() 
    {
        markaVozila = new char[15];
        brojSasije = new char[10];
        tipVozila = new char;
        kubnihCM = new int;
    }
    ~vozilo()
    {
        delete markaVozila;
        markaVozila = nullptr;

        delete  brojSasije;
        brojSasije = nullptr;

        delete tipVozila;
        tipVozila = nullptr;

        delete  kubnihCM;
        kubnihCM = nullptr;
    }
};

void unos(vozilo**, int , int);
void ispis(vozilo** , int , int );
int najvecakubikaza(vozilo**, int, int);
void prosjecnakubikaza(vozilo**, int, int);

void dealokacija(vozilo**& , int );

int main()
{
    int red;
    int kol;

    cout << "Unesite koliko redova zelite: ";
    cin>> red;
    cout << "Unesite koliko kolona zelite: ";
    cin >> kol;

    vozilo** niz = new vozilo * [red];
    for (int i = 0; i < red; i++)
    {
        *(niz + i) = new vozilo[kol];
    }
    unos(niz, red, kol);
    cout << endl;
    ispis(niz, red, kol);
    cout << endl;

    cout << "Firma sa najvecom  prosjecnom kubikazom se nalazi na indeksu: " << najvecakubikaza(niz, red, kol) << endl;

    int indeks = najvecakubikaza(niz, red, kol);
    cout << "Uneseni podaci firme sa najvecom kubikazom su: ";
    for (int j = 0; j < kol; j++)
    {
        cout << "Marka vozila je: " << (*(niz + indeks) + j)->markaVozila << "\t";
        cout << "Broj sasije vozila je: " << (*(niz + indeks) + j)->brojSasije << "\t";
        cout << "Tip vozila je: " << *(*(niz + indeks) + j)->tipVozila << "\t";
        cout << "Kubna potrosnja vozila je: " << *(*(niz + indeks) + j)->kubnihCM << endl;
    }
    dealokacija(niz, red);
    
    prosjecnakubikaza(niz, red, kol);

    cin.get();
    return 0;
}
void unos(vozilo** niz, int red, int kol)
{
    cout << "Unesite " << red * kol << " elementa niza: " << endl;
    for (int i = 0; i < red; i++)
    {
        for (int j = 0; j < kol; j++)
        {
            cin.ignore();
            cout << "Unesite marku vozila : " << endl;
            cin.getline((*(niz + i) + j)->markaVozila, 15);
            cout << "Unesite broj sasije vozila: " << endl;
            cin.getline((*(niz + i) + j)->brojSasije, 10);

            do
            {
                cout << "Unesite tip vozila(A,B,C): " << endl;
                cin>>*(*(niz + i) + j)->tipVozila;
               
            } while (*(*(niz + i) + j)->tipVozila != 'A' && *(*(niz + i) + j)->tipVozila != 'B' && *(*(niz + i) + j)->tipVozila != 'C');
            cout << "Unesite broj kubne potrosnje vozila: " << endl;
            cin >> *(*(niz + i) + j)->kubnihCM;
        }
    }
}
void ispis(vozilo** niz, int red, int kol)
{
    cout << "Unjeli ste: " << red * kol << " elemenata ,a oni su: " << endl;
    for (int i = 0; i < red; i++)
    {
        for (int j = 0; j < kol; j++)
        {
            cout << "Marka vozila je: " << (*(niz + i) + j)->markaVozila << " | " << endl;
            cout << "Broj sasije vozila je: " << (*(niz + i) + j)->brojSasije << " | " << endl;
            cout << "Tip vozila je: " << (*(niz + i) + j)->tipVozila << " | " << endl;
            cout << "Kubikaza vozila je: " << (*(niz + i) + j)->kubnihCM << " | " << endl;
        }
        cout << endl;
    }
}
void dealokacija(vozilo**& niz, int red)
{
    for (int i = 0; i < red; i++)
    {
        delete[] * (niz + i);
    }
    delete[]niz;
    niz = nullptr;
}
int najvecakubikaza(vozilo** niz, int red, int kol)
{
    float* kubikaza = new float[red] {};
    for (int i = 0; i < red; i++)
    {
        for (int j = 0; j < kol; j++)
        {
            *(kubikaza + i) += *(*(niz + i) + j)->kubnihCM;
        }
        *(kubikaza + i) /= kol;
    }
    int maxk=0;
    for (int i = 0; i < red; i++)
    {
        if (*(kubikaza + i) > *(kubikaza + maxk))
        {
            maxk = i;
        }
    }
    delete[]kubikaza;
    kubikaza = nullptr;

    return maxk;
}
void prosjecnakubikaza(vozilo** niz, int red, int kol)
{
    float aprosjek = 0.0f;
    float bprosjek = 0.0f;
    float cprosjek = 0.0f;
    int A = 0, B = 0, C = 0;

    for (int i = 0; i < red; i++)
    {
        for (int j = 0; j < kol; j++)
        {
            if (*(*(niz + i) + j)->tipVozila == 'A') {
                aprosjek += *(*(niz + i) + j)->kubnihCM;
                A++;
            }
            else if (*(*(niz + i) + j)->tipVozila == 'B') {
                bprosjek += *(*(niz + i) + j)->kubnihCM;
                B++;
            }
            else if (*(*(niz + i) + j)->tipVozila == 'C') {
                cprosjek += *(*(niz + i) + j)->kubnihCM;
                C++;
            }
        }
        
    }
    if (A != 0) {
        aprosjek /= A;
    }
    if (B != 0) {
        bprosjek /= B;
    }
    if (C != 0) {
        cprosjek /= C;
    }

    cout << "Prosjecna kubikaza vozila A je: " << aprosjek << endl;
    cout << "Prosjecna kubikaza vozila B je: " << bprosjek << endl;
    cout << "Prosjecna kubikaza vozila C je: " << cprosjek << endl;
}