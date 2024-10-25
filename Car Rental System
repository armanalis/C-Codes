#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_Cars 80
#define MAX_Users 80

typedef struct {
    int CarID;
    char model[80];
    int hourly_rate;
    int daily_rate;
    int available;//if car is available then it is 1, if it is not available it equals to 0.
}car;

typedef struct {
    char username[80];
    char password[80];
}user;

double time_current() {
    time_t seconds;
    seconds = time(NULL);// means that the number of seconds since the epoch (1 Jan 1970)
    return seconds;
}

double calculateHours(time_t start, time_t end) {
    return difftime(end, start) / 3600.0;
}

void addCar(car cars[], int *totalcars){

    if(*totalcars>MAX_Cars){
        printf("Car limit reached!\n");
        return;
    }

    car newcar;
    printf("Add a new car into the system. But first provide some details");
    printf("\nEnter the car model:");
    scanf("%c", cars->model);
    printf("\nEnter the car ID:");
    scanf("%d", &cars->CarID);
    printf("\nEnter the car rate per hour:");
    scanf("%d", &cars->hourly_rate);
    printf("\nEnter the car rate per day:");
    scanf("%d", &cars->daily_rate);
    cars->available = 1;

    cars[(*totalcars)++] = newcar;
    printf("Car added successfully!\n");
}

void viewCars(car cars[], int totalcars){

    printf("\nAvailable cars:\n");
    for(int i=0; i<totalcars; i++){
        printf("ID: %d, Model: %s, Rate per hour: %.2f, Rate per day: %.2f Availability; %s\n",cars[i].CarID, cars[i].model, cars[i].hourly_rate, cars[i].daily_rate, cars[i].available );
        if (cars[i].available)
            printf("Yes");
        else
            printf("No");
    }
}

void rentcar(car cars[], int totalcars){

    int id;
    printf("\nEnter car ID to rent:");
    scanf("%d", &id);

    for(int i=0; i<totalcars; i++){
        if(cars[i].CarID == id && cars[i].available){
            cars[i].available = 0;
            time_t startTime = time_current();
            printf("Car rented successfully! Start time logged.\n");
            return;
        }
    }
    printf("Car not available or invalid ID.\n");
}

void returncar(car cars[], int totalcars){

    int id;
    printf("\nEnter Car ID to return:");
    scanf("%d", &id);

    for(int i=0; i<totalcars; i++){
        if (cars[i].CarID == id && !cars[i].available) {
            time_t startTime, endTime;
            printf("Enter rental start time (seconds since epoch): ");
            scanf("%ld", &startTime);
            endTime = time_current();

            double hours = calculateHours(startTime, endTime);
            double fare = hours * cars[i].hourly_rate;
            cars[i].available = 1;

            printf("Car returned successfully! Total fare: $%.2f\n", fare);
            return;
        }
    }
    printf("Car not rented or invalid ID.\n");
}

void adminmenu(car cars[], int *totalcars, user users[], int totalusers){
    int choice;
    do{
        printf("Admin Menu:\n");
        printf("1. Add Car:\n");
        printf("2. View Cars:\n");
        printf("3. Exit\n");
        printf("3. Enter your choice:\n");
        scanf("%d", &choice);

        switch(choice){
            case 1:
                addCar(&cars, &totalcars);
                break;
            case 2:
                viewCars(cars, *totalcars);
                break;
            case 3:
                printf("Exiting admin menu.\n");
                break;
            default:
            printf("Invalid choice try again.\n");
        }
    }while(choice!=3);
}

void adminlogin(car cars[], int *totalcars, user users[], int totalusers){

    char username[80], password[80];

    printf("Admin Login\n");
    printf("username");
    scanf("%s", username);
    printf("password");
    scanf("%s", password);

    if(strcmp(username, "admin") == 0 && strcmp(password, "admin123") == 0){
        printf("\nAdmin login successful!\n");
        adminmenu(cars, totalcars, users, totalusers);
    }
    else{
        printf("Invalid login!\n");
    }
}

void usermenu(car cars[], int totalcars, user users[], int totalusers){

    int choice;

    do {
        printf("\nUser Menu:\n");
        printf("1. View Available Cars\n");
        printf("2. Rent a Car\n");
        printf("3. Return a Car\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice){
            case 1:
                viewCars(cars, totalcars);
                break;
            case 2:
                rentcar(cars, totalcars);
                break;
            case 3:
                returncar(cars, totalcars);
                break;
            case 4:
                printf("Exiting user menu.\n");
                break;
            default:
                printf("Invalid choice! \n");
        }
    }while(choice != 4);
}

void userlogin(car cars[], int totalcars, user users[], int totalusers){

    char username[20], password[20];

    printf("\nUser Login\n");
    printf("Username: ");
    scanf("%s", username);
    printf("Password: ");
    scanf("%s", password);

    for(int i=0; i<totalusers; i++)
    {
        if(strcmp(users[i].username, username) == 0 && strcmp(users[i].password, password) == 0) {
            printf("User login successful!\n");
            usermenu(cars, totalcars, users, totalusers);
            return;
        }
    }
    printf("Invalid login!\n");
}

int main(void) {

     car cars[MAX_Cars];
     user users[MAX_Users];

    int choice;
    int totalcars = 0;
    int totalusers = 0;

    do {
        printf("\nWelcome to the Car Rental System\n");
        printf("1. Admin Login\n");
        printf("2. User Login\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                adminlogin(cars, &totalcars, users, totalusers);
                break;
            case 2:
                userlogin(cars, totalcars, users, totalusers);
                break;
            case 3:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice! Try again.\n");
        }
    } while (choice != 3);

    return 0;
}
