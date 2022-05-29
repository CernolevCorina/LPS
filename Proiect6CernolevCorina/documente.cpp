#include <bits/stdc++.h>
#include "czodiac.h"

using namespace std;

void Linia(int st, int lin, int mij, int dr)
{
    int i;
    printf("\n%c", st);
    for(i=1; i<=4; i++) printf("%c", lin); printf("%c", mij); //nr
    for(i=1; i<=3; i++) printf("%c", lin); printf("%c", mij); //id
    for(i=1; i<=20; i++) printf("%c", lin); printf("%c", mij); //nume
    for(i=1; i<=10; i++) printf("%c", lin); printf("%c", mij); //data
    for(i=1; i<=12; i++) printf("%c", lin); printf("%c", mij); //zodia
    for(i=1; i<=12; i++) printf("%c", lin); printf("%c", mij); // piatra
    for(i=1; i<=9; i++) printf("%c", lin); printf("%c", mij); // nr norocoase
    for(i=1; i<=12; i++) printf("%c", lin); printf("%c", dr); // nr destin
}

void Afisare(Persoana persoane[100], int n)
{
    Linia(201, 205, 209, 187);
    printf("\n%c Nr %c Id%c Nume, prenume pers.%cData nast.%c %8s %3c %8s %3cNr. Noroc%c Nr. Destin %c",
           186, 179, 179, 179, 179, "zodia", 179, "piatra", 179, 179, 186);
    Linia(199, 196, 197, 182);
    for(int i = 0; i < n; i++)
    {
        printf("\n%c %2d %c%3d%c %-18.18s %c%02d.%02d.%4d%c %-10.10s %c %-10.10s %c %3d %3d %c %9d %2c",
                 186, i+1, 179, persoane[i].id, 179, persoane[i].nume, 179, persoane[i].dn.zi, persoane[i].dn.luna, persoane[i].dn.an,
                 179, persoane[i].zodia, 179, persoane[i].piatra, 179, persoane[i].numereNorocoase[0],  persoane[i].numereNorocoase[1], 179, persoane[i].numarDestin, 186);
    }
    Linia(200, 205, 207, 188);
}

void Lista1()
{
    int i = 0;
    char zodia[20];
    cout << "Introduceti zodia dorita: ";
    fflush(stdin);
    gets(zodia);
    Persoana persoana;
    Persoana persoane[100];
    FILE *f;
    f = fopen("czodiac.in", "rb");
    while(fread(&persoana, sizeof(Persoana), 1, f) > 0)
    {
        if(strnicmp(persoana.zodia, zodia, strlen(zodia)) == 0)
        {
            persoane[i] = persoana;
            i++;
        }
    }

    Afisare(persoane, i);
}

void Lista2()
{
    int i = 0;
    char piatra[20];
    cout << "Introduceti piatra dorita: ";
    fflush(stdin);
    gets(piatra);
    Persoana persoana;
    Persoana persoane[100];
    FILE *f;
    f = fopen("czodiac.in", "rb");
    while(fread(&persoana, sizeof(Persoana), 1, f) > 0)
    {
        if(strcmp(persoana.piatra, piatra) == 0)
        {
            persoane[i] = persoana;
            i++;
        }
    }
    Afisare(persoane, i);
}
void Lista3()
{
    int i = 0;
    char nume[30];
    char compvalue[30];
    cout << "Introduceti numele dorit: ";
    fflush(stdin);
    gets(nume);
    Persoana persoana;
    Persoana persoane[100];
    FILE *f;
    f = fopen("czodiac.in", "rb");
    while(fread(&persoana, sizeof(Persoana), 1, f) > 0)
    {
        if(strnicmp(persoana.nume, nume, strlen(nume)) == 0)
        {
            persoane[i] = persoana;
            i++;
        }
    }
    if(persoane[0].dn.zi)
    {
        Afisare(persoane, i);
    }
    else {
        cout << "Nu sunt persoane cu numele indicat \n";
    }
}
void Lista4()
{
    int i = 0;
    int an;
    cout << "Introduceti anul dorit: ";
    fflush(stdin);
    cin >> an;
    Persoana persoana;
    Persoana persoane[100];
    FILE *f;
    f = fopen("czodiac.in", "rb");
    while(fread(&persoana, sizeof(Persoana), 1, f) > 0)
    {
        if(persoana.dn.an == an)
        {
            persoane[i] = persoana;
            i++;
        }
    }
    Afisare(persoane, i);
}
void Lista5()
{
    int i = 0;
    int numar;
    cout << "Introduceti numarul destinului dorit: ";
    fflush(stdin);
    cin >> numar;
    Persoana persoana;
    Persoana persoane[100];
    FILE *f;
    f = fopen("czodiac.in", "rb");
    while(fread(&persoana, sizeof(Persoana), 1, f) > 0)
    {
        if(persoana.numarDestin != 10)
        {
            if(persoana.numarDestin == numar)
            {
                persoane[i] = persoana;
                i++;
            }
        } else
        {
            cout << "Numerele destinului nu au fost introduse\n";
            return;
        }
    }
    if(persoane[0].dn.zi)
    {
        Afisare(persoane, i);
    } else {
        cout << "Nu sunt persoane cu numarul destinului indicat \n";
    }
}
void Lista6()
{

}
void Lista7()
{

}
void Lista8()
{

}
