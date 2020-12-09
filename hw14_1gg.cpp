#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

typedef
struct Seminar {
    char subject[25];
    char teacher[25];
    unsigned int group_num;
    unsigned int hours;
    unsigned int classroom;

} Seminar;

int input(Seminar* x) {
    Seminar res;
    printf("Subject: ");
    scanf("%s", &res.subject);

    printf("Teacher: ");
    scanf("%s", &res.teacher);

    printf("Group number: ");
    scanf("%u", &res.group_num);

    printf("Hours: ");
    scanf("%u", &res.hours);

    printf("Classroom: ");
    scanf("%u", &res.classroom);

    *x = res;
    return 0;
}

void output(const Seminar x) {
    printf("\nSubject: %s\tTeacher: %s\nGroup number: %u\tHours: %u\tClassroom: %u\n", x.subject, x.teacher, x.group_num, x.hours, x.classroom);
}

int main() {
    Seminar x;
    input(&x);
    output(x);
}