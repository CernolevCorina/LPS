#include <iostream>
#include <cstdlib>
#include <conio.h>
using namespace std;
// actualizare
void Transfer();
void Afisare();
void Adaugare();
void Modificare();
void Eliminare();

// service
void AranjareAlfabitica();
void AranjareCategorii();
void Completare();

// liste
void Lista1();
void Lista2();
void Lista3();
void Lista4();
void Lista5();
void Lista6();
void Lista7();
void Lista8();

int main()
{
    int opt;
    do
    {
        system("cls");
        cout << "Proiect 6 elaborat de Cernolev Corina" << endl;
        cout << "Tema: Datele zodiacului" << endl;
        cout << "1. Transfer" << endl;
        cout << "2. Afisare" << endl;
        cout << "3. Adaugare" << endl;
        cout << "4. Modificare" << endl;
        cout << "5. Eliminare" << endl;
        cout << "6. Aranjare alfabetica" << endl;
        cout << "7. Aranjare Disciplina" << endl;
        cout << "8. Completare categorii" << endl;
        cout << "9. Lista 1" << endl;
        cout << "10. Lista 2" << endl;
        cout << "11. Lista 3" << endl;
        cout << "12. Lista 4" << endl;
        cout << "13. Lista 5" << endl;
        cout << "14. Lista 6" << endl;
        cout << "15. Lista 7" << endl;
        cout << "16. Lista 8" << endl;
        cout << "0. Stop" << endl;
        cout << "\n\t Alege -> ";
        cin >> opt;
        switch(opt)
        {
            case 1: Transfer(); break;
            case 2: Afisare(); break;
            case 3: Adaugare(); break;
            case 4: Modificare(); break;
            /*case 5: Eliminare(); break;
            case 6: AranjareAlfabitica(); break;
            case 7: AranjareCategorii(); break;
            case 8: Completare(); break;
            case 9: Lista1(); break;
            case 10: Lista2(); break;
            case 11: Lista3(); break;
            case 12: Lista4(); break;
            case 13: Lista5(); break;
            case 14: Lista6(); break;
            case 15: Lista7(); break;
            case 16: Lista8(); break;*/
        }
        getch();
    } while(opt);
    return 0;
}
