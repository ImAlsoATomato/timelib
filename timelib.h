/**
 * Crispin Klusmann , ifa 92 , 13.02.2020
 *Tag des Jahres, liest Datum ein und gibt aus um welchen Tag des Jahres es sich handelt
 * Header-File
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
