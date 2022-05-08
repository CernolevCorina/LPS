#include <iostream>
#include <math.h>

using namespace std;

bool isPrime(long n)
{
    if (n == 2 || n == 3 || n == 5)
    {
        return true;
    }
    else if (n % 2 == 0 || n % 3 == 0 || n % 5 == 0)
    {
        return false;
    }
    else
    {
        int i = 7;
        while (i <= sqrt(n))
        {
            if (n % i == 0)
            {
                return false;
            }
            i += 2;
        }
    }
    return true;
}

// bool Prim(int n)
// {
//     if (n < 2)
//         return false;
//     for (int k = 2; k <= n / 2; k++)
//         if (n % k == 0)
//         {
//             return false;
//         }

//     return true;
// }

long Invers(long n)
{
    long r = 0;
    while (n > 0)
    {
        r = r * 10 + n % 10;
        n = n / 10;
    }
    return r;
}

int main()
{
    cout << "Proiect nr. 2 elaborat de Cernolev Corina\n";
    cout << "Tema: Numere prime\n";
    int numar, n;
    long lsus, ljos;

    // De verificat daca numarul este prim
    do
    {
        cout << "1.\tDati un numar natural: ";
        cin >> numar;
    } while (numar < 2);
    if (isPrime(numar))
        cout << "\tNumarul " << numar << " este prim\n";
    else
        cout << "\tNumarul " << numar << " nu este prim\n";

    cout << "2.\tDati intervalul\n";
    do
    {
        cout << "\tLimita inferioara: ";
        cin >> ljos;
    } while (ljos < 2);

    cout << "\tLimita superioara: ";
    cin >> lsus;
    cout << "\tNumerele prime din intervalul dat sunt: ";
    for (int i = ljos; i <= lsus; i++)
    {
        if (isPrime(i))
        {
            cout << i << " ";
        }
    }

    cout << "\n3.\tNumerele prime inverse din intervalul dat sunt: ";
    for (long i = ljos; i <= lsus; i++)
    {
        if (isPrime(i) && isPrime(Invers(i)))
        {
            cout << i << " ";
        }
    }

    // Primele n numere prime
    do
    {
        cout << "\n4.\tIntroduceti nr de nr prime: ";
        cin >> n;
    } while (n < 1);
    int k = 2;
    cout << "\tPrimele " << n << " numere prime sunt: ";
    while (n > 0)
    {
        if (isPrime(k))
        {
            cout << k << " ";
            n--;
        }
        k++;
    }

    // Cel mai mare numar prim
    long i = 2147483647;
    while (i > 2)
    {
        if (isPrime(i))
        {
            cout << "\n5.\t" << i << " este cel mai mare numar prim";
            break;
        }
        i--;
    }

    return 0;
}
