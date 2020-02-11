/**
 * Crispin Klusmann , ifa 92 , 11.02.2020
 *Tag des Jahres, liest Datum ein und gibt aus um welchen Tag des Jahres es sich handelt
 **/

#include <stdio.h>
#include <stdlib.h>


/*
*Die Funktion überprüft, ob ein gegebenes Jahr nach den Regeln des gregorianischen Kalender ein Schaltjahr
  ist. Bei Jahreszahlen vor dem Jahr 1582 wird ein Fehler zurückgegeben.
*
* input year as Integer
* return 0 (no leapyear) 1 (leapyear) -1 (not a correct year) as int
*/
int is_leapyear(int year)
{
    // invalid year
    if(year < 1582 || year > 2400){
        return -1;
    }
    // check if leap year
    if(year % 4 == 0 && year % 100 !=0 || year % 400 == 0 ){
            return 1;
    }
    return 0;
}
/*
Die Funktion bestimmt für einen gegebenen Monat eines gegebenen Jahres, wie viele Tage der Monat hat. Der
Wert des Monats muss zwischen 1 und 12 liegen. Schaltjahre werden berücksichtigt.
* input month as Integer year as Integer
* return 28-31 (days of the month) or -1 invalid input as Integer
*/
int get_days_for_month(int month, int year){
    int tage[12]= {31,28,31,30,31,30,31,31,30,31,30,31};
    // invalid month or year
    if(month<1 || month > 12 || -1==is_leapyear(year)){
        return -1;
    }
    // when its februrary return 28 or 29 if leapyear
    if(month == 2){
        return (tage[month-1] + is_leapyear(year));
    }
    // return day for the month
    else{
        return (tage[month-1]);
    }
}

/*
Die Funktion überprüft, ob ein eingegebenes Datum gültig ist. Daten vor dem 1.1.1582 sind ungültig, genauso
wie alle Daten nach dem 31.12.2400.
* input day, month, year as integer
* return 1 (correct date) or 0 (invalid date)
*/
int exists_date(int day, int month, int year){
    //invalid month or year
if(get_days_for_month(month,year)==-1){
    return 0;
}
    // valid month year and day
if(day<=get_days_for_month(month,year)&& day>=1){
    return 1;
}
    // else invalid
else{
    return 0;
}

}
/**
 * Calculates the day of the Year
 * input actual day, month and year
 * output day as int from 1 to 366
 **/
int day_of_the_year(int day, int month, int year)
{
    int tagsum = 0;
    // add days of preMonth
    int i=1;
    for(i = 1; i<month; i++){
        tagsum += get_days_for_month(i, year);
    }
  // addiere Tage des aktuellen Monats auf
    tagsum += day;

    return tagsum;
}

/*
 * reads day , month , year from user as input and
 * prints out the day of the year
 */
int main()
{
    int Tag=0;
    int Monat=0;
    int Jahr=0;
    // Read in day month and year // the day Array is neccassary to check weather it is a correct day in
    do{
        // Einlesen von Tag Monat und Jahr
        printf("Bitte Tag eingeben: ");
        scanf("%d", &Tag);
        fflush(stdin);
        printf("Bitte Monat eingeben: ");
        scanf("%d", &Monat);
        fflush(stdin);
        printf("Bitte Jahr eingeben: ");
        scanf("%d", &Jahr);
        fflush(stdin);
    // day exists?
    }while(!exists_date(Tag, Monat, Jahr));

    printf("Tag des Jahres: %i\n", day_of_the_year(Tag, Monat, Jahr));
    return 0;
}

