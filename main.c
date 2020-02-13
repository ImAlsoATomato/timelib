
/**
 * Crispin Klusmann , ifa 92 , 13.02.2020
 *Tag des Jahres, liest Datum ein und gibt aus um welchen Tag des Jahres es sich handelt
 **/

#include <stdio.h>
#include <stdlib.h>
#include "timelib.h"

int main()
{
    int Tag = 0;
    int Monat = 0;
    int Jahr = 0;
    // Read in day month and year // the day Array is neccassary to check weather it is a correct day in
    do {
        // Einlesen von Tag Monat und Jahr
        printf("Bitte Tag eingeben: ");
        scanf_s("%d", &Tag);
        fflush(stdin);
        printf("Bitte Monat eingeben: ");
        scanf_s("%d", &Monat);
        fflush(stdin);
        printf("Bitte Jahr eingeben: ");
        scanf_s("%d", &Jahr);
        fflush(stdin);
        // day exists?
    } while (!exists_date(Tag, Monat, Jahr));

    printf("Tag des Jahres: %i\n", day_of_the_year(Tag, Monat, Jahr));
    printf("Wochentag des Jahres :");
    _print_weekday(get_weekday(Tag, Monat, Jahr));
    printf("\n Kalenderwoche des Tages: %i \n", get_calender_week(Tag, Monat, Jahr));
    return 0;
}
