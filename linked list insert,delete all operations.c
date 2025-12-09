#include <stdio.h>
#include <stdlib.h>

struct node {
    int info;
    struct node *next;
};

struct node *start = NULL;

void insert_end(int value) {
    struct node *newnode = malloc(sizeof(struct node));

    newnode->info = value;
    newnode->next = NULL;

    if (start == NULL) {
        start = newnode;
        return;
    }

    struct node *temp = start;
    while (temp->next != NULL)
        temp = temp->next;

    temp->next = newnode;
}

void insert_begin(int value) {
    struct node *newnode = malloc(sizeof(struct node));

    newnode->info = value;
    newnode->next = start;
    start = newnode;
}

void insert_pos(int value, int pos) {
    if (pos == 1) {
        insert_begin(value);
        return;
    }

    struct node *temp = start;
    int i = 1;

    while (i < pos - 1 && temp != NULL) {
        temp = temp->next;
        i++;
    }

    if (temp == NULL) {
        printf("Invalid position\n");
        return;
    }

    struct node *newnode = malloc(sizeof(struct node));
    newnode->info = value;
    newnode->next = temp->next;
    temp->next = newnode;
}

void delete_begin() {
    if (start == NULL) {
        printf("List empty\n");
        return;
    }

    struct node *temp = start;
    start = start->next;
    free(temp);
}

void delete_end() {
    if (start == NULL) {
        printf("List empty\n");
        return;
    }

    if (start->next == NULL) {
        free(start);
        start = NULL;
        return;
    }

    struct node *temp = start;
    while (temp->next->next != NULL)
        temp = temp->next;

    free(temp->next);
    temp->next = NULL;
}

void delete_pos(int pos) {
    if (start == NULL) {
        printf("List empty\n");
        return;
    }

    if (pos == 1) {
        delete_begin();
        return;
    }

    struct node *temp = start;
    int i = 1;

    while (i < pos - 1 && temp != NULL) {
        temp = temp->next;
        i++;
    }

    if (temp == NULL || temp->next == NULL) {
        printf("Invalid position\n");
        return;
    }

    struct node *del = temp->next;
    temp->next = del->next;
    free(del);
}

void display() {
    if (start == NULL) {
        printf("List empty\n");
        return;
    }

    struct node *temp = start;
    while (temp != NULL) {
        printf("%d ", temp->info);
        temp = temp->next;
    }
    printf("\n");
}

void create_list() {
    int n, value;
    printf("Enter number of nodes: ");
    scanf("%d", &n);

    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &value);
        insert_end(value);
    }
}

int main() {
    int choice, value, pos;

    while (1) {
        printf("\n----- Linked List Menu -----\n");
        printf("1. Create Linked List\n");
        printf("2. Insert at beginning\n");
        printf("3. Insert at end\n");
        printf("4. Insert at position\n");
        printf("5. Delete at beginning\n");
        printf("6. Delete at end\n");
        printf("7. Delete at position\n");
        printf("8. Display list\n");
        printf("9. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {

            case 1:
                create_list();
                break;

            case 2:
                printf("Enter element: ");
                scanf("%d", &value);
                insert_begin(value);
                break;

            case 3:
                printf("Enter element: ");
                scanf("%d", &value);
                insert_end(value);
                break;

            case 4:
                printf("Enter element and position: ");
                scanf("%d %d", &value, &pos);
                insert_pos(value, pos);
                break;

            case 5:
                delete_begin();
                break;

            case 6:
                delete_end();
                break;

            case 7:
                printf("Enter position: ");
                scanf("%d", &pos);
                delete_pos(pos);
                break;

            case 8:
                display();
                break;

            case 9:
                return 0;

            default:
                printf("Invalid choice\n");
        }
    }
}
