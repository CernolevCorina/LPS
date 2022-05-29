#ifndef CZODIAC_H_INCLUDED
#define CZODIAC_H_INCLUDED
struct Data
{
    int zi;
    int luna;
    int an;
};
struct Persoana
{
    int id;
    char nume[31];
    Data dn;
    char zodia[21];
    char piatra[20];
    int numereNorocoase[3];
    int numarDestin;
};

#endif // CZODIAC_H_INCLUDED
