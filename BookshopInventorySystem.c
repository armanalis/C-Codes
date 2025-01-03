/*
This is a simple project where the system maintains the inventory of books in a bookshop.
If a customer purchases a book, the book's count will decrease; if a book is added, the same is updated.
Notice the use of pointers. You can modify the code to add a book ID and make the search based on the book ID
or make the search using just one parameter giving multiple results, and so on.

Solution starts below:
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

struct book{
    int ID;
    char title[MAX];
    char author[MAX];
    int quantity;
    float price;
};

void add(struct book *books, int *count){

    if(*count>MAX){
        printf("Inventory is full. Cannot add more books.\n");
        return;
    }

    struct book *new = &books[*count];

    printf("Enter book ID:");
    scanf("%d", &new->ID);
    getchar();
    printf("Enter book title:");
    fgets(new->title, sizeof(new->title), stdin);
    new->title[strcspn(new->title, "\n")] = '\0';//Remove new line character
    printf("Enter author name:");
    fgets(new->author, sizeof(new->author), stdin);
    new->author[strcspn(new->author, "\n")] = '\0';//Remove new line character
    printf("Enter quantity:");
    scanf("%d", &new->quantity);
    printf("Enter price:");
    scanf("%f", &new->price);

    (*count)++;
    printf("Book added successfully.\n");
}

void display(struct book *books, int count){

    if(count == 0){
        printf("No books in inventory.\n");
        return;
    }

    printf("Displaying all the books in the inventory:\n");

    for(int i=0; i<count; i++){

        printf("ID:%d, Title: %s, Author: %s, Quantity: %d, Price: %.2f\n",
               books[i].ID, books[i].title, books[i].author, books[i].quantity, books[i].price);
    }
}

int search(struct book *books, int count){

    int id;

    printf("Enter book ID to search:");
    scanf("%d", &id);

    for(int i=0; i<count; i++){
        if(books[i].ID == id){
            printf("Book found: ID: %d, Title:%s, Author: %s, Quantity: %d, Price: %.2f\n",
                   books[i].ID, books[i].title, books[i].author, books[i].quantity, books[i].price);
            return 1;
        }
    }
    printf("Book with ID %d not found.\n", id);

    return 1;
}

void sell(struct book *books, int count) {

    int id;

    printf("Enter book ID to sell:");
    scanf("%d", &id);

    for (int i = 0; i < count; i++) {
        if (books[i].ID == id) {
            if (books[i].quantity > 0) {
                books[i].quantity--;
                printf("Book sold successfully!\nRemaining quantity: %d\n", books[i].quantity);
            } else {
                printf("Book out of stock.\n");
            }
            return;
        }
    }
    printf("Book with ID: %d not found.\n", id);
}

void update(struct book *books, int count){

    int id, quantity;

    printf("Enter book Id to update quantity:");
    scanf("%d", &id);

    for(int i=0; i<count; i++){
        if(books[i].ID == id){
            printf("\nEnter new quantity for book ID %d:", id);
            scanf("%d", &quantity);
            books[i].quantity += quantity;
            printf("Book quantity updated successfully to %d.\n", books[i].quantity);
            return;
        }
    }
    printf("Book with ID %d not found.\n", id);
}

int main(){

    char check = 'y';
    int choice, count = 0;
    struct book books[MAX];

    do{
        printf("Welcome to the bookshop menu:\n");
        printf("1.Add a book:\n2.Display all books:\n3.Search for a book by ID:");
        printf("\n4. Sell a book:\n5.Update book quantity:\n6.Exit\nEnter your choice:");
        scanf("%d", &choice);

        switch(choice){
            case 1:
                add(books, &count);
                break;
            case 2:
                display(books, count);
                break;
            case 3:
                search(books, count);
                break;
            case 4:
                sell(books, count);
                break;
            case 5:
                update(books, count);
                break;
            case 6:
                exit(1);
            default:
                printf("Invalid choice. Please try again.\n");
        }

        printf("\nDo you want to continue: (y/n) ");
        getchar(); // clear new line left in buffer
        scanf("%c", &check);

    }while(check == 'y' || check == 'Y');

    return 0;
}
