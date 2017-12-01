#include <stdio.h>
#include <time.h>
#include <string.h>
#include <stdlib.h>
 
char *monthsAbbreviated[12] = {"jan", "feb", "mar", "apr", "may", "jun", "jul", "aug", "sep", "oct", "nov", "dec"};
char *months[12] = {"january", "february", "march", "april", "may", "june", "july", "august", "september", "october", "november", "december"};

int makeMonth(struct tm *dt, char *month_string) {
    int i;
    for (i = 0; i < 12; i++) {
       // printf("%d, abbr: %s, %s\n", i, monthsAbbreviated[i], month_string);
        if (strcmp(monthsAbbreviated[i], month_string) == 0) {
            
            (*dt).tm_mon = i + 1;
         //  printf("return 0");
            return 0;
        } 
        //else if (strcmp(months[i], month_string) == 0) {
          //  (*dt).tm_mon = i + 1;
            //return 0;
       // }
    }
    //printf("return 1");   
    return 1;
}


int main ()
{
    int day;
    int month;
    char month_string[3];
    int year;
    int hours;
    int minutes;

    time_t datetime;
    struct tm dt;
    
    printf("Enter date (e.g. 14 apr 2017 13:20) :");
    scanf("%2d %3s %4d %2d:%2d", &day, month_string, &year, &hours, &minutes );
//return 0;
    printf("%2d %3s %4d %02d:%02d", day, month_string, year, hours, minutes );
//return 0;
// todo fix makemonth it always returns 0
 // printf("mk: %d",makeMonth(&dt, month_string) ); exit;
    if (makeMonth(&dt, month_string) == 1) {
        printf("Invalid month!");
        exit(1);
    }

    dt.tm_mday = day;
    dt.tm_year = year;
    dt.tm_hour = hours;
    dt.tm_min = minutes; 

    //datetime = mktime(&dt);
        
    printf("Date: %02d-%02d-%d %02d:%02d", dt.tm_mday, dt.tm_mon, dt.tm_year, dt.tm_hour, dt.tm_min); 

   // struct date dt;
    
  //  printf("Enter date (e.g. 22 7 2017 13:20");
   // scanf("%d%d%d", &dt.da_day, &dt.da_mon, &dt.da_year );

   // printf("Date: %d-%d-%d\n", dt.da_day, dt.da_mon, dt.da_year);    

    return 0;

    time_t now_timestamp;
    now_timestamp = time(NULL);
    char *today = ctime(&now_timestamp);


    time_t my_timestamp;
    struct tm newtime;
    newtime.tm_year = 2015-1900;
    newtime.tm_mon = 6;
    newtime.tm_mday = 10;
    newtime.tm_hour = 10;
    newtime.tm_min = 3;
    newtime.tm_sec = 5;
    newtime.tm_isdst = 0;
    
    my_timestamp = mktime(&newtime);

    printf("Unix timestamp: %ld ctime: %s\n", now_timestamp, today);
    printf("My unix timestamp: %ld myctime: %s\n", my_timestamp, ctime(&my_timestamp));

    return 0;
}
