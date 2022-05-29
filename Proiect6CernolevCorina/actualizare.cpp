#include <bits/stdc++.h>
#include "czodiac.h"

using namespace std;

void Transfer()
{
    FILE *ft, *f;
    char prenume[21];
    Persoana pr;
    ft = fopen("czodiac.txt", "r");
    f = fopen("czodiac.in", "wb");
    while(fscanf(ft, "%d %s %s %d %d %d %s %s %d %d",
                 &pr.id, pr.nume, prenume, &pr.dn.zi, &pr.dn.luna, &pr.dn.an,
                 pr.zodia, pr.piatra, &pr.numereNorocoase[0], &pr.numereNorocoase[1]) != EOF)
                 {
                     pr.numarDestin = 10;
                    strcat(pr.nume, " ");
                    strcat(pr.nume, prenume);
                    fwrite(&pr, sizeof(Persoana), 1, f);
                 }
    printf("\nOk");
    fclose(ft);
    fclose(f);
}

void Linia(int st, int lin, int mij, int dr);

void Afisare()
{
    int n = 0;
    FILE *f;
    Persoana pr;
    f = fopen("czodiac.in", "rb");
    Linia(201, 205, 209, 187);
    printf("\n%c Nr %c Id%c Nume, prenume pers.%cData nast.%c %8s %3c %8s %3cNr. Noroc%c Nr. Destin %c",
           186, 179, 179, 179, 179, "zodia", 179, "piatra", 179, 179, 186);
    Linia(199, 196, 197, 182);
    while(fread(&pr, sizeof(Persoana), 1, f) > 0)
    {
        n++;
        printf("\n%c %2d %c%3d%c %-18.18s %c%02d.%02d.%4d%c %-10.10s %c %-10.10s %c %3d %3d %c %9d %2c",
                 186, n, 179, pr.id, 179, pr.nume, 179, pr.dn.zi, pr.dn.luna, pr.dn.an,
                 179, pr.zodia, 179, pr.piatra, 179, pr.numereNorocoase[0],  pr.numereNorocoase[1], 179, pr.numarDestin, 186);
    }
    Linia(200, 205, 207, 188);
    fclose(f);
}

void Citire(Persoana &pr)
{
    char prenume[21];
    do
    {
        cout << "\n Intrduceti id-ul: ";
        cin >> pr.id;
    } while(pr.id <= 0);
    cout << " Introduceti numele: ";
    cin >> pr.nume;
    cout << " Introduceti prenumele: ";
    cin >> prenume;
    strcat(pr.nume, " ");
    strcat(pr.nume, prenume);
    do
    {
        cout << " Introduceti data nasterii: " << "\n Ziua - ";
        cin >> pr.dn.zi;
    } while((pr.dn.zi <= 0)||(pr.dn.zi > 31));
    do
    {
        cout << " Luna - ";
        cin >> pr.dn.luna;
    } while ((pr.dn.luna <= 0)||(pr.dn.luna > 12));
    do
    {
        cout << " Anul - ";
        cin >> pr.dn.an;
    } while ((pr.dn.an <= 1000));
    cout << " Introduceti zodia: ";
    cin >> pr.zodia;
    cout << " Introduceti piatra: ";
    cin >> pr.piatra;
    do
    {
        cout << " Introduceti numerele norocoase: ";
        cin >> pr.numereNorocoase[0] >> pr.numereNorocoase[1];
    }while((pr.numereNorocoase[0] < 0)||(pr.numereNorocoase[1] < 0));
}
void Adaugare()
{
    Persoana prAdd;
    Citire(prAdd);
    FILE *f;
    f = fopen("czodiac.in", "ab");
    fwrite(&prAdd, sizeof(Persoana), 1, f);
    fclose(f);

    cout << "\n Lista persoanelor zodiacului dupa adaugare:\n";
    Afisare();
}
void InscriereModificata(Persoana persoane[100], int cit)
{
    FILE *f;
    f = fopen("czodiac.in", "wb");
    for (int i = 0; i < cit; i++)
    {
       fwrite(&persoane[i], sizeof(Persoana), 1, f);
    }
    fclose(f);
}
void Modificare()
{
    FILE *f;
    Persoana persoane[100];
    Persoana persoana;
    char nume[30], prenume[15];
    int i = 0;
    int cit = 0;
    int aux, key;
    f = fopen("czodiac.in", "rb");
    while(fread(&persoana, sizeof(Persoana), 1, f) > 0)
    {
        persoane[i] = persoana;
        i++;
        cit = i;
    }
    fclose(f);
    printf("\nIntroduceti numele si prenumele personei, datele careia vreti sa modificati: ");
    scanf("%s %s", nume, prenume);
    strcat(nume, " ");
    strcat(nume, prenume);
    for(i = 0; i < cit; i++)
    {
        int cmp = strcmp(persoane[i].nume, nume);
        if (cmp == 0)
        {
            aux = i;
            break;
        }
    }
    do
    {
        cout << "\nCe vreti sa modificati: ";
        cout << "\n1. Data nasterii";
        cout << "\n2. Zodia";
        cout << "\n3. Piatra";
        cout << "\n4. Numar";
        cout << "\n0. Nimic";
        cout << "\n\t Alege (de la 0 la 4) -> ";
        cin >> key;
        switch(key)
        {
            case 1:
                cout << "Introduceti ziua, luna si anul nasterii(fiecare din rand nou): ";
                cin >> persoane[aux].dn.zi >> persoane[aux].dn.luna >> persoane[aux].dn.an;
                InscriereModificata(persoane, cit);
            break;
            case 2:
                cout << "Introduceti Zodia: ";
                cin >> persoane[aux].zodia;
                InscriereModificata(persoane, cit);
            break;
            case 3:
                cout << "Introduceti Piatra: ";
                cin >> persoane[aux].piatra;
                InscriereModificata(persoane, cit);
            break;
            case 4:
                cout << "Introduceti numerele norocoase: ";
                cin >> persoane[aux].numereNorocoase[0] >> persoane[aux].numereNorocoase[1];
                InscriereModificata(persoane, cit);
            break;
        }
    } while(key);
    printf("\nDatele au fost modificate");
    fclose(f);
}
