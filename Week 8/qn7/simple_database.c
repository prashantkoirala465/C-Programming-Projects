#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define DATABASE_FILE "database.txt"

typedef struct {
    int id;
    char name[100];
    int age;
} Record;

void addRecord();
void searchRecord();
void deleteRecord();
void listRecords();

int main() {
    int choice;

    while (1) {
        printf("\nSimple Database System\n");
        printf("1. Add Record\n");
        printf("2. Search Record\n");
        printf("3. Delete Record\n");
        printf("4. List All Records\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addRecord();
                break;
            case 2:
                searchRecord();
                break;
            case 3:
                deleteRecord();
                break;
            case 4:
                listRecords();
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}

void addRecord() {
    FILE *file = fopen(DATABASE_FILE, "a");
    if (file == NULL) {
        printf("Error opening file!\n");
        return;
    }

    Record record;
    printf("Enter ID: ");
    scanf("%d", &record.id);
    printf("Enter Name: ");
    scanf("%s", record.name);
    printf("Enter Age: ");
    scanf("%d", &record.age);

    fprintf(file, "%d %s %d\n", record.id, record.name, record.age);
    fclose(file);

    printf("Record added successfully!\n");
}

void searchRecord() {
    FILE *file = fopen(DATABASE_FILE, "r");
    if (file == NULL) {
        printf("Error opening file!\n");
        return;
    }

    int id;
    printf("Enter ID to search: ");
    scanf("%d", &id);

    Record record;
    int found = 0;
    while (fscanf(file, "%d %s %d", &record.id, record.name, &record.age) != EOF) {
        if (record.id == id) {
            printf("Record found: ID: %d, Name: %s, Age: %d\n", record.id, record.name, record.age);
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("No record found with ID %d.\n", id);
    }

    fclose(file);
}

void deleteRecord() {
    FILE *file = fopen(DATABASE_FILE, "r");
    if (file == NULL) {
        printf("Error opening file!\n");
        return;
    }

    int id;
    printf("Enter ID to delete: ");
    scanf("%d", &id);

    FILE *tempFile = fopen("temp.txt", "w");
    if (tempFile == NULL) {
        printf("Error opening temporary file!\n");
        fclose(file);
        return;
    }

    Record record;
    int found = 0;
    while (fscanf(file, "%d %s %d", &record.id, record.name, &record.age) != EOF) {
        if (record.id != id) {
            fprintf(tempFile, "%d %s %d\n", record.id, record.name, record.age);
        } else {
            found = 1;
        }
    }

    fclose(file);
    fclose(tempFile);

    if (found) {
        remove(DATABASE_FILE);
        rename("temp.txt", DATABASE_FILE);
        printf("Record deleted successfully!\n");
    } else {
        remove("temp.txt");
        printf("No record found with ID %d.\n", id);
    }
}

void listRecords() {
    FILE *file = fopen(DATABASE_FILE, "r");
    if (file == NULL) {
        printf("Error opening file!\n");
        return;
    }

    printf("List of Records:\n");
    Record record;
    while (fscanf(file, "%d %s %d", &record.id, record.name, &record.age) != EOF) {
        printf("ID: %d, Name: %s, Age: %d\n", record.id, record.name, record.age);
    }

    fclose(file);
}
