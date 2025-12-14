#include <stdio.h>
#include <stdlib.h>

#define MAX 50

struct node {
    int info;
    struct node *next;
};

int stack[MAX];
int top = -1;

void push(int x) {
    if (top == MAX - 1)
        printf("Stack Overflow\n");
    else {
        top++;
        stack[top] = x;
        printf("Pushed %d\n", x);
    }
}

void pop() {
    if (top == -1)
        printf("Stack Underflow\n");
    else {
        printf("Popped %d\n", stack[top]);
        top--;
    }
}

void display_stack() {
    if (top == -1)
        printf("Stack is empty\n");
    else {
        for (int i = top; i >= 0; i--)
            printf("%d ", stack[i]);
        printf("\n");
    }
}

struct node* createsll() {
    struct node *start = NULL, *p, *temp;
    int item;
    printf("Enter elements for linked list (-999 to stop): ");
    scanf("%d", &item);

    while (item != -999) {
        p = (struct node*)malloc(sizeof(struct node));
        p->info = item;
        p->next = NULL;

        if (start == NULL)
            start = p;
        else {
            temp = start;
            while (temp->next != NULL)
                temp = temp->next;
            temp->next = p;
        }
        scanf("%d", &item);
    }
    return start;
}

void display_ll(struct node *start) {
    struct node *temp = start;
    while (temp != NULL) {
        printf("%d ", temp->info);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    struct node *start = NULL;
    int choice, x;

    while (1) {
        printf("\n1. Create Linked List\n2. Display Linked List\n3. Push\n4. Pop\n5. Display Stack\n6. Exit\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1: start = createsll(); break;
            case 2: display_ll(start); break;
            case 3: printf("Enter element to push: "); scanf("%d", &x); push(x); break;
            case 4: pop(); break;
            case 5: display_stack(); break;
            case 6: exit(0);
            default: printf("Invalid choice\n");
        }
    }
    return 0;
}

