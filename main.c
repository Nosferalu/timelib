
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>
#include "zeit.h"


/**
 *
 * @author Alexander Miller
 * This Programm checks the day of the year
 */

int main() {
    int result = 0;
    int result2 = 0;
    struct date date;

    date.year = 0;
    date.month = 0;
    date.day = 0;

     printf("*** Tag des Jahres *** \n");

     do{
         date = input_date(date);
     }while(exists_date(date) < 1);

    result = day_of_the_year(date);
    result2 = day_of_week(date);
    

    printf("Result: %d \n", result);

    return 0;

    }

