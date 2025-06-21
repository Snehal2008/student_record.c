#include <stdio.h>
#include <stdlib.h>

struct Student {
    char name[50];
    int roll;
    float marks;
};

void addStudent() {
    struct Student s;
    FILE *f = fopen("students.txt", "a");

    if (f == NULL) {
        printf("Error opening file!\n");
        return;
    }

    printf("Enter student name: ");
    scanf(" %[^\n]s", s.name);
    printf("Enter roll number: ");
    scanf("%d", &s.roll);
    printf("Enter marks: ");
    scanf("%f", &s.marks);

    fprintf(f, "%s %d %.2f\n", s.name, s.roll, s.marks);
    fclose(f);
    printf("Student added successfully!\n\n");
}

void displayStudents() {
    struct Student s;
    FILE *f = fopen("students.txt", "r");

    if (f == NULL) {
        printf("No records found!\n");
        return;
    }

    printf("\n--- Student Records ---\n");
    while (fscanf(f, " %[^\n] %d %f", s.name, &s.roll, &s.marks) != EOF) {
        printf("Name: %s | Roll: %d | Marks: %.2f\n", s.name, s.roll, s.marks);
    }

    fclose(f);
    printf("\n");
}

int main() {
    int choice;

    while (1) {
        printf("1. Add Student\n2. Display Students\n3. Exit\nEnter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: addStudent(); break;
            case 2: displayStudents(); break;
            case 3: exit(0);
            default: printf("Invalid choice!\n");
        }
    }

    return 0;
}
