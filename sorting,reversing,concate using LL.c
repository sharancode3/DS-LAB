#include <stdio.h>
#include <stdlib.h>

struct node {
    int info;
    struct node *next;
};

struct node *start1 = NULL;
struct node *start2 = NULL;

void create_list1(int value) {
    struct node *newnode = (struct node*)malloc(sizeof(struct node));
    newnode->info = value;
    newnode->next = NULL;
    if (start1 == NULL)
        start1 = newnode;
    else {
        struct node *temp = start1;
        while (temp->next != NULL)
            temp = temp->next;
        temp->next = newnode;
    }
}

void create_list2(int value) {
    struct node *newnode = (struct node*)malloc(sizeof(struct node));
    newnode->info = value;
    newnode->next = NULL;
    if (start2 == NULL)
        start2 = newnode;
    else {
        struct node *temp = start2;
        while (temp->next != NULL)
            temp = temp->next;
        temp->next = newnode;
    }
}

void display(struct node *start) {
    if (start == NULL) {
        printf("List is empty\n");
        return;
    }
    struct node *temp = start;
    while (temp != NULL) {
        printf("%d ", temp->info);
        temp = temp->next;
    }
    printf("\n");
}

void sort_list(struct node **s) {
    if (*s == NULL || (*s)->next == NULL) return;
    int swapped;
    do {
        swapped = 0;
        struct node *ptr = *s;
        while (ptr->next != NULL) {
            if (ptr->info > ptr->next->info) {
                int t = ptr->info;
                ptr->info = ptr->next->info;
                ptr->next->info = t;
                swapped = 1;
            }
            ptr = ptr->next;
        }
    } while (swapped);
}

void reverse_list(struct node **s) {
    struct node *prev = NULL;
    struct node *curr = *s;
    struct node *next = NULL;
    while (curr != NULL) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    *s = prev;
}

void concatenate() {
    if (start2 == NULL) {
        printf("Second list is empty — nothing to concatenate\n");
        return;
    }
    if (start1 == NULL) {
        start1 = start2;
    } else {
        struct node *temp = start1;
        while (temp->next != NULL)
            temp = temp->next;
        temp->next = start2;
    }
    start2 = NULL;
    printf("Lists concatenated: list2 appended to list1\n");
}

int main() {
    int choice, value, n, i;

    while (1) {
        printf("\n--- SINGLY LINKED LIST MENU ---\n");
        printf("1. Create list1 (append n elements)\n");
        printf("2. Create list2 (append n elements)\n");
        printf("3. Display list1\n");
        printf("4. Display list2\n");
        printf("5. Sort list1\n");
        printf("6. Sort list2\n");
        printf("7. Reverse list1\n");
        printf("8. Reverse list2\n");
        printf("9. Concatenate list2 to list1\n");
        printf("10. Display concatenated list (list1)\n");
        printf("11. Exit\n");
        printf("Enter your choice: ");
        if (scanf("%d", &choice) != 1) return 0;

        switch (choice) {
            case 1:
                printf("How many elements to append to list1? ");
                scanf("%d", &n);
                for (i = 0; i < n; i++) {
                    printf("Enter element %d: ", i+1);
                    scanf("%d", &value);
                    create_list1(value);
                }
                break;

            case 2:
                printf("How many elements to append to list2? ");
                scanf("%d", &n);
                for (i = 0; i < n; i++) {
                    printf("Enter element %d: ", i+1);
                    scanf("%d", &value);
                    create_list2(value);
                }
                break;

            case 3:
                printf("List1: ");
                display(start1);
                break;

            case 4:
                printf("List2: ");
                display(start2);
                break;

            case 5:
                sort_list(&start1);
                printf("List1 sorted\n");
                break;

            case 6:
                sort_list(&start2);
                printf("List2 sorted\n");
                break;

            case 7:
                reverse_list(&start1);
                printf("List1 reversed\n");
                break;

            case 8:
                reverse_list(&start2);
                printf("List2 reversed\n");
                break;

            case 9:
                concatenate();
                break;

            case 10:
                printf("Concatenated list (list1): ");
                display(start1);
                break;

            case 11:
                return 0;

            default:
                printf("Invalid choice\n");
        }
    }
    return 0;
}
