#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <conio.h>
#include <string.h>
#include <stdio.h>
#include <cstring>
#define LMAX 255

int NumarCuvinte(char sir[]);
int CuvinteLitere(char sir[], char litera1, char litera2);
int Majuscule(char sir[]);
int CuvinteMajuscule(char sir[]);
void TransferCuvinteLitera(char sir[], char litera1, char litera2);
int EliminaCuvinteLitera(char sir[], char litera1, char litera2);
void ViewFile(char nume[30]);
int nrCuv(char nume[]);
int nrCuvLitere(char sir[], char litera1, char litera2);
int nrCuvMaj(char nume[]);

using namespace std;

char sir[LMAX];
int main()
{
    int optiune, nr;
    char fraza[LMAX] = "Dumitru este prieten cu Mihai, Mihai prieteneste cu Corina, rezulta...\nDumitru este prieten cu Mihai, Mihai prieteneste cu Corina, rezulta...";
    do
    {
        system("cls");
        cout << "Proiect nr. 5, elaborat de Cernolev Corina IS11Z\n";
        cout << "Tema: Siruri de caractere. Fisiere text";
        cout << "\n 1. Numarul de cuvinte dintr-o fraza";
        cout << "\n 2. Cuvinte ce contin cel putin 2 litere indicate";
        cout << "\n 3. Cuvintele ce incep cu litera majuscula";
        cout << "\n 4. Numarul de cuvinte dintr-un fisier";
        cout << "\n 5. Cuvintele din fisier ce contin cel putin 2 litere indicate";
        cout << "\n 6. Cuvintele ce incep cu litere majuscule din fisier";
        cout << "\n 7. Transfer cuvinte ce contin literele indicate in alt fisier";
        cout << "\n 8. Eliminare cuvinte cu 2 litere indicate din fisier";
        cout << "\n 0. Stop";
        cout << "\n\n\t Alege (de la 0 la 9) -> ";
        cin >> optiune;
        switch (optiune)
        {
        case 1:
            fflush(stdin);
            cout << "Introduceti o fraza: ";
            gets(fraza);
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
            ViewFile("fraza.txt");
            cout << "\nIn fisier sunt: " << nrCuv("fraza.txt") << " cuvinte.";
            break;
        case 5:
            ViewFile("fraza.txt");
            cout << "\n Dati literele cautate ";
            cin >> litera1 >> litera2;
            if ((nr = nrCuvLitere("fraza.txt", litera1, litera2)) > 0)
                cout << "\n In total " << nr << " cuvinte care contin literele indicate\n";
            else
                cout << "\n Nu-s cuvinte care contin literele indicate \n";
            break;
        case 6:
            ViewFile("fraza.txt");
            if ((nr = nrCuvMaj("fraza.txt")) > 0)
                cout << "\nIn total " << nr << " cuvinte cu litere majuscule\n";
            else
                cout << "\nNu-s cuvinte cu litere majuscule!\n";
            break;
        case 7:
            ViewFile("fraza.txt");
            cout << "Dati literele cautate ";
            cin >> litera1 >> litera2;
            TransferCuvinteLitera("fraza.txt", litera1, litera2);
            break;
        case 8:
            ViewFile("fraza.txt");
            cout << "Dati literele cautate ";
            cin >> litera1 >> litera2;
            EliminaCuvinteLitera("fraza.txt", litera1, litera2);
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
    if ((cuvant = strtok(copia, ",.!\n\t:;? ")) == NULL)
        return 0;
    nr++;
    while ((cuvant = strtok(NULL, ",.!\n\t:;? ")) != NULL)
        nr++;
    return nr;
}

int nrCuv(char nume[30])
{
    char sir2[LMAX];
    FILE *f;
   f = fopen(nume, "r");
   int nr = 0;
   while(fread(sir2,sizeof(sir2),1,f) != 0)
    {
        nr = NumarCuvinte(sir2);
    }
   fclose(f);
   return nr;
}

int CuvinteLitere(char sir[], char litera1, char litera2)
{
    char *cuvant, copia[LMAX];
    strcpy(copia, sir);
    int nr = 0;

    if ((cuvant = strtok(copia, ",.!?:\n\t ")) == NULL)
        return 0;
    if ((strchr(cuvant, litera1)) && (strchr(cuvant, litera2)))
    {
        cout << setw(16) << cuvant;
        nr++;
    }
    while ((cuvant = strtok(NULL, ",.!?:\n\t ")) != NULL)
    {
        if ((strchr(cuvant, litera1)) && (strchr(cuvant, litera2)))
        {
            cout << setw(16) << cuvant;
            nr++;
        }
    }
    return nr;
}


int nrCuvLitere(char nume[30], char litera1, char litera2)
{
    char sir2[LMAX];
    FILE *f;
   f = fopen(nume, "r");
   int nr = 0;
   while(fread(sir2,sizeof(sir2),1,f) != 0)
    {
        nr = CuvinteLitere(sir2, litera1, litera2);

    }
   fclose(f);
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
    if ((cuvant = strtok(copia, ",.!?:\n\t ")) == NULL)
        return 0;
    if (Majuscule(cuvant))
    {
        cout << setw(16) << cuvant;
        nr++;
    }
    while ((cuvant = strtok(NULL, ",.!\n\t:? ")) != NULL)
        if (Majuscule(cuvant))
        {
            cout << setw(16) << cuvant;
            nr++;
        }
    return nr;
}

int nrCuvMaj(char nume[30])
{
    char sir2[LMAX];
    FILE *f;
   f = fopen(nume, "r");
   int nr = 0;
   while(fread(sir2,sizeof(sir2),1,f) != 0)
    {
        nr = CuvinteMajuscule(sir2);

    }
   fclose(f);
   return nr;
}

void TransferCuvinteLitera(char nume[], char litera1, char litera2)
{
    FILE *f, *ft;
    int n =0;
    ft= fopen(nume, "r");
    f = fopen("cuvTrans.txt", "w");
    char *cuvant, copia[LMAX];
    char sir[LMAX];
    while(fread(sir,sizeof(sir),1,ft) != 0)
    {
        strcpy(copia, sir);
        if ((cuvant = strtok(copia, ",.!?:\n\t ")) == NULL)
        return;
        if ((strchr(cuvant, litera1)) && (strchr(cuvant, litera2)))
        {
            fputs(cuvant, f);
            fputs(" ", f);
            n++;
        }
        while ((cuvant = strtok(NULL, ",.!?:\n\t ")) != NULL)
        {
            if ((strchr(cuvant, litera1)) && (strchr(cuvant, litera2)))
            {
                fputs(cuvant, f);
                fputs(" ", f);
                n++;
                if(n%5 == 0)
                fputs("\n", f);
            }

        }
    }
    fclose(f);
    char cuvTrans[LMAX];
    ViewFile("cuvTrans.txt");
}

int EliminaCuvinteLitera(char nume[], char litera1, char litera2)
{
    FILE *f, *ft;
    int n =0;
    ft = fopen(nume, "r");
    f = fopen("frazapt.txt", "w");
    char *cuvant, copia[LMAX];
    char sir[LMAX];
    while(fread(sir,sizeof(sir),1,ft) != 0)
    {
        strcpy(copia, sir);
        if ((cuvant = strtok(copia, ",.!?:\n\t ")) == NULL)
            return 0;
        if (!((strchr(cuvant, litera1)) && (strchr(cuvant, litera2))))
        {
            fputs(cuvant, f);
            fputs(" ", f);
            n++;
        }
        while (((cuvant = strtok(NULL, ",.!?:\t ")) != NULL))
        {
            if (!((strchr(cuvant, litera1)) && (strchr(cuvant, litera2))))
            {
                fputs(cuvant, f);
                fputs(" ", f);
                n++;
            }
        }
    }
    fclose(f);
    fclose(ft);
    f =fopen(nume, "w");
    ft = fopen("frazapt.txt", "r");
    while(fread(sir, sizeof(sir), 1, ft) != 0)
    {
        fputs(sir, f);
    }
    fclose(f);
    fclose(ft);
    ViewFile("fraza.txt");
}

void ViewFile(char nume[30])
{
    char sir2[LMAX];
   FILE *f;
   f = fopen(nume, "r");
   while(!feof(f))
    {
        fread(sir2, sizeof(sir2),1,f);
        puts(sir2);
    }
   fclose(f);
}
