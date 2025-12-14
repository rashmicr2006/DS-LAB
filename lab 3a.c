
#include <stdio.h>
#include <stdlib.h>

#define MAX 5

int queue[MAX];
int front = -1, rear = -1;

void insert(int x) {
    if (rear == MAX - 1)
        printf("Queue Overflow\n");
    else {
        if (front == -1) front = 0;
        rear++;
        queue[rear] = x;
        printf("Inserted %d\n", x);
    }
}

void delete() {
    if (front == -1 || front > rear)
        printf("Queue Empty\n");
    else {
        printf("Deleted %d\n", queue[front]);
        front++;
    }
}

void display() {
    if (front == -1 || front > rear)
        printf("Queue Empty\n");
    else {
        for (int i = front; i <= rear; i++)
            printf("%d ", queue[i]);
        printf("\n");
    }
}

int main() {
    int choice, x;

    while (1) {
        printf("\n1 Insert\n2 Delete\n3 Display\n4 Exit\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1: scanf("%d", &x); insert(x); break;
            case 2: delete(); break;
            case 3: display(); break;
            case 4: exit(0);
            default: printf("Invalid Choice\n");
        }
    }
    return 0;
}
