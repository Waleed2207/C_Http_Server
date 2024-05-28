#include <stdio.h>
#include <sys/types.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <time.h>
#include <stdbool.h>

#define MAX_LINE_LENGTH 100
#define PASSWORD_LENGTH 8

struct User {
    char username[MAX_LINE_LENGTH];
    char password[MAX_LINE_LENGTH];
};

void registerUser() {
    struct User newUser;
    printf("Enter Username: ");
    scanf("%s", newUser.username);
    printf("Enter Password: ");
    scanf("%s", newUser.password);

    FILE *file = fopen("users.txt", "a");
    if (file == NULL) {
        printf("Error opening file.\n");
        return;
    }
    fprintf(file, "%s %s\n", newUser.username, newUser.password);
    fclose(file);
    printf("User registered successfully!\n");
}

void print_Data() {
    char buff[32];
    FILE *fp;
    printf("\nUser Data:\n");
    fp = fopen("users.txt", "r");

    while (fgets(buff, 32, fp)) {
        fputs(buff, stdout);
    }
    printf("\n");

    fclose(fp);
}

bool authenticate(const char *userName, const char *password) {
    FILE *file = fopen("users.txt", "r");
    if (file == NULL) {
        printf("Error opening file.\n");
        return false;
    }

    struct User user;
    while (fscanf(file, "%s %s", user.username, user.password) == 2) {
        if (strcmp(user.username, userName) == 0 && strcmp(user.password, password) == 0) {
            fclose(file);
            return true;
        }
    }

    fclose(file);
    return false;
}

int login() {
    bool auth = false;
    char password[PASSWORD_LENGTH] = {0};
    char UserName[PASSWORD_LENGTH] = {0};

    printf("Enter Username:\n> ");
    scanf("%s", UserName);
    printf("Enter Password:\n> ");
    // scanf("%s", password);
    getchar();
    gets(password);

    if (authenticate(UserName, password)) {
        auth = true;
    }

    if (auth) {
        return 1;
    }
    return -1;
}

void start_forever() {
    int choose;
    while (true) {
        printf("\n1. Login\n2. Register\n3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choose);

        switch (choose) {
            case 1:
                if (login() == 1) {
                    print_Data();
                } else {
                    printf("You are not authenticated.\n");
                }
                break;
            case 2:
                registerUser();
                break;
            case 3:
                printf("Exiting...\n");
                return;  
            default:
                printf("Invalid choose. Please try again.\n");
                break;
        }
    }
}

int main(int argc, char const *argv[]) {
    start_forever();
    return 0;
}
