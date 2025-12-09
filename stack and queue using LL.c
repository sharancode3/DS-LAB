#include <stdio.h>
#include <stdlib.h>

struct node {
    int info;
    struct node *next;
};

struct node *stack_top = NULL;
struct node *q_front = NULL, *q_rear = NULL;

void push(int v) {
    struct node *n = malloc(sizeof(struct node));
    if (!n) return printf("Memory Error\n");
    n->info = v;
    n->next = stack_top;
    stack_top = n;
    printf("Pushed: %d\n", v);
}

void pop() {
    if (!stack_top) return printf("Stack Empty\n");
    struct node *t = stack_top;
    printf("Popped: %d\n", t->info);
    stack_top = t->next;
    free(t);
}

void display_stack() {
    if (!stack_top) return printf("Stack Empty\n");
    struct node *t = stack_top;
    printf("Stack: ");
    while (t) { printf("%d ", t->info); t = t->next; }
    printf("\n");
}

void enqueue(int v) {
    struct node *n = malloc(sizeof(struct node));
    if (!n) return printf("Memory Error\n");
    n->info = v;
    n->next = NULL;

    if (!q_front)
        q_front = q_rear = n;
    else
        q_rear->next = n, q_rear = n;

    printf("Enqueued: %d\n", v);
}

void dequeue() {
    if (!q_front) return printf("Queue Empty\n");
    struct node *t = q_front;
    printf("Dequeued: %d\n", t->info);
    q_front = q_front->next;
    if (!q_front) q_rear = NULL;
    free(t);
}

void display_queue() {
    if (!q_front) return printf("Queue Empty\n");
    struct node *t = q_front;
    printf("Queue: ");
    while (t) { printf("%d ", t->info); t = t->next; }
    printf("\n");
}

int main() {
    int choice, sub, val;

    while (1) {
        printf("\n1.Stack  2.Queue  3.Exit\nChoice: ");
        scanf("%d", &choice);

        if (choice == 1) {
            printf("\n1.Push 2.Pop 3.Show 4.Back\nChoice: ");
            scanf("%d", &sub);
            if (sub == 1) { printf("Value: "); scanf("%d", &val); push(val); }
            else if (sub == 2) pop();
            else if (sub == 3) display_stack();
        }
        else if (choice == 2) {
            printf("\n1.Enqueue 2.Dequeue 3.Show 4.Back\nChoice: ");
            scanf("%d", &sub);
            if (sub == 1) { printf("Value: "); scanf("%d", &val); enqueue(val); }
            else if (sub == 2) dequeue();
            else if (sub == 3) display_queue();
        }
        else if (choice == 3) return 0;
        else printf("Invalid\n");
    }
}
