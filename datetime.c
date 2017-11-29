#include <stdio.h>
#include <time.h>
#include <string.h>

int main ()
{

    char month_string[3];
    char *months[12] = {"jan", "feb", "mar", "apr", "may", "jun", "jul", "aug", "sep", "oct", "nov", "dec"};

    struct tm dt;
    
    printf("Enter date (e.g. 14 apr 2017 13:20) :");
    scanf("%d %3s %d %d:%d", &dt.tm_mday, month_string, &dt.tm_year, &dt.tm_hour, &dt.tm_min );

    int i;
    for (i = 0; i < 12; i++) {
        if (strcmp(months[i], month_string) == 0) {
            dt.tm_mon = i + 1;
            break;
        }
    }

    
    printf("Date: %02d-%02d-%d %02d:%02d\n", dt.tm_mday, dt.tm_mon, dt.tm_year, dt.tm_hour, dt.tm_min); 

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
