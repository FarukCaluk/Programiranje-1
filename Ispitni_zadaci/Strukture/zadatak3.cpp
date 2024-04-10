/*Redovi matrice predstavljaju firme, kolone automobile. Izraèunati u kojoj je firmi najveæa potrošnja goriva po km.
Naæi i ispisati prosjek potrošnje goriva po km u vozilima tipa C u cijeloj matrici.*/
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

struct vozilo
{
    char* markaVozila;
    char* nazivVozila;
    char* tipVozila; // omoguæiti unos samo 'A', 'B','C'
    float* potrosnjagoriva;

    vozilo() {
        markaVozila = new char[15];
        nazivVozila = new char[10];
        tipVozila = new char;
        potrosnjagoriva = new float;
    }

    ~vozilo() {
        delete[]markaVozila;
        markaVozila = nullptr;

        delete[]nazivVozila;
        nazivVozila = nullptr;

        delete tipVozila;
        tipVozila = nullptr;

        delete potrosnjagoriva;
        potrosnjagoriva = nullptr;
    }
};

void unos(vozilo**, int, int);
void ispis(vozilo**, int, int);
void najvecipotrosac(vozilo**, int, int);
void dealokacija(vozilo**&, int );

int main()
{
    srand(time(0));
    int red, kol;

    cout << "Unesite koliko redova zelite: ";
    cin >> red;
    cout << "--------------------------------" << endl;
    cout << "Unesite koliko kolona zelite: ";
    cin >> kol;
    cout << "--------------------------------" << endl;

    vozilo** niz = new vozilo * [red];
    for (int i = 0; i < red; i++) 
    {
        *(niz + i) = new vozilo[kol];
    }
    unos(niz, red, kol);
    ispis(niz, red, kol);
    dealokacija(niz, red);
    najvecipotrosac(niz, red, kol);

    cin.get();
   
    return 0;
}
void unos(vozilo** niz, int red, int kol)
{
    cout << "Unnjeli ste: " << red * kol << " elemenata u niz: " << endl;
    cout << "--------------------------------" << endl;

    for (int i = 0; i < red; i++)
    {
        for (int j = 0; j < kol; j++)
        {
            cin.ignore();
            cout << "Unesite marku vozila: " << endl;
            cin.getline((*(niz + i) + j)->markaVozila, 15);
            cout << "Unesite naziv vozila: " << endl;
            cin.getline((*(niz + i) + j)->nazivVozila, 10);

            do 
            {
                cout << "Unesite tip vozila(A,B,C): "<<endl;
                cin >> *(*(niz + i) + j)->tipVozila;
            } while (*(*(niz + i) + j)->tipVozila != 'A' && *(*(niz + i) + j)->tipVozila != 'B' && *(*(niz + i) + j)->tipVozila != 'C');
            
            *(*(niz + i) + j)->potrosnjagoriva = rand() % 10 + 5;
        }

    }
}
void ispis(vozilo** niz, int red, int kol)
{
    cout << endl;
    cout << "Unjeli ste: " << red * kol << " elemenata a oni su: " << endl;
    for (int i = 0; i < red; i++)
    {
        for (int j = 0; j < kol; j++)
        {
            cout << "Marka vozila je: " << (*(niz + i) + j)->markaVozila << endl;
            cout << "Naziv vozila je: " << (*(niz + i) + j)->nazivVozila<<endl;
            cout << "Tip vozila je: " << *(*(niz + i) + j)->tipVozila<<endl;
            cout << "Potrosnja goriva kod vozila je: " << *(*(niz + i) + j)->potrosnjagoriva<<endl;
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
void najvecipotrosac(vozilo** niz, int red, int kol)
{
    int* potrosnjaFirme = new int[red] {};

    for (int i = 0; i < red; i++)
    {
        for (int j = 0; j < kol; j++)
        {
            *(potrosnjaFirme + i) += *(*(niz + i) + j)->potrosnjagoriva;
        }
    }
    int indeks = 0;
    for (int i = 0; i < red; i++)
    {
        if (*(potrosnjaFirme + i) > *(potrosnjaFirme + indeks)) {
            indeks + i;
        }
    }
    cout << endl;
    cout << "Firma sa najvecom potrosnjom nalazi se na indeksu: " << indeks << " I ima sljedece podatke: " << endl;
    for (int j = 0; j < kol; j++)
    {
        cout << "Marka vozila je: " << (*(niz + indeks) + j)->markaVozila << endl;
        cout << "Naziv vozila je: " << (*(niz + indeks) + j)->nazivVozila << endl;
        cout << "Tip vozila je: " << *(*(niz + indeks) + j)->tipVozila << endl;
        cout << "Potrosnja goriva kod vozila je: " << *(*(niz + indeks) + j)->potrosnjagoriva << endl;
    }
    cout << endl;

    delete[]potrosnjaFirme;
}