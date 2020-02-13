#include <stdio.h>
#include <stdlib.h>

/**
 * Calculates the day of the Year
 * input actual day, month and year
 * output day as int from 1 to 366
 **/
int day_of_the_year(int day, int month, int year)
{
    int tagsum = 0;
    // add days of preMonth
    int i = 1;
    for (i = 1; i < month; i++) {
        tagsum += get_days_for_month(i, year);
    }
    // addiere Tage des aktuellen Monats auf
    tagsum += day;

    return tagsum;
}


/*
 *Die Funktion überprüft, ob ein gegebenes Jahr nach den Regeln des gregorianischen Kalender ein Schaltjahr
   ist. Bei Jahreszahlen vor dem Jahr 1582 (und groesser als 2400 wird ein Fehler zurückgegeben.
 *
 * input year as Integer
 * return 0 (no leapyear) 1 (leapyear) -1 (not a correct year) as int
 */
int is_leapyear(int year)
{
    // invalid year
    if (year < 1582 || year > 2400) {
        return -1;
    }
    // check if leap year
    if (year % 4 == 0 && year % 100 != 0 || year % 400 == 0) {
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
int get_days_for_month(int month, int year) {
    int tage[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
    // invalid month or year
    if (month < 1 || month > 12 || -1 == is_leapyear(year)) {
        return -1;
    }
    // when its februrary return 28 or 29 if leapyear
    if (month == 2) {
        return (tage[month - 1] + is_leapyear(year));
    }
    // return day for the month
    else {
        return (tage[month - 1]);
    }
}

/*
Die Funktion überprüft, ob ein eingegebenes Datum gültig ist. Daten vor dem 1.1.1582 sind ungültig, genauso
wie alle Daten nach dem 31.12.2400.
* input day, month, year as integer
* return 1 (correct date) or 0 (invalid date)
*/
int exists_date(int day, int month, int year) {
    //invalid month or year
    if (get_days_for_month(month, year) == -1) {
        return 0;
    }
    // valid month year and day
    if (day <= get_days_for_month(month, year) && day >= 1) {
        return 1;
    }
    // else invalid
    else {
        return 0;
    }

}


/**
    Gibt den Wochentag für den gewählten Tag wieder.
    0 = Sonntag, 1 = Montag, ... 6 = Samstag
    berechnet aus dem Tag des Jahresanfangs
**/
int get_weekday(int day, int month, int year)
{
    int current = day_of_the_year(day, month, year) - 1;
    return (current + _week_day_beginning(year)) % 7;
}


/**
    Die Funktion gibt den Wochentag vom Jahresanfang wieder
    0 = Sonntag, 1 = Montag, 2 = Dienstag, ... 6 = Samstag
    Berechnet nach der Gausschen Jahresanfangsformel, funktioniert nur fuer 4stellige Datumsziffern
**/
int _week_day_beginning(int year)
{
    return ((1 + 5 * ((year - 1) % 4) + 4 * ((year - 1) % 100) + 6 * ((year - 1) % 400)) % 7);
}


/**
    Gibt den gewählten Wochentag im Format von get_weekday() aus.
**/
void _print_weekday(int day)
{
    switch (day)
    {
    default:
        printf("INVALID DAY");
        break;
    case 0:
        printf("Sonntag");
        break;
    case 1:
        printf("Montag");
        break;
    case 2:
        printf("Dienstag");
        break;
    case 3:
        printf("Mittwoch");
        break;
    case 4:
        printf("Donnerstag");
        break;
    case 5:
        printf("Freitag");
        break;
    case 6:
        printf("Samstag");
        break;

    }
}

/**
    Gibt für das gewählte Datum die Kalenderwoche aus.
    Wenn diese nicht ins gwählte Jahr fällt so gebe man 52 / 53 *s.u. zurück.
**/
int get_calender_week(int day, int month, int year)
{
    int currentDays = day_of_the_year(day, month, year);
    int actualDay = get_weekday(day, month, year);
    int startWeekDay = _week_day_beginning(year);
    int MondayWhenWeekOneBegins = (startWeekDay <= 4 && startWeekDay >0 ) ? (2-startWeekDay) : (startWeekDay==0)? 2: (7-startWeekDay+2);
    int calenderWeek = 0;
    for (int i = MondayWhenWeekOneBegins; i <= currentDays; i += 7) {
        calenderWeek++;
    }
      
    if (calenderWeek == 0) {
        // when the previous year starts with Donnerstag or Mittwoch (bei Schaltjahren) then
        // Week has 53 KW. Case year is 1582 then it is hard coded cause an error occurs while
        // trying to calculate fpr a year before 1582
        if (year == 1582) {
            return 53;
        }
        if (_week_day_beginning(year - 1) + is_leapyear(year - 1) == 4) {
            return 53;
        }
        return 52;
    }
    return calenderWeek;
}

