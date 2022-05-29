#include <bits/stdc++.h>
#include "czodiac.h"

using namespace std;

void Linia(int,int,int, int);

void AranjareAlfabetica()
{
    FILE *f;
    Persoana persoane[100];
    Persoana persoana, aux;
    char prenume[15];
    int i = 0;
    int cit = 0;
    f = fopen("czodiac.in", "rb");
    while(fread(&persoana, sizeof(Persoana), 1, f) > 0)
    {
        persoane[i] = persoana;
        i++;
        cit = i;
    }
    fclose(f);
    for(i = 0; i < cit; i++)
    {
        bool check = true;
        for(int j = 0; j < cit - (i+1); j++)
        {
            int cmp = strcmp(persoane[j].nume, persoane[j+1].nume);
            if (cmp > 0)
            {
                check = false;
                aux = persoane[j];
                persoane[j] = persoane[j+1];
                persoane[j+1] = aux;
            }
        }
        if (check) break;
    }
    f = fopen("czodiac.in", "wb");
    for (i = 0; i < cit; i++)
    {
       fwrite(&persoane[i], sizeof(Persoana), 1, f);
    }
    fclose(f);
    printf("\nAranjarea a fost facuta");
}

void AranjareZodiac()
{
    FILE *f;
    Persoana persoane[100];
    Persoana persoana, aux;
    Persoana berbec[100];
    Persoana taur[100];
    Persoana gemeni[100];
    Persoana rac[100];
    Persoana leu[100];
    Persoana fecioara[100];
    Persoana balanta[100];
    Persoana scorpion[100];
    Persoana sagetator[100];
    Persoana capricorn[100];
    Persoana varsator[100];
    Persoana pesti[100];
    char prenume[15];
    int i = 0;
    int cit = 0;
    f = fopen("czodiac.in", "rb");
    while(fread(&persoana, sizeof(Persoana), 1, f) > 0)
    {
        persoane[i] = persoana;
        i++;
        cit = i;
    }
    fclose(f);
    int ber = 0;
    int tur = 0;
    int gem = 0;
    int rc = 0;
    int lu = 0;
    int fec = 0;
    int bal = 0;
    int sc = 0;
    int sag = 0;
    int cap = 0;
    int vars = 0;
    int pes = 0;
    for(i = 0; i < cit; i++)
    {
        if(strcmp(persoane[i].zodia, "berbec") == 0)
        {
            berbec[ber] = persoane[i];
            ber++;
        }else if(strcmp(persoane[i].zodia,"taur") == 0)
        {
            taur[tur] = persoane[i];
            tur++;
        }else if (strcmp(persoane[i].zodia, "gemeni") == 0)
        {
            gemeni[gem] = persoane[i];
            gem++;
        }else if (strcmp(persoane[i].zodia, "rac") == 0)
        {
            rac[rc] = persoane[i];
            rc++;
        }else if(strcmp(persoane[i].zodia, "leu") == 0)
        {
            leu[lu] = persoane[i];
            lu++;
        }else if(strcmp(persoane[i].zodia, "fecioara") == 0)
        {
            fecioara[fec] = persoane[i];
            fec++;
        }else if(strcmp(persoane[i].zodia, "balanta") == 0)
        {
            balanta[bal] = persoane[i];
            bal++;
        }else if(strcmp(persoane[i].zodia, "scorpion") == 0)
        {
            scorpion[sc] = persoane[i];
            sc++;
        }else if(strcmp(persoane[i].zodia, "sagetator") == 0)
        {
            sagetator[sag] = persoane[i];
            sag++;
        }else if(strcmp(persoane[i].zodia, "capricorn") == 0)
        {
            capricorn[cap] = persoane[i];
            cap++;
        }else if(strcmp(persoane[i].zodia, "varsator") == 0)
        {
            varsator[vars] = persoane[i];
            vars++;
        }else if(strcmp(persoane[i].zodia, "pesti") == 0)
        {
            pesti[pes] = persoane[i];
            pes++;
        }
    }
    f = fopen("czodiac.in", "wb");
    for (i = 0; i < ber; i++)
    {
       fwrite(&berbec[i], sizeof(Persoana), 1, f);
    }
    for (i = 0; i < tur; i++)
    {
       fwrite(&taur[i], sizeof(Persoana), 1, f);
    }
    for (i = 0; i < gem; i++)
    {
       fwrite(&gemeni[i], sizeof(Persoana), 1, f);
    }
    for (i = 0; i < rc; i++)
    {
       fwrite(&rac[i], sizeof(Persoana), 1, f);
    }
    for (i = 0; i < lu; i++)
    {
       fwrite(&leu[i], sizeof(Persoana), 1, f);
    }
    for (i = 0; i < fec; i++)
    {
       fwrite(&fecioara[i], sizeof(Persoana), 1, f);
    }
    for (i = 0; i < bal; i++)
    {
       fwrite(&balanta[i], sizeof(Persoana), 1, f);
    }
    for (i = 0; i < sc; i++)
    {
       fwrite(&scorpion[i], sizeof(Persoana), 1, f);
    }
    for (i = 0; i < sag; i++)
    {
       fwrite(&sagetator[i], sizeof(Persoana), 1, f);
    }
    for (i = 0; i < cap; i++)
    {
       fwrite(&capricorn[i], sizeof(Persoana), 1, f);
    }
    for (i = 0; i < vars; i++)
    {
       fwrite(&varsator[i], sizeof(Persoana), 1, f);
    }
    for (i = 0; i < pes; i++)
    {
       fwrite(&pesti[i], sizeof(Persoana), 1, f);
    }
    fclose(f);
    printf("\nAranjarea a fost facuta");
}

int sumCifre(int nr)
{
    if(nr < 10)
    {
        return nr;
    } else
    {
        return (nr % 10) + (sumCifre(nr / 10));
    }
}

void Completare()
{
   FILE *f;
    Persoana persoane[100];
    Persoana persoana;
    char prenume[15];
    int i = 0;
    int cit = 0;
    int nr = 0;
    f = fopen("czodiac.in", "rb");
    while(fread(&persoana, sizeof(Persoana), 1, f) > 0)
    {
        nr = sumCifre(persoana.dn.zi) + sumCifre(persoana.dn.luna) + sumCifre(persoana.dn.an);
        while (nr > 9)
            nr = sumCifre(nr);
        persoana.numarDestin = nr;
        persoane[i] = persoana;
        i++;
        cit = i;
    }
    fclose(f);
    f = fopen("czodiac.in", "wb");
    for (i = 0; i < cit; i++)
    {
       fwrite(&persoane[i], sizeof(Persoana), 1, f);
    }
    fclose(f);
    printf("\nCaracteristica a fost adaugata");
}
