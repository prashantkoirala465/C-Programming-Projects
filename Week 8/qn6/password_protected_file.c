#include <stdio.h>
#include <string.h>
#define PASSWORD "prashant511"
//Written by: Prashant Koirala
int main() {
    char enteredPassword[100];
    char filename[100];
    char content[1000];
    FILE *file;
    printf("Enter the password: ");
    scanf("%s", enteredPassword);
    if (strcmp(enteredPassword, PASSWORD) == 0) {
        printf("Enter the filename to write to: ");
        scanf("%s", filename);
        file = fopen(filename, "w");
        if (file == NULL) {
            printf("Error opening file!\n");
            return 1;
        }
        printf("Enter the content to write to the file: ");
        getchar();
        fgets(content, sizeof(content), stdin);
        fputs(content, file);
        fclose(file);
        printf("Content written to %s successfully.\n", filename);
    } else {
        printf("Incorrect password. Access denied.\n");
    }
    return 0;
}
