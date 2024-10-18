#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void registration(){

    FILE *fp;
    char user[80], pass[80];
    printf("Enter username:");
    scanf("%s", user);

    printf("Enter password:");
    scanf("%s", pass);

    fp =fopen(user, "w");
    if(fp==NULL) {
        printf("Error!\n");
        exit(0);
    }
    fprintf(fp, "username: %s\npassword: %s", user, pass);

    printf("User registered successfully.");

    fclose(fp);
}

void login(){

    char user[80], pass[80], tempuser[80], temppass[80];
    FILE *fp;

    printf("Enter username:");
    scanf("%s", user);

    printf("Enter password:");
    scanf("%s", pass);

    fp =fopen(user,"r");
    if(fp==NULL){
        printf("Error!!\n");
        exit(0);
    }

    fscanf(fp,"username: %s\npassword: %s",tempuser, temppass);

    if(strcmp(user,tempuser) == 0 && strcmp(pass,temppass) == 0){
        printf("Login successfull.\n");
    }
    else{
        printf("Invalid username or password!\n");
    }

    fclose(fp);
}
int main(void) {

    int choice;

    printf("1.Register\n");
    printf("2.Login\n");
    printf("Choose an option (1 or 2):");
    scanf("%d", &choice);

    if(choice==1)
        registration();
    else if(choice==2)
        login();
    else
        printf("Invalid choice!\n");

    return 0;
}
