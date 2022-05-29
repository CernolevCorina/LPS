#include <iostream>
#include <stdlib.h>
#include <conio.h>
#include <iomanip>
#include <cstdlib>
#include <stdio.h>
#include <string.h>

#define NMAX 100
#define VARSTA_MAX 100
#define VARSTA_MIN 0

using namespace std;

// l - numarul de echipe; k - numarul de persoane in echipa
int Citire(int &l, int &k, int a[NMAX][NMAX]);
void Afisare(int l, int k, int a[NMAX][NMAX], char sir[]);
// functia returneaza valoarea minima
int Minim(int l, int k, int a[NMAX][NMAX], int pozMinMax[]);
// functia returneaza valoarea maxima
int Maxim(int l, int k, int a[NMAX][NMAX], int pozMinMax[]);
// functia returneaza media
double Media(int l, int k, int a[NMAX][NMAX]);
// aranjeaza in oridine crescatoare participantii echipei indicate
// au loc schimbari in toate echipele
int Aranjare(int numar, int l, int k, int a[NMAX][NMAX]);
// roteste spre stanga, de numarul indicat de ori
int Rotire(int l, int k, int a[NMAX][NMAX], int n);
//Insereaza la sfarsitul tabelului o noua echipa
int Inserare(int &l, int k, int a[NMAX][NMAX]);
// val - numarul echipei de sters
// Elimina echipa indicata
int Eliminare(int &l, int k, int a[NMAX][NMAX], int val);
// 1. Copilarie : 0-13 ani
// 2. Adolescenta: 13-18 ani
// 3. Tinerete: 18-24 ani
// 4. Maturitate: 24-60 ani
// 5. Varstnic: 60+
void Clasificare(int l, int k, int a[NMAX][NMAX]);
int Clasificare2(int l, int k, int a[NMAX][NMAX], int b[]);
// genereaza noi varste pentru toate echipele conform unei reguli
int Generare(int l, int k, int a[NMAX][NMAX]);
void Interschimb(int k, int a[NMAX][NMAX]);
void VarstaMedie(int l, int &k, int a[NMAX][NMAX]);

int main()
{
    int pozMinMax[5];
    int b[6] = {0, 0, 0, 0, 0};
    int optiune;
    int k = 3;
    int l = 7;
    int varsta[NMAX][NMAX] = {{10, 19, 15}, {27, 18, 39}, {26, 28, 30}, {27, 12, 23}, {21, 20, 17}, {32, 31, 43}, {34, 67, 75}};
    int val;
    Citire(l, k, varsta);
    do
    {
        system("cls");
        cout << "Proiect nr.4 elaborat de Cernolev Corina" << endl;
        cout << "Tema: Varstele persoanelor intr-o familie (echipa)" << endl;
        cout << "1. Determinarea varstei minime si maxime" << endl;
        cout << "2. Determinarea varstei medii" << endl;
        cout << "3. Sortarea varstelor" << endl;
        cout << "4. Rotirea" << endl;
        cout << "5. Inserarea unei echipe" << endl;
        cout << "6. Stergerea unei echipe" << endl;
        cout << "7. Clasificarea" << endl;
        cout << "8. Generare" << endl;
        cout << "9. Interschimba doua linii" << endl;
        cout << "10. Adaugarea varstei medii" << endl;
        cout << "0. Iesire" << endl;
        cout << "\n\n\t Alege o optiune de la 0 la 8 -> ";
        cin >> optiune;
        switch (optiune)
        {
        case 1:
            Afisare(l, k, varsta, "initial");
            cout << "\n Varsta cea mai mare este " << Maxim(l, k, varsta, pozMinMax);
            cout << "\n O are membrul echipei " << pozMinMax[2] + 1 << " cu numarul " << pozMinMax[3] + 1;
            cout << "\n Varsta cea mai mica este " << Minim(l, k, varsta, pozMinMax);
            cout << "\n O are membrul echipei " << pozMinMax[0] + 1 << " cu numarul " << pozMinMax[1] + 1;
            break;
        case 2:
            Afisare(l, k, varsta, "initial");
            cout << "\nVarsta medie este: " << Media(l, k, varsta) << endl;
            break;
        case 3:
            int numar;
            Afisare(l, k, varsta, "initial");
            cout << "Numarul echipei de aranjat: ";
            cin >> numar;
            Aranjare(numar-1, l, k, varsta);
            Afisare(l, k, varsta, "aranjat");
            break;
        case 4:
            int n;
            cout << "Dati numarul de rotiri ";
            cin >> n;
            Afisare(l, k, varsta, "initial");
            Rotire(l, k, varsta, n);
            Afisare(l, k, varsta, "rotit");
            break;
        case 5:
            Afisare(l, k, varsta, "initial");
            Inserare(l, k, varsta);
            Afisare(l, k, varsta, "dupa inserare");
            break;
        case 6:
            Afisare(l, k, varsta, "initial");
            cout << "Introduceti numarul echipei de sters: ";
            cin >> val;
            Eliminare(l, k, varsta, val-1);
            Afisare(l, k, varsta, "dupa eliminare");
            break;
        case 7:
            Afisare(l, k, varsta, "curent");
            cout << "\nAvem urmatoarele rezultate: " << endl;
            //Clasificare(l, k, varsta);
            Clasificare2(l, k, varsta, b);
            if (b[0] != 0)
                cout << b[0] << " copii" << endl;
            if (b[1] != 0)
                cout << b[1] << " adolescenti" << endl;
            if (b[2] != 0)
                cout << b[2] << " tineri" << endl;
            if (b[3] != 0)
                cout << b[3] << " maturi" << endl;
            if (b[4] != 0)
                cout << b[4] << " varstnici" << endl;
            break;
        case 8:
            Generare(l, k, varsta);
            Afisare(l, k, varsta, "tabloul generat:");
            break;
        case 9:
            Afisare(l, k, varsta, "tabloul initial:");
            Interschimb(k, varsta);
            Afisare(l, k, varsta, "dupa interschimbarea a doua linii:");
        case 10:
            Afisare(l, k, varsta, "tabloul initial:");
            VarstaMedie(l, k, varsta);
            Afisare(l, k, varsta, "tabloul dupa inserarea mediei:");
            break;
        }
        _getch();
    } while (optiune);
    return 0;
}

int Citire(int &l, int &k, int a[NMAX][NMAX])
{
    int varianta;
    cout << "\n Alege varianta de citire:" << endl;
    cout << "\n 1. De la tastatura;";
    cout << "\n 2. Aleator;";
    cout << "\n 3. Generat dupa o regula;";
    cout << "\n 4. Din fisier;";
    cout << "\n 5. Implicit";
    cout << "\n\t -> ";
    cin >> varianta;
        switch (varianta)
        {
        case 1:
            cout << "Cate echipe? ";
            cin >> l;
            cout << "Cate persoane in echipa? ";
            cin >> k;
            for (int i = 0; i < l; i++)
            for (int j = 0; j < k; j++)
            {
                do
                {
                    cout << "Indica varsta persoanei in echipa " << i + 1 << " cu indicele " << j + 1 << " : ";
                    cin >> a[i][j];
                } while (a[i][j] > VARSTA_MAX);
            }
            break;
        case 2:
            cout << "Cate echipe? ";
            cin >> l;
            cout << "Cate persoane in echipa? ";
            cin >> k;
            for (int i = 0; i < l; i++)
            for (int j = 0; j < k; j++)
            {
                a[i][j] = (rand() % VARSTA_MAX + 18)/2; // varste din intervalul 9-59
            }
            break;
        case 3:
            cout << "Cate echipe? ";
            cin >> l;
            cout << "Cate persoane in echipa? ";
            cin >> k;
            for (int i = 0; i < l; i++)
            for (int j = 0; j < k; j++)
            {
                a[i][j] = (i + j) % 7 +18; // genereaza doar tineri - 18-24 ani
            }
            break;
        case 4:
            FILE *f;
            f = fopen("varste.txt", "r");
            fscanf( f, "%d %d", &l, &k);
            cout << l << " " << k;
            for (int i = 0; i < l; i++)
            for (int j = 0; j < k; j++)
            {
                fscanf(f, "%d", &a[i][j]);
            }
            fclose(f);
        }
    return 1;
}
void Afisare(int l, int k, int a[NMAX][NMAX], char sir[])
{
    int i;
    cout << "\nTabloul de varste " << sir << "\n";
    for (i = 0; i < l; i++)
    {
        for (int j = 0; j < k; j++)
        {
            cout << setw(8) << a[i][j] << " ";
        }
        cout << endl;
    }

}
int Minim(int l, int k, int a[NMAX][NMAX], int pozMinMax[])
{
    int minim = a[0][0];
    pozMinMax[0] = 0;
    pozMinMax[1] = 0;
    for (int i = 0; i < l; i++)
        for (int j = 0; j < k; j++)
        {
            if (minim > a[i][j])
            {
                minim = a[i][j];
                pozMinMax[0] = i;
                pozMinMax[1] = j;
            }
        }
    return minim;
}
int Maxim(int l, int k, int a[NMAX][NMAX], int pozMinMax[])
{
    int maxim = a[0][0];
    pozMinMax[2] = 0;
    pozMinMax[3] = 0;
    for (int i = 0; i < l; i++)
        for (int j = 0; j < k; j++)
        {
            if (maxim < a[i][j])
            {
                maxim = a[i][j];
                pozMinMax[2] = i;
                pozMinMax[3] = j;
            }
        }
    return maxim;
}
double Media(int l,int k, int a[NMAX][NMAX])
{
    double sum = 0;
    for (int i = 0; i < l; i++)
        for (int j = 0; j < k; j++)
        {
            sum += a[i][j];
        }
    return sum / (l*k);
}
int Aranjare(int numar, int l, int k, int a[NMAX][NMAX])
{
    int j, x = 0;
    bool change;
    do
    {
        x++;
        change = false;
        for (j = 0; j < k-x; j++)
        {
            if (a[numar][j] > a[numar][j + 1])
            {
                for (int i = 0; i < l; i++)
                    {
                        swap(a[i][j], a[i][j + 1]);
                        change = true;
                    }

            }
        }
    } while (change);
    return 1;
}
int Rotire(int l, int k, int a[NMAX][NMAX], int n)
{
    for (int m = 0; m < n; m++)
        for (int i = 0; i < l; i++)
            {
                int temp = a[i][0];
                for (int j = 0; j < k - 1; j++)
                    {
                        a[i][j] = a[i][j + 1];
                    }
                a[i][k - 1] = temp;
            }
    return 1;
}
// val - valoarea adaugata
int Inserare(int &l, int k, int a[NMAX][NMAX])
{
    l++;
    for (int j = 0; j < k; j++)
    do
        {
            cout << "Introduceti varsta persoanei numarul " << j+1 << " : ";
            cin >> a[l-1][j];
        } while ((a[l-1][j] > VARSTA_MAX));
    return 1;
}
// val numarul liniei de eliminat
int Eliminare(int &l, int k, int a[NMAX][NMAX], int val)
{
    for (int i = val; i < l - 1; i++)
        for (int j = 0; j < k; j++)
    {
        a[i][j] = a[i + 1][j];
    }
    l--;
    return 1;
}

void Clasificare(int l, int k, int a[NMAX][NMAX])
{
    //     1. Copilarie : 0-13 ani
    //     2. Adolescenta: 13-18 ani
    //     3. Tinerete: 18-24 ani
    //     4. Maturitate: 24-60 ani
    //     5. Varstnic: 60+
    int copil, adolescent, tanar, matur, varstnic;
    copil = adolescent = tanar = matur = varstnic = 0;
    for (int i = 0; i < l; i++)
        for (int j =0; j < k; j++)
    {
        if (a[i][j] < 13)
            copil++;
        else if (a[i][j] < 18)
            adolescent++;
        else if (a[i][j] < 24)
            tanar++;
        else if (a[i][j] < 60)
            matur++;
        else
            varstnic++;
    }
    cout << "\nAvem: " << endl;
    if (copil != 0)
        cout << copil << " copii" << endl;
    if (adolescent != 0)
        cout << adolescent << " adolescenti" << endl;
    if (tanar != 0)
        cout << tanar << " tineri" << endl;
    if (matur != 0)
        cout << matur << " maturi" << endl;
    if (varstnic != 0)
        cout << varstnic << " varstnici" << endl;
}

int Generare(int l, int k, int a[NMAX][NMAX])
{
   for(int j = 0; j < k; j++)
   {
       a[0][j] = 1;
   }
   for(int i = 1; i < l; i++)
    for(int j = 0; j < k; j++)
   {
       if(a[i][j-1])
       {
           a[i][j] = a[i][j-1] + a[i-1][j];
       } else
       {
            a[i][j] = 1;
       }
   }
    return 1;
}
int Clasificare2(int l, int k, int a[NMAX][NMAX], int b[])
{
    int limite[] = {13, 18, 24, 60, 100};
    for (int i = 0; i < l; i++)
        for (int m = 0; m < k; m++)
            for (int j = 0; j < 5; j++)
                if (a[i][m] < limite[j])
                    {
                        b[j]++;
                        break;
                    }
    return 1;
}

void Interschimb(int k, int a[NMAX][NMAX])
{
    int linia1, linia2;
    int val;
    cout << "\n Dati cele doua linii de interschimbat: ";
    cin >> linia1 >> linia2;
    for (int j = 0; j < k; j++)
    {
        val = a[linia1-1][j];
        a[linia1-1][j] = a[linia2-1][j];
        a[linia2-1][j] = val;
    }
}

void VarstaMedie(int l, int &k, int a[NMAX][NMAX])
{
    int media, rest, sum;
    for (int i = 0; i < l; i++)
    {
        sum = 0;
         for(int j = 0; j < k; j++)
            {
                sum += a[i][j];
            }
        media = sum/k;
        rest = sum%k;
        a[i][k] = media;
        a[i][k+1] = rest;
    }
    k +=2;
}
