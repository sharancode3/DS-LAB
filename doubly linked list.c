#include <stdio.h>
#include <stdlib.h>

struct node {
    int info;
    struct node *prev;
    struct node *next;
};

struct node *start = NULL;

void create(int value) {
    struct node *newnode = malloc(sizeof(struct node));
    newnode->info = value;
    newnode->prev = NULL;
    newnode->next = NULL;

    if (start == NULL) {
        start = newnode;
    } else {
        struct node *temp = start;
        while (temp->next != NULL)
            temp = temp->next;
        temp->next = newnode;
        newnode->prev = temp;
    }
    printf("Node inserted\n");
}

void insert_left(int value, int key) {
    struct node *temp = start;

    while (temp != NULL && temp->info != key)
        temp = temp->next;

    if (temp == NULL) {
        printf("Element not found\n");
        return;
    }

    struct node *newnode = malloc(sizeof(struct node));
    newnode->info = value;
    newnode->next = temp;
    newnode->prev = temp->prev;

    if (temp->prev != NULL)
        temp->prev->next = newnode;
    else
        start = newnode;

    temp->prev = newnode;
    printf("Inserted to the left\n");
}

void delete_value(int key) {
    struct node *temp = start;

    while (temp != NULL && temp->info != key)
        temp = temp->next;

    if (temp == NULL) {
        printf("Element not found\n");
        return;
    }

    if (temp->prev != NULL)
        temp->prev->next = temp->next;
    else
        start = temp->next;

    if (temp->next != NULL)
        temp->next->prev = temp->prev;

    free(temp);
    printf("Node deleted\n");
}

void display() {
    struct node *temp = start;

    if (temp == NULL) {
        printf("List is empty\n");
        return;
    }

    printf("List: ");
    while (temp != NULL) {
        printf("%d ", temp->info);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    int choice, value, key;

    while (1) {
        printf("\n1.Create  2.Insert Left  3.Delete  4.Display  5.Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value: ");
                scanf("%d", &value);
                create(value);
                break;

            case 2:
                printf("Enter new value: ");
                scanf("%d", &value);
                printf("Enter key value: ");
                scanf("%d", &key);
                insert_left(value, key);
                break;

            case 3:
                printf("Enter value to delete: ");
                scanf("%d", &key);
                delete_value(key);
                break;

            case 4:
                display();
                break;

            case 5:
                return 0;
        }
    }
}
