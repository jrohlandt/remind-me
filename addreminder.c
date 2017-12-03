#include <stdio.h>
#include <time.h>
#include <string.h>
#include <stdlib.h>

char *monthsAbbreviated[12] = {"jan", "feb", "mar", "apr", "may", "jun", "jul", "aug", "sep", "oct", "nov", "dec"};

int makeMonth(struct tm *dt, char *month_string);


struct reminder {
    int timestamp;
    char *subject;
    char message[100];
};

void displayReminders(char* filename);
int appendReminder(char* filename, struct reminder *r);



int main ()
{
    int day;
    int month;
    char month_string[3];
    int year;
    int hours;
    int minutes;

    int timestamp;
    struct tm dt;
    char buffer[80];
    struct reminder r;
    char *subject = malloc(256);
    // appendReminder(filename, &r);

    printf("Enter date (e.g. 14 apr 2017 13:20) :");
    scanf("%2d %3s %4d %2d:%2d%*[^\n]%*c", &day, month_string, &year, &hours, &minutes );
    printf("String: %2d %3s %4d %02d:%02d\n", day, month_string, year, hours, minutes );
    if (makeMonth(&dt, month_string) == 1) {
        printf("Invalid month!");
        exit(1);
    }

    dt.tm_mday = day;
    dt.tm_year = year-1900;
    dt.tm_hour = hours;
    dt.tm_min = minutes;
    dt.tm_sec = 0;

    printf("TM: %d %d %4d %02d:%02d\n", dt.tm_mday, dt.tm_mon, dt.tm_year, dt.tm_hour, dt.tm_min );


    r.timestamp = mktime(&dt);
    if (r.timestamp == -1) {
        printf("mktime failed");
        exit(1);
    } //else {
        // strftime(buffer, sizeof(buffer), "%c", &dt);
        // printf("Timestamp: %d strftime: %s\n", timestamp, buffer);
//    }
    printf("Subject:");
    fgets(subject, 256, stdin);
    printf("Subject - %s", subject);
    free(subject);
    return 0;
    // scanf("%s", r.subject);

    printf("Message:");
    scanf("%s", r.message);

    printf("Adding %d %s %s", r.timestamp, r.subject, r.message);
    return 0;
}

int makeMonth(struct tm *dt, char *month_string) {
    int i;
    for (i = 0; i < 12; i++) {
        if (strcmp(monthsAbbreviated[i], month_string) == 0) {
            (*dt).tm_mon = i;
            return 0;
        }
    }
    return 1;
}

void displayReminders(char* filename) {

    FILE *fp;
    char *line = NULL;
    size_t len = 0;
    ssize_t read;

    fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Could not open file %s for reading.", filename);
        exit(1);
    }


    while ((read = getline(&line, &len, fp)) != -1) {
        //printf("Line length: %zu \n", read);
        printf("%s", line);
    }
    printf("\n");
    fclose(fp);

    if (line) {
        free(line);
    }
}


int appendReminder(char* filename, struct reminder *r) {
    FILE *fp;
    if ((fp = fopen(filename, "a")) == NULL) {
        printf("Could not open file %s for writing", filename);
        return 1;
    }
    // (*r) dereference pointer, can also use r->datetime for cleaner syntax
    fprintf(fp, "\n%d,%s,%s", (*r).timestamp, (*r).subject, (*r).message);
    fclose(fp);

    return 0;
}
