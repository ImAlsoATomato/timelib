
/**
 * Crispin Klusmann , ifa 92 , 02.03.2020
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

    struct date idate = input_date();

    printf("Day of the Year: %i\n", day_of_the_year(idate));
    printf("Weekday:");
    _print_weekday(get_weekday(idate));
    printf("\n Calenderweek of the Day: %i \n", get_calender_week(idate));
    return 0;
}
