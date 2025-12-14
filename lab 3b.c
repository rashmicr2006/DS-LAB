
#include <stdio.h>
#include <stdlib.h>

#define MAX 5

int cqueue[MAX];
int front = -1, rear = -1;

void insert(int x) {
    if ((front == 0 && rear == MAX - 1) || (rear + 1) % MAX == front)
        printf("Circular Queue Overflow\n");
    else {
        if (front == -1) front = 0;
        rear = (rear + 1) % MAX;
        cqueue[rear] = x;
        printf("Inserted %d\n", x);
    }
}

void delete() {
    if (front == -1)
        printf("Circular Queue Empty\n");
    else {
        printf("Deleted %d\n", cqueue[front]);
        if (front == rear)
            front = rear = -1;
        else
            front = (front + 1) % MAX;
    }
}

void display() {
    if (front == -1)
        printf("Circular Queue Empty\n");
    else {
        int i = front;
        while (1) {
            printf("%d ", cqueue[i]);
            if (i == rear) break;
            i = (i + 1) % MAX;
        }
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
