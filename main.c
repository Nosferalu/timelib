
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>


/**
 *
 * @author Alexander Miller
 * This Programm checks the day of the year
 */

int is_leapyear(int year); //done
int day_of_the_year(int day, int month, int year);
void input_date(int *day, int *month, int *year); //done
int exists_date(int day, int month, int year); //done
int get_days_for_month(int month, int year); //done

    int main() {
    int day = 0;
    int month = 0;
    int year = 0;
    int result = 0;

     printf("*** Tag des Jahres *** \n");

     do{
         input_date(&day, &month, &year);
     }while(exists_date(day, month, year) < 1);

    result = day_of_the_year(day, month, year);

    printf("Result: %d \n", result);

    }

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

void input_date(int *day, int *month, int *year){
  
   printf("Geben Sie das Jahr ein: ");
            scanf("%d", year);

            printf("Geben sie den Monat ein: ");
            scanf("%d", month);

            printf("Geben Sie den Tag ein: ");
            scanf("%d", day);



}

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

int exists_date(int day, int month, int year){
    
            if(month > 12 || month < 1 || year < 1582 || year > 2400 || day < 1){
                return 0;
            }

            if(day > get_days_for_month(month, year) || day < 0){
                return 0;
            }

            return 1;


}


int get_days_for_month(int month, int year){
    int tage_pro_monat[12] = {31,28,31,30,31,30,31,31,30,31,30,31};

    if(is_leapyear(year) > 0){
                tage_pro_monat[1] = 29;
            }
    
    return tage_pro_monat[month];

}

