/**
 * Crispin Klusmann , ifa 92 , 25.02.2020
 * Header-File of the time library
 **/

#pragma once

#ifndef HEADER_FILE
#define HEADER_FILE
struct date{
  int day;
  int month;
  int year;
};



int day_of_the_year(struct date);
int is_leapyear(int year);
int get_weekday(struct date);
int exists_date(struct date);
int get_days_for_month(int month, int year);
int get_weekday(struct date);
struct date input_date();

#endif
