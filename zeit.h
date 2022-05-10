#ifndef ZEIT_H_INCLUDED
#define ZEIT_H_INCLUDED

struct date {
    int day;
    int month;
    int year;
};

int is_leapyear(struct date);
int day_of_the_year(struct date);
struct date input_date(struct date);
int exists_date(struct date); 
int get_days_for_month(struct date); 
int day_of_week(struct date);
int calender_week(struct date);



#endif
