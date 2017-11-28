// 1. take a reminder (struct) and append it to a file.
// 2. then read the file and print it's contents to console.

// 3. next step take user input from terminal and append to file.
// 4. check if current system time matches any reminders in the file and then display a desktop notification for each one.

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

struct reminder {
    char *datetime;
    char *subject;
    char *message;
};

void displayReminders(char* filename) {

  FILE *fp;
  fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Could not open file %s for reading.", filename);
        exit(1);
    }
  
    char s[100];
    while (!feof(fp)) {
        fscanf(fp, " %*s %99[^\n]", s);
        printf("%s\n", s);
     } 
    
    fclose(fp);
} 

int main(int argc, char **argv)
{
    printf("%s %s %s", argv[0], argv[1], argv[2]); 
    return 4;

    char *filename = "data.csv";
    struct reminder r;
    r.datetime = "2017-11-26 10:25";
    r.subject = "Dont forget!";
    r.message = "Take out the trash again.";

    char subject[30] = "Reminder: ";
    strcat(subject, r.subject);

    FILE *fp;

    if ((fp = fopen(filename, "a")) == NULL) {
        printf("Could not open file %s for writing", filename);
        exit(1);
    }
    //fprintf(fp, "\n%s,%s,%s", r.datetime, subject, r.message);   
    
    fclose(fp);

    displayReminders(filename);
    //return 0;  

    

    return 0;    
}
