/* Crispin Klusmann , ifa 92 , 14.01.2020
* Tag des Jahres, liest Datum ein und gibt aus um welchen Tag des Jahres es sich handelt
*/

#include <stdio.h>
#include <stdlib.h>

// prueft ob jahr schaltjahr ist und gibt 0 (nein) 1 (ja) zurueck
int isThisASchaltjahr(int jahreszahl)
{
    if(jahreszahl % 4 == 0 && jahreszahl % 100 !=0 || jahreszahl % 400 == 0 ){
            return 1;
    }
    return 0;
}


int main()
{
    // Deklaration und Initialisierung der Variablen
    int Tag;
    int Monat;
    int Jahr;
    int tagsum = 0;
    int tage[12]= {31,28,31,30,31,30,31,31,30,31,30,31};
    int isSchaltjahr = 0;

    do{
        // Einlesen von Tag Monat und Jahr
        printf("Bitte Tag eingeben: ");
        scanf("%i", &Tag);
        printf("Bitte Monat eingeben: ");
        scanf("%i", &Monat);
        printf("Bitte Jahr eingeben: ");
        scanf("%i", &Jahr);
    // solange Tag / Monat / jahr (nach greg. Kalender Einfuerhung)is Quark und kein Schaltjahr beim 29.02
    }while( !((Tag <= tage[Monat-1] && Tag > 0 && Monat <13 && Monat > 0 && Jahr > 1581)) && !(Tag ==29 && Monat == 2 && 1==isThisASchaltjahr(Jahr)));

    isSchaltjahr = isThisASchaltjahr(Jahr);
    // gehe Monate bis zum Vormonat durch und addiere die maximalen Tage auf
    for(int i = 0; i<Monat-1; i++){
        tagsum += tage[i];
    }

    // addiere Tage des aktuellen Monats auf und ggf isSchaltjahr wenn min Maerz
    tagsum += Tag;
    if (Monat > 2)
    {
        tagsum += isSchaltjahr;
    }
    printf("Es ist der %i Tag des Jahres", tagsum);


    return 0;
}
