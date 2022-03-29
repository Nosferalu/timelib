
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>


/**
 *
 * @author Alexander Miller
 * This Programm checks the day of the year
 */

int schaltjahr(int year){
    if((year % 4) == 0){
        if((year % 100) == 0){
            if((year % 400) == 0){
                return 1; // Jahr ist durch 4, 100 und 400 teilbar
            } else{  return 0;} // Jahr ist durch 4, 100 aber nicht durch 400 teilbar
        } else {  return 1;} // Jahr ist durch 4 aber nicht durch 100 teilbar
    }else {
        return 0; // Jahr ist nicht durch 4 teilbar
    }
}

    int main() {

        int tage_pro_monat[12] = {31,28,31,30,31,30,31,31,30,31,30,31};
        int valid = 1;

        int tag = 0;
        int monat = 0;
        int jahr = 0;
        int result = 0;
        int i;


            printf("*** Tag des Jahres *** \n");

            printf("Geben Sie das Jahr ein: ");
            scanf("%d", &jahr);

            printf("Geben sie den Monat ein: ");
            scanf("%d", &monat);

            printf("Geben Sie den Tag ein: ");
            scanf("%d", &tag);




            if(schaltjahr(jahr) > 0){
                tage_pro_monat[1] = 29;
            }

            if(monat > 12 || monat < 1){
                printf("Das Jahr hat 12 Monate \n");
                valid = 0;
            }
            if(jahr < 0){
                printf("Vor Christus machen wir hier nicht \n");
                valid = 0;
            }
            if(tag > tage_pro_monat[monat-1] || tag < 0){
                printf("Beim Monatstag passt was nicht \n");
                valid = 0;
            }

            if (valid == 0){
                printf("schade");
                return 1;
            }

            for(i = 0; i < monat-1; i++){
                result = result + tage_pro_monat[i];
            }

            result = result + tag;

        printf("Wir sind bei Tag %d", result);






    }


