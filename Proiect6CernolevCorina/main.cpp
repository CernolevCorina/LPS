#include <iostream>
#include <string.h>
#include <conio.h>
#include <cstdlib>
#include <stdlib.h>
#include <iomanip>
#include <stdio.h>
#include "service.cpp"
using namespace std;
// actualizare
void Transfer();
void Afisare();
void Adaugare();
void Modificare();
void Eliminare();

// service
void AranjareAlfabetica();
void AranjareZodiac();
void Completare();

// liste
void Lista1();
void Lista2();
void Lista3();
void Lista4();
void Lista4();
void Lista5();

int main()
{
    int opt;
    do
    {
        system("cls");
        cout << "Proiect 6 elaborat de Cernolev Corina" << endl;
        cout << "Tema: Datele zodiacului" << endl;
        cout << "1. De inscris datele intr-un fisier binar;" << endl;
        cout << "2. De afisat datele;" << endl;
        cout << "3. Adaugarea unei persoane;" << endl;
        cout << "4. Modificarea unei persoane dupa nume;" << endl;
        cout << "5. Aranjare alfabetica a persoanelor;" << endl;
        cout << "6. Aranjarea dupa zodie a persoanelor;" << endl;
        cout << "7. Adaugare numar destin;" << endl;
        cout << "8. Lista persoanelor cu zodia dorita;" << endl;
        cout << "9. Lista persoanelor cu piatra dorita;" << endl;
        cout << "10. Lista persoanelor dupa nume;" << endl;
        cout << "11. Lista persoanelor nascute in anul dorit." << endl;
        cout << "12. Lista persoanelor cu numarul destinului dorit" << endl;
        cout << "0. Stop" << endl;
        cout << "\n\t Alege -> ";
        cin >> opt;
        switch(opt)
        {
            case 1: Transfer(); break;
            case 2: Afisare(); break;
            case 3: Adaugare(); break;
            case 4: Modificare(); break;
            case 5: AranjareAlfabetica(); break;
            case 6: AranjareZodiac(); break;
            case 7: Completare(); break;
            case 8: Lista1(); break;
            case 9: Lista2(); break;
            case 10: Lista3(); break;
            case 11: Lista4(); break;
            case 12: Lista5(); break;
        }
        getch();
    } while(opt);
    return 0;
}
