/**
 * Crispin Klusmann , ifa 92 , 25.02.2020
 *Project: Day of the Year
 *Source-Code of the Header file
 **/

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
    // add Days of the actual month
    tagsum += day;

    return tagsum;
}


/*
 * The function cheacks, weather an input Year is a leap year (in Gregorian Calender). Returns -1 when, year is smaller than
 * 1582 or greater than 2400
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
* read in a valid date
* input pointer for day, month and year
*/
void input_date(int *day, int *month, int *year)
{
    do
    {
        printf("Please input Day: ");
        scanf("%i", day);
        fflush(stdin);
        printf("Please input Month: ");
        scanf("%i", month);
        fflush(stdin);
        printf("Please input Year: ");
        scanf("%i", year);
        fflush(stdin);
    }
    while (exists_date(*day, *month, *year) != 1);
}



/*
* Calculates for a given month and year ( cause leapyear) the maximum days the month has. Month needs to be between 1-12.
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
Cheaks weather a given date is valid, a date before 1582 or after 2400 is invalid
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
 * Returns for a given day the Weekday.
  Calculation from the day of the 01.01 of the given year
  input: day, month and year as integer
  returns  0 = Sunday, 1 = Monday, ... 6 = Saturday
**/
int get_weekday(int day, int month, int year)
{
    int current = day_of_the_year(day, month, year) - 1;
    return (current + _week_day_beginning(year)) % 7;
}


/**
* Calculates the Weekday of the 01.01.year
  input year 
  returns  0 = Sunday, 1 = Monday, ... 6 = Saturday
  Calculation from the  "Gausschen Wochentagsformel", only works for years with 4 digits
**/
int _week_day_beginning(int year)
{
    return ((1 + 5 * ((year - 1) % 4) + 4 * ((year - 1) % 100) + 6 * ((year - 1) % 400)) % 7);
}


/**
    prints the current weekday for a given day
    input: day as int
**/
void _print_weekday(int day)
{
    switch (day)
    {
    default:
        printf("INVALID DAY");
        break;
    case 0:
        printf("Sunday");
        break;
    case 1:
        printf("Monday");
        break;
    case 2:
        printf("Tuesday");
        break;
    case 3:
        printf("Wednesday");
        break;
    case 4:
        printf("Thursday");
        break;
    case 5:
        printf("Friday");
        break;
    case 6:
        printf("Saturday");
        break;

    }
}

/**
    For a given date, calculate the Calender Week
    input day, month and year as integer 
    return calender week as int between 1 and 53 * (see below)   
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
        // when the previous year starts with Thursday or Wednesday (bei Schaltjahren) then
        // Week has 53 KW. Case year is 1582 then it is hard coded cause an error occurs while
        // trying to calculate for a year before 1582
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

