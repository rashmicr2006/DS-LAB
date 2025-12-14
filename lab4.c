
#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
} *head = NULL;

struct node* create(int value) {
    struct node *temp = (struct node*)malloc(sizeof(struct node));
    temp->data = value;
    temp->next = NULL;
    return temp;
}

int count() {
    int c = 0;
    struct node *temp = head;
    while (temp != NULL) {
        c++;
        temp = temp->next;
    }
    return c;
}

void insert_begin(int value) {
    struct node *newnode = create(value);
    newnode->next = head;
    head = newnode;
}

void insert_end(int value) {
    struct node *newnode = create(value), *temp;
    if (head == NULL)
        head = newnode;
    else {
        temp = head;
        while (temp->next != NULL)
            temp = temp->next;
        temp->next = newnode;
    }
}

void insert_pos(int value, int pos) {
    int c = count(), i = 1;
    if (pos < 1 || pos > c + 1) {
        printf("Invalid Position\n");
        return;
    }
    if (pos == 1) {
        insert_begin(value);
        return;
    }
    struct node *newnode = create(value);
    struct node *temp = head;
    while (i < pos - 1) {
        temp = temp->next;
        i++;
    }
    newnode->next = temp->next;
    temp->next = newnode;
}

void display() {
    struct node *temp = head;
    if (temp == NULL)
        printf("List is empty\n");
    else {
        while (temp != NULL) {
            printf("%d ", temp->data);
            temp = temp->next;
        }
        printf("\n");
    }
}

int main() {
    int ch, value, pos;
    while (1) {
        printf("\n1 Insert Begin\n2 Insert End\n3 Insert Position\n4 Display\n5 Exit\n");
        scanf("%d", &ch);

        if (ch == 5) break;

        switch (ch) {
            case 1: scanf("%d", &value); insert_begin(value); break;
            case 2: scanf("%d", &value); insert_end(value); break;
            case 3: scanf("%d", &value); scanf("%d", &pos); insert_pos(value, pos); break;
            case 4: display(); break;
            default: printf("Invalid Choice\n");
        }
    }
    return 0;
}
