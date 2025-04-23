#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STUDENTS 100
#define MAX_NAME_LENGTH 100
#define MAX_DEPARTMENT_LENGTH 50

// Structure to represent each student record
struct Student {
    char name[MAX_NAME_LENGTH];
    int rollNo;
    char department[MAX_DEPARTMENT_LENGTH];
};

// Function to read the student records from a file
void readStudentData(const char *filename, struct Student students[], int *studentCount) {
    FILE *file = fopen("student.txt", "r");
    if (file == NULL) {
        printf("Error opening file.\n");
        return;
    }

    // Read each student's information and store it
    while (fscanf(file, " %99[^\n]%d %49s", students[*studentCount].name, &students[*studentCount].rollNo, students[*studentCount].department) != EOF) {
        (*studentCount)++;
    }

    fclose(file);
}

// Bubble Sort: Sorts the students based on name, and if names are the same, by roll number
void bubbleSort(struct Student students[], int studentCount) {
    int swapped;
    for (int i = 0; i < studentCount - 1; i++) {
        swapped = 0; // Reset the swapped flag at the start of each pass
        for (int j = 0; j < studentCount - 1 - i; j++) {
            // Compare names, and if equal, compare roll numbers
            if (strcmp(students[j].name, students[j + 1].name) > 0 || 
                (strcmp(students[j].name, students[j + 1].name) == 0 && students[j].rollNo > students[j + 1].rollNo)) {
                // Swap if the current record is larger
                struct Student temp = students[j];
                students[j] = students[j + 1];
                students[j + 1] = temp;
                swapped = 1; // A swap has occurred
            }
        }
        // If no two elements were swapped, then the array is already sorted
        if (!swapped) {
            break;
        }
    }
}

// Binary Search to find student records by name
void binarySearch(struct Student students[], int studentCount, const char *searchName) {
    int low = 0, high = studentCount - 1;
    int found = 0;

    // Start binary search
    while (low <= high) {
        int mid = low + (high - low) / 2;
        int cmp = strcmp(students[mid].name, searchName);

        if (cmp == 0) {
            // Found a match, print all students with this name
            found = 1;
            int i = mid;
            // Find all occurrences on the left of mid
            while (i >= 0 && strcmp(students[i].name, searchName) == 0) {
                printf("Student Found: %s %d %s\n", students[i].name, students[i].rollNo, students[i].department);
                i--;
            }
            // Find all occurrences on the right of mid
            i = mid + 1;
            while (i < studentCount && strcmp(students[i].name, searchName) == 0) {
                printf("Student Found: %s %d %s\n", students[i].name, students[i].rollNo, students[i].department);
                i++;
            }
            break;
        }
        else if (cmp < 0) {
            low = mid + 1;
        }
        else {
            high = mid - 1;
        }
    }

    if (!found) {
        printf("No student found with the name '%s'.\n", searchName);
    }
}

// Function to display all student records
void displayStudents(struct Student students[], int studentCount) {
    printf("\nStudent Records:\n");
    for (int i = 0; i < studentCount; i++) {
        printf("%s %d %s\n", students[i].name, students[i].rollNo, students[i].department);
    }
}

int main() {
    struct Student students[MAX_STUDENTS];
    int studentCount = 0;
    int option;
    char searchName[MAX_NAME_LENGTH];

    // Read data from the file
    readStudentData("students.txt", students, &studentCount);

    if (studentCount == 0) {
        printf("No student records found in the file.\n");
        return 0;
    }

    do {
        // Display menu
        printf("\nSelect an option:\n");
        printf("1. Bubble Sort\n");
        printf("2. Binary Search\n");
        printf("3. Quit\n");
        printf("Enter your choice: ");
        scanf("%d", &option);

        switch (option) {
            case 1:
                // Sort the students and display the sorted list
                bubbleSort(students, studentCount);
                displayStudents(students, studentCount);
                break;
            case 2:
                // Perform Binary Search for a student by name
                printf("Enter the name of the student to search for: ");
                getchar(); // To consume the newline character left by scanf
                fgets(searchName, MAX_NAME_LENGTH, stdin);
                // Remove newline character from fgets
                searchName[strcspn(searchName, "\n")] = 0;
                binarySearch(students, studentCount, searchName);
                break;
            case 3:
                // Quit the program
                printf("Exiting the program.\n");
                break;
            default:
                printf("Invalid option! Please try again.\n");
        }
    } while (option != 3);

    return 0;
}
