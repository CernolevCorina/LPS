#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <conio.h>
#include <string.h>
#include <stdio.h>
#include <cstring>
#define LMAX 121

int NumarCuvinte(char sir[]);
int CuvinteLitere(char sir[], char litera1, char litera2);
int Majuscule(char sir[]);
int CuvinteMajuscule(char sir[]);
int NumarCuvinte();
int CuvinteLitere(char litera1, char litera2);
int CuvinteMajuscule();
int TransferCuvinteLitera(char litera1, char litera2);
int EliminaCuvinteLitera();

using namespace std;
int main()
{
    int optiune, nr;
    char fraza[LMAX] = "Dumitru este prieten cu Mihai, Mihai prieteneste cu Corina, rezulta...";
    do
    {
        system("cls");
        cout << "Proiect nr. 5, elaborat de Cernolev Corina IS11Z\n";
        cout << "Tema: Siruri de caractere. Fisiere text";
        cout << "\n 1. Numarul de cuvinte dintr-o fraza";
        cout << "\n 2. Cuvinte ce contin cel putin 2 litere indicate";
        cout << "\n 3. Cuvintele cu litere majuscule";
        cout << "\n 4. Numarul de cuvinte dintr-un fisier";
        cout << "\n 5. Cuvintele din fisier ce contin cel putin 2 litere indicate";
        cout << "\n 6. Cuvintele cu litere majuscule din fisier";
        cout << "\n 7. Transfer cuvinte ce contin literele indicate in alt fisier";
        cout << "\n 8. Eliminare cuvinte din fisier";
        cout << "\n 9. Interesant";
        cout << "\n 0. Stop";
        cout << "\n\n\t Alege (de la 0 la 9) -> ";
        cin >> optiune;
        switch (optiune)
        {
        case 1:
            cout << "Fraza initiala:\n";
            puts(fraza);
            if ((nr = NumarCuvinte(fraza)) > 0)
                cout << "In total " << nr << " cuvinte\n";
            else
                cout << "Nu-s cuvinte!\n";
            break;
        case 2:
            cout << "Fraza initiala:\n";
            puts(fraza);
            char litera1, litera2;
            cout << "Dati literele cautate ";
            cin >> litera1 >> litera2;
            if ((nr = CuvinteLitere(fraza, litera1, litera2)) > 0)
                cout << "\n In total " << nr << " cuvinte care contin literele indicate\n";
            else
                cout << "\n Nu-s cuvinte care contin literele indicate \n";
            break;
        case 3:
            cout << "Fraza initiala:\n";
            puts(fraza);
            if ((nr = CuvinteMajuscule(fraza)) > 0)
                cout << "\nIn total " << nr << " cuvinte cu litere majuscule\n";
            else
                cout << "Nu-s cuvinte cu litere majuscule!\n";
            break;
        case 4:
            cout << "\nIn fisier sunt: " << NumarCuvinte() << " cuvinte.";
            break;
        case 5:
            cout << "Dati literele cautate ";
            cin >> litera1 >> litera2;
            if ((nr = CuvinteLitere(litera1, litera2)) > 0)
                cout << "\n In total " << nr << " cuvinte care contin literele indicate\n";
            else
                cout << "\n Nu-s cuvinte care contin literele indicate \n";
            break;
        case 6:
            if ((nr = CuvinteMajuscule()) > 0)
                cout << "\nIn total " << nr << " cuvinte cu litere majuscule\n";
            else
                cout << "\nNu-s cuvinte cu litere majuscule!\n";
            break;
        case 7:
            cout << "Dati literele cautate ";
            cin >> litera1 >> litera2;
            TransferCuvinteLitera(litera1, litera2);
            break;
        }
        getch();
    } while (optiune);

    return 0;
}

int NumarCuvinte(char sir[])
{
    int nr = 0;
    char *cuvant, copia[LMAX];
    strcpy(copia, sir);
    if ((cuvant = strtok(copia, " ,.!\n\t:?")) == NULL)
        return 0;
    nr++;
    while ((cuvant = strtok(NULL, " ,.!\n\t:?")) != NULL)
        nr++;
    return nr;
}

int CuvinteLitere(char sir[], char litera1, char litera2)
{
    char *cuvant, copia[LMAX];
    strcpy(copia, sir);
    int nr = 0;

    if ((cuvant = strtok(copia, " ,.!?:\n\t")) == NULL)
        return 0;
    if ((strchr(strupr(cuvant), toupper(litera1))) && (strchr(strupr(cuvant), toupper(litera2))))
    {
        cout << setw(16) << cuvant;
        nr++;
    }
    while ((cuvant = strtok(NULL, " ,.!?:\n\t")) != NULL)
    {
        if ((strchr(strupr(cuvant), toupper(litera1))) && (strchr(strupr(cuvant), toupper(litera2))))
        {
            cout << setw(16) << cuvant;
            nr++;
        }
    }
    return nr;
}

int Majuscule(char sir[])
{
    for (int i = 0; i < strlen(sir); i++)
    {
        if (islower(sir[i]))
            return 0;
        return 1;
    }
}

int CuvinteMajuscule(char sir[])
{
    int nr = 0;
    char *cuvant, copia[LMAX];
    strcpy(copia, sir);
    if ((cuvant = strtok(copia, " ,.!?:\n\t")) == NULL)
        return 0;
    if (Majuscule(cuvant))
    {
        cout << setw(16) << cuvant;
        nr++;
    }
    while ((cuvant = strtok(NULL, " ,.!\n\t:?")) != NULL)
        if (Majuscule(cuvant))
        {
            cout << setw(16) << cuvant;
            nr++;
        }
    return nr;
}
int NumarCuvinte()
{
    int nr = 0;
    char cuvant[20];
    FILE *f;
    f = fopen("fraza.txt", "r");
    cout << "\nFraza initiala este: \n";
    while(fscanf(f, "%s", cuvant) != EOF)
    {
        cout << cuvant << " ";
        nr++;
    }
    fclose(f);
    return nr;
}
int CuvinteLitere(char litera1, char litera2)
{
    int nr = 0;
    char cuvant[20];
    FILE *f;
    f = fopen("fraza.txt", "r");
    while(fscanf(f, "%s", cuvant) != EOF)
    {
        if ((strchr(strupr(cuvant), toupper(litera1))) && (strchr(strupr(cuvant), toupper(litera2))))
        {
            cout << setw(16) << cuvant;
            nr++;
        }
    }
    fclose(f);
    return nr;
}
int CuvinteMajuscule()
{
    int nr = 0;
    char cuvant[20];
    FILE *f;
    f = fopen("fraza.txt", "r");
    while(fscanf(f, "%s", cuvant) != EOF)
    {
         if (Majuscule(cuvant))
            {
                cout << setw(16) << cuvant;
                nr++;
            }
    }
    fclose(f);
    return nr;
}

TransferCuvinteLitera(char litera1, char litera2)
{
    char cuvant[20];
    FILE *f, *ft;
    f = fopen("fraza.txt", "r");
    ft = fopen("cuvTrans.in", "wb");
    while(fscanf(f, "%s", cuvant) != EOF)
    {
        if ((strchr(strupr(cuvant), toupper(litera1))) && (strchr(strupr(cuvant), toupper(litera2))))
        {
            fwrite(cuvant, sizeof(cuvant), 1, ft);
        }
    }
    cout << "\nContinutul fisierului dupa transfer: \n";
    ft = fopen("cuvTrans.in", "rb");
    while(fread(&cuvant, sizeof(cuvant), 1, ft) > 0)
    {
        cout << cuvant << " ";
    }
    fclose(f);
    fclose(ft);
    return 1;
}
