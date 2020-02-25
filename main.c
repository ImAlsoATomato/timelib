
/**
 * Crispin Klusmann , ifa 92 , 25.02.2020
 * Day of the year, read in Date from User and return the Day of the Year and the Weekday, calender week
 **/

#include <stdio.h>
#include <stdlib.h>
#include "timelib.h"

/*
* main function. Get Input from user and calculate output
* input: nothing
* return: int as possible Errorcode
*/
int main()
{
    int iDay = 0;
    int iMonth = 0;
    int iYear = 0;
    // Read in day month and year // the day Array is neccassary to check weather it is a correct day in
    do {
        // Read in Day, Month and year
        printf("Please input day: ");
        scanf_s("%d", &iDay);
        fflush(stdin);
        printf("Please input Month: ");
        scanf_s("%d", &iMonth);
        fflush(stdin);
        printf("Please input Year: ");
        scanf_s("%d", &iYear);
        fflush(stdin);
        // day exists?
    } while (!exists_date(Tag, Monat, Jahr));

    printf("Day of the Year: %i\n", day_of_the_year(Tag, Monat, Jahr));
    printf("Weekday:");
    _print_weekday(get_weekday(Tag, Monat, Jahr));
    printf("\n Calenderweek of the Day: %i \n", get_calender_week(Tag, Monat, Jahr));
    return 0;
}
