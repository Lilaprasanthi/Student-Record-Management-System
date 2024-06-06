#include <stdio.h>
#include <string.h>
#define MAX_STUDENTS 92
struct Student {
    int roll;
    char name[15];
    char branch[4];
    char address[10];
};

void add(struct Student s[], int *i);
void delete(struct Student s[], int *i);
void display(struct Student s[], int i);
void displayAll(struct Student s[], int i);

int main() {
    struct Student s[MAX_STUDENTS];
    int i = 0;
    int input;

    while (1) {
        printf("Student Record Management System\n");
        printf("__________________________________\n");
        printf("1. Add student details:\n");
        printf("2. Delete student details:\n");
        printf("3. Display particular student details:\n");
        printf("4. Display all students details:\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &input);

        switch (input) {
        case 1:
            if (i < MAX_STUDENTS) {
                add(s, &i);
            } else {
                printf("Student list is full!\n");
            }
            break;
        case 2:
            delete(s, &i);
            break;
        case 3:
            display(s, i);
            break;
        case 4:
            displayAll(s, i);
            break;
        case 5:
            printf("Exit from the application.\n");
            return 0;
        default:
            printf("Invalid choice. Please try again.\n");
        }
    }
    return 0;
}

void add(struct Student s[], int *i) {
    printf("Enter roll no: ");
    scanf("%d", &s[*i].roll);
    printf("Enter name: ");
    scanf("%s", s[*i].name);
    printf("Enter branch: ");
    scanf("%s", s[*i].branch);
    printf("Enter address: ");
    scanf("%s", s[*i].address);
    printf("Added student details are: %d %s %s %s\n", s[*i].roll, s[*i].name, s[*i].branch, s[*i].address);
    (*i)++;
}
void delete(struct Student s[], int *i) {
    int roll, j, found = 0;
    printf("Enter roll no to delete: ");
    scanf("%d", &roll);

    for (j = 0; j < *i; j++) {
        if (s[j].roll == roll) {
            printf("Deleted student details: %d %s %s %s\n", s[j].roll, s[j].name, s[j].branch, s[j].address);
            s[j] = s[*i - 1]; 
            (*i)--;
            found = 1;
            break;
        }
    }
    if (!found) {
        printf("Student does not exist.\n");
    }
}

void display(struct Student s[], int i) {
    int roll, j, found = 0;
    printf("Enter roll no to display: ");
    scanf("%d", &roll);

    for (j = 0; j < i; j++) {
        if (s[j].roll == roll) {
            printf("Student details are : %d %s %s %s\n", s[j].roll, s[j].name, s[j].branch, s[j].address);
            found = 1;
            break;
        }
    }
    if (!found) {
        printf("Student does not exist.\n");
    }
}

void displayAll(struct Student s[], int i) {
    int j;
    if (i == 0) {
        printf("No student records to display.\n");
    } else {
        for (j = 0; j < i; j++) {
            printf("Student %d details: %d %s %s %s\n", j + 1, s[j].roll, s[j].name, s[j].branch, s[j].address);
        }
    }
}
