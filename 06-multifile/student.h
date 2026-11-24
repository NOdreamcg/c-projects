#ifndef STUDENT_H
#define STUDENT_H

struct student {                         
    char name[20];
    int score;
};

void input(struct student *a, int n);     
int  save (struct student *a, int n);
int  load (struct student *a, int n);
void print(struct student *a, int n);

#endif