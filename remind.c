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

void displayReminders(char* filename);
int appendReminder(char* filename, struct reminder *r);

int main(int argc, char **argv)
{    
    char *ADD = "a";
    char *SHOW = "s";
    char *filename = "data.csv";

    if (argc > 1 && argc < 4 && strcmp(argv[1],  "s") != 0) {
        printf("Too few arguments.\n Usage: remindme \"2017-11-28\" \"Don\'t forget to finish task.\"");        
        exit(1);
    }
        
    if (strcmp(argv[1], ADD) == 0) {
        struct reminder r;
        r.datetime = argv[2];
        r.subject = "Reminder - ";
        r.message = argv[3];

        appendReminder(filename, &r);
        displayReminders(filename);
    }
   
    if (strcmp(argv[1], SHOW) == 0) {
        displayReminders(filename);
    }

    return 0;    
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
    fprintf(fp, "\n%s,%s,%s", (*r).datetime, (*r).subject, (*r).message);   
    fclose(fp);

    return 0;
}


