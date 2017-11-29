#include <stdio.h>
#include <time.h>

int main ()
{
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
