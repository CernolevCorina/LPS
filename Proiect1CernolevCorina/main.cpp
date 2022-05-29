#include <iostream>
#include <iomanip>

#define VMAX 150

using namespace std;

int main()
{
    int persoana;
    int maxim, minim, decalaj;
    int varsta, maimic = 0, maimare = 0, egal = 0;
    int ljos, lsus, interval = 0;
    int n;
    int copil = 0, tanar = 0, adolescent = 0, matur = 0, varstnic = 0;
    float media = 0;
    cout << "Proiect Nr.1 elaborat de Cernolev Corina" << endl;
    cout << "Tema: Varstele persoanelor dintr-o familie (echipa)" << endl;

    // 0. citirea datelor
    do
    {
        cout << "Indica numarul de persoane: ";
        cin >> n;
    } while ((n < 1) || (n > 20));
    cout << "Introduceti varsta pentru comparatie: ";
    cin >> varsta;
    cout << "Introduceti limitele de varsta: " << endl;
    cout << "Limita inferioara: ";
    cin >> ljos;
    cout << "Limita superioara: ";
    cin >> lsus;
    cout << "Introduceti varstele: " << endl;
    maxim = -VMAX;
    minim = VMAX;

    for (int i = 1; i <= n; i++)
    {
        do
        {
            cout << "Varsta persoanei " << i << " = ";
            cin >> persoana;
        } while ((persoana < 0) || (persoana >= VMAX));

        // 1. De determinat cea mai mică și cea mai mare valoare a varstei
        if (persoana < minim)
            minim = persoana;
        if (persoana > maxim)
            maxim = persoana;

        // Determinam suma varstelor pentru calcularea ulterioara a mediei
        media += persoana;

        // 4. De determinat numărul de valori, egale, mai mici sau mai mari ca o valoare indicată.
        if (persoana < varsta)
            maimic++;
        else if (persoana > varsta)
            maimare++;
        else
            egal++;

        // 5. Determinam numarul de persoane cu varsta in limitele indicate
        if ((persoana >= ljos) && (persoana <= lsus))
            interval++;

        /*5. Clasificare:
        1. Copilarie : 0-13 ani
        2. Adolescenta: 13-18 ani
        3. Tinerete: 18-24 ani
        4. Maturitate: 24-60 ani
        5. Varstnic: 60+
        */
        if (persoana < 13)
            copil++;
        else if (persoana < 18)
            adolescent++;
        else if (persoana < 24)
            tanar++;
        else if (persoana < 60)
            matur++;
        else
            varstnic++;
    }

    // 2. De determinat decalajul (diferența între valorile minimă și maximă).
    decalaj = maxim - minim;

    // 3. De determinat media valorilor.
    media = (float)(media / n);

    cout << "1.\t Varsta maxima este: " << maxim << endl;
    cout << "\t Varsta minima este: " << minim << endl;
    cout << "2.\t Decalajul este egal cu: " << decalaj << endl;
    cout << "3.\t Media varstelor este: " << setprecision(4) << media << endl;
    if (maimare > 0)
        cout << "4.\t Numarul de persoane cu varsta mai mare decat " << varsta << " = " << maimare << endl;
    if (maimic > 0)
        cout << "\t Numarul de persoane cu varsta mai mica decat " << varsta << " = " << maimic << endl;
    if (egal > 0)
        cout << "\t Numarul de persoane cu varsta egala cu " << varsta << " = " << egal << endl;
    cout << "5. \t Numarul de persoane cu varsta cuprinsa intre " << ljos << " si " << lsus << " = " << interval << endl;
    cout << "6. \t Clasificare: " << endl;
    if (copil > 0)
        cout << " \t Numarul de copii: " << copil << endl;
    if (adolescent > 0)
        cout << " \t Numarul de adolescenti: " << adolescent << endl;
    if (tanar > 0)
        cout << " \t Numarul tinerilor: " << tanar << endl;
    if (matur > 0)
        cout << " \t Numarul maturilor: " << matur << endl;
    if (varstnic > 0)
        cout << " \t Numarul varstnicilor: " << varstnic << endl;

    return 0;
}
