#ifndef VSPORTIV_H_INCLUDED
#define VSPORTIV_H_INCLUDED
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
    int numarDestin[21];
};

#endif // VSPORTIV_H_INCLUDED
