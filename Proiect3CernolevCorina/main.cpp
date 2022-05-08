#include <iostream>
#include <stdlib.h>
#include <conio.h>
#include <iomanip>
#include <cstdlib>

#define NMAX 100
#define VARSTA_MAX 100
#define VARSTA_MIN 0

using namespace std;

// interfata programului
// n - dimensiunea tabloului; la iesire: a - tabloul; functia returneaza 1/0 succes/eroare
int Citire(int n, int a[]);
void Afisare(int n, int a[], char sir[]);
// functia returneaza valoarea minima
int Minim(int n, int a[]);
int Maxim(int n, int a[]);
double Media(int n, int a[]);
int Aranjare(int n, int a[]);
int Rotire(int n, int a[], int k);
// val - valoarea adaugata
int Inserare(int &n, int a[], int val);
// vom lua n ca index de la care incepem
int Cautare(int n, int a[], int val);
// val pozitia
int Eliminare(int &n, int a[], int val);
void Clasificare(int n, int a[]);
int Clasificare2(int n, int a[], int b[]);
int Generare(int n, int a[]);

int main()
{
    int b[6] = {0, 0, 0, 0, 0};
    int optiune;
    int n = 10;
    int varsta[NMAX] = {10, 19, 15, 27, 18, 39, 26, 28, 30, 27};
    int val;
    // citirea datelor
    cout << "Cate persoane ? ";
    cin >> n;
    Citire(n, varsta);
    do
    {
        system("cls");
        cout << "Proiect nr.3 elaborat de Cernolev Corina" << endl;
        cout << "Tema: Varstele persoanelor intr-o familie (echipa)" << endl;
        cout << "1. Determinarea varstei minime si maxime" << endl;
        cout << "2. Determinarea varstei medii" << endl;
        cout << "3. Sortarea varstelor" << endl;
        cout << "4. Rotirea" << endl;
        cout << "5. Inserarea unei varste" << endl;
        cout << "6. Stergerea unei varste" << endl;
        cout << "7. Clasificarea" << endl;
        cout << "8. Generare" << endl;
        cout << "0. Iesire" << endl;
        cout << "\n\n\t Alege o optiune de la 0 la 8 -> ";
        cin >> optiune;
        switch (optiune)
        {
        case 1:
            Afisare(n, varsta, "initial");
            cout << "\n Varsta cea mai mare este " << Minim(n, varsta);
            cout << "\n Varsta cea mai mica este " << Maxim(n, varsta) << endl;
            break;
        case 2:
            Afisare(n, varsta, "initial");
            cout << "\nVarsta medie este: " << Media(n, varsta) << endl;
            break;
        case 3:
            Afisare(n, varsta, "initial");
            Aranjare(n, varsta);
            Afisare(n, varsta, "aranjat");
            break;
        case 4:
            int k;
            cout << "Dati numarul de rotiri ";
            cin >> k;
            Afisare(n, varsta, "initial");
            Rotire(n, varsta, k);
            Afisare(n, varsta, "rotit");
            break;
        case 5:
            cout << "Introduceti varsta de inserat ";
            cin >> val;
            Afisare(n, varsta, "initial");
            Inserare(n, varsta, val);
            Afisare(n, varsta, "dupa inserare");
            break;
        case 6:
            Afisare(n, varsta, "initial");
            cout << "Introduceti valoarea de sters ";
            cin >> val;
            int poz;
            if ((poz = Cautare(n, varsta, val)) < n)
            {
                Eliminare(n, varsta, poz);
            }
            Afisare(n, varsta, "dupa eliminare");
            break;
        case 7:

            Afisare(n, varsta, "curent");
            cout << "\nAvem urmatoarele rezultate: " << endl;
            //Clasificare(n, varsta);
            Clasificare2(n, varsta, b);
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
        }
        _getch();
    } while (optiune);
    return 0;
}

int Citire(int n, int a[])
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
    for (int i = 0; i < n; i++)
    {
        switch (varianta)
        {
        case 1:
            do
            {
                cout << "Indica varsta persoanei " << i + 1 << ": ";
                cin >> a[i];
            } while (a[i] > VARSTA_MAX);

            break;
        case 2:
             a[i] = (rand() % VARSTA_MAX + 18)/2; // varste din intervalul 9-59
            break;
        case 3:
            a[i] = i % 7 + 19; // genereaza doar tineri - 19-24 ani
            break;
        }
    }
    return 1;
}
void Afisare(int n, int a[], char sir[])
{
    int i;
    cout << "\nTabloul de varste " << sir << "\n";
    for (i = 0; i < n; i++)
    {
        cout << setw(8) << a[i] << " ";
    }
    cout << endl;
}
int Minim(int n, int a[])
{
    int i, minim = a[0];
    for (i = 1; i < n; i++)
    {
        if (minim < a[i])
        {
            minim = a[i];
        }
    }
    return minim;
}
int Maxim(int n, int a[])
{
    int i, maxim = a[0];
    for (i = 1; i < n; i++)
    {
        if (maxim > a[i])
        {
            maxim = a[i];
        }
    }
    return maxim;
}
double Media(int n, int a[])
{
    double sum = a[0];
    for (int i = 1; i < n; i++)
    {
        sum += a[i];
    }
    return sum / n;
}
int Aranjare(int n, int a[])
{
    int i, k = 0;
    bool change;
    do
    {
        k++;
        change = false;
        for (i = 0; i < n - k; i++)
        {
            if (a[i] < a[i + 1])
            {
                swap(a[i], a[i + 1]);
                change = true;
            }
        }
    } while (change);
    return 1;
}
int Rotire(int n, int a[], int k)
{
    for (int j = 0; j < k; j++)
    {
        int temp = a[0];
        for (int i = 0; i < n - 1; i++)
        {
            a[i] = a[i + 1];
        }
        a[n - 1] = temp;
    }
    return 1;
}
// val - valoarea adaugata
int Inserare(int &n, int a[], int val)
{
    n++;
    a[n - 1] = val;
    return 1;
}
// vom lua n ca index de la care incepem
int Cautare(int n, int a[], int val)
{
    int i = 0;
    while ((a[i] != val) && (i < n))
    {
        i++;
    }
    return i;
}
// val pozitia
int Eliminare(int &n, int a[], int val)
{
    for (int i = val; i < n - 1; i++)
    {
        a[i] = a[i + 1];
    }
    n--;
    return 1;
}

void Clasificare(int n, int a[])
{
    //     1. Copilarie : 0-13 ani
    //     2. Adolescenta: 13-18 ani
    //     3. Tinerete: 18-24 ani
    //     4. Maturitate: 24-60 ani
    //     5. Varstnic: 60+
    int copil, adolescent, tanar, matur, varstnic;
    copil = adolescent = tanar = matur = varstnic = 0;
    for (int i = 0; i < n; i++)
    {
        if (a[i] < 13)
            copil++;
        else if (a[i] < 18)
            adolescent++;
        else if (a[i] < 24)
            tanar++;
        else if (a[i] < 60)
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

int Generare(int n, int a[])
{
    return 1;
}

int Clasificare2(int n, int a[], int b[])
{
    int limite[] = {13, 18, 24, 60, 100};
    for (int i = 0; i < n; i++)
        for (int j = 0; j < 5; j++)
            if (a[i] <= limite[j])
                {
                    b[j]++;
                    break;
                }
    return 1;
}
