/**
 * Crispin Klusmann , ifa 92 , 25.02.2020
 * Header-File of the time library
 **/

#pragma once

#ifndef HEADER_FILE
#define HEADER_FILE


int day_of_the_year(int day, int month, int year);
int is_leapyear(int year);
int get_weekday(int day, int month, int year);
int exists_date(int day, int month, int year);
int get_days_for_month(int month, int year);
int get_weekday(int day, int month, int year);

#endif
