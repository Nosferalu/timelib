#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>
#include "zeit.h"

/**
 * @brief This function calculates the day of the year
 * 
 * @param day 
 * @param month 
 * @param year 
 * @return int 
 */
int day_of_the_year(int day, int month, int year){

    int result = 0;
    int i;
    int days_for_month = 0;

    days_for_month = get_days_for_month(month, year);


    for(i = 0; i < month-1; i++){
                result = result + days_for_month;
            }

            result = result + day;
            return result;
}

/**
 * @brief This function is used for the input of day, month and year
 * 
 * @param day 
 * @param month 
 * @param year 
 */
void input_date(int *day, int *month, int *year){
  
   printf("Geben Sie das Jahr ein: ");
            scanf("%d", year);

            printf("Geben sie den Monat ein: ");
            scanf("%d", month);

            printf("Geben Sie den Tag ein: ");
            scanf("%d", day);



}

/**
 * @brief This function decides of the given year is a leapyear
 * 
 * @param year 
 * @return int 
 */
int is_leapyear(int year){

    if(year < 1582){
        return -1;
    }

    if((year % 4) == 0){
        if((year % 100) == 0){
            if((year % 400) == 0){
                return 1; // Jahr ist ein Schaltjahr
            } else{  return 0;} // Jahr ist kein Schaltjahr
        } else {  return 1;} // Jahr ist ein Schaltjahr
    }else {
        return 0; // Jahr ist kein Schaltjahr
    }
}    

/**
 * @brief This function calculates if the given year exists
 * 
 * @param day 
 * @param month 
 * @param year 
 * @return int 
 */
int exists_date(int day, int month, int year){
    
            if(month > 12 || month < 1 || year < 1582 || year > 2400 || day < 1){
                return 0;
            }

            if(day > get_days_for_month(month, year) || day < 0){
                return 0;
            }

            return 1;


}

/**
 * @brief Get the days for month object
 * 
 * @param month 
 * @param year 
 * @return int 
 */
int get_days_for_month(int month, int year){
    int tage_pro_monat[12] = {31,28,31,30,31,30,31,31,30,31,30,31};

    if(is_leapyear(year) > 0){
                tage_pro_monat[1] = 29;
            }
    
    return tage_pro_monat[month];

}

int day_of_week(int day, int month, int year){
    if (month < 3) {
      month += 12;
      year--;
   }
   return (((13*month+3)/5 + day + year + year/4 - year/100 + year/400) % 7);
}


