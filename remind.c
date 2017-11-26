// 1. take a reminder (struct) and append it to a file

#include <stdio.h>

struct reminder {
    char *datetime;
    char *subject;
    char *message;
};

int main(void)
{
    struct reminder r;
    r.datetime = "2017-11-26 10:25";
    r.subject = "Reminder - Dont forget!";
    r.message = "Take out the trash";

    printf("%s | %s | %s\n", r.datetime, r.subject, r.message);

    return 0;    
}
