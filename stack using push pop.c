
#include <stdio.h>
#include <stdlib.h>

#define MAX 10
int arr[MAX];
int top = -1;

void push(int n) {
    if(top == MAX - 1) {
        printf("Stack Overflow: Unable to push element\n");
        return;
    }

    top++;
    arr[top] = n;
}

void pop() {
    if(top == -1) {
        printf("Stack Underflow: Unable to pop element\n");
        return;
    }

    int el = arr[top];
    top--;
    return el;
}

void display() {
    printf("Stack: ");
    if(top == -1) printf("Empty");
    else {
        for(int i = top; i >= 0; i--) {
            printf("%d ", arr[i]);
        }
    }
    printf("\n");
}

int main()
{
    printf("Enter number of elements: ");
    int n;
    scanf("%d", &n);

    display();
    printf("\nPushing elements: \n");

    for(int i = 0; i < n; i++) {
        printf("%d: ", i + 1);
        int e;
        scanf("%d", &e);

        push(e);
    }

    display();
    printf("\n After Popping one element: \n");

    {
        pop();
    }


    display();
    return 0;
}
