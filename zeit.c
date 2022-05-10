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
int day_of_the_year(struct date date){

    int result = 0;
    int i;
    int days_for_month = 0;

    days_for_month = get_days_for_month(date);


    for(i = 0; i < date.month-1; i++){
                result = result + days_for_month;
            }

            result = result + date.day;
            return result;
}

/**
 * @brief This function is used for the input of day, month and year
 * 
 * @param day 
 * @param month 
 * @param year 
 */
struct date input_date(struct date date){
  
        printf("Geben Sie das Jahr ein: ");
        scanf("%d", &date.year);

        printf("Geben sie den Monat ein: ");
        scanf("%d", &date.month);

        printf("Geben Sie den Tag ein: ");
        scanf("%d", &date.day);

        return date;



}

/**
 * @brief This function decides of the given year is a leapyear
 * 
 * @param year 
 * @return int 
 */
int is_leapyear(struct date date){

    if(date.year < 1582){
        return -1;
    }

    if((date.year % 4) == 0){
        if((date.year % 100) == 0){
            if((date.year % 400) == 0){
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
int exists_date(struct date date){
    
            if(date.month > 12 ||date.month < 1 || date.year < 1582 || date.year > 2400 || date.day < 1){
                return 0;
            }

            if(date.day > get_days_for_month(date) || date.day < 0){
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
int get_days_for_month(struct date date){
    int tage_pro_monat[12] = {31,28,31,30,31,30,31,31,30,31,30,31};

    if(is_leapyear(date) > 0){
                tage_pro_monat[1] = 29;
            }
    printf("%d \n", tage_pro_monat[date.month -1] );
    return tage_pro_monat[date.month -1];

}

/**
 * @brief returns the day of the week (1 = monday, 7 = sunday)
 * 
 * @param day 
 * @param month 
 * @param year 
 * @return int 
 */
int day_of_week(struct date date){
    if (date.month < 3) {
      date.month += 12;
      date.year--;
   }
   return (((13*date.month+3)/5 + date.day + date.year + date.year/4 - date.year/100 + date.year/400) % 7) +1;
}


