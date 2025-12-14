
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

void delete_begin() {
    if (head == NULL)
        printf("Deletion not possible\n");
    else {
        struct node *temp = head;
        head = head->next;
        free(temp);
    }
}

void delete_end() {
    if (head == NULL)
        printf("Deletion not possible\n");
    else if (head->next == NULL) {
        free(head);
        head = NULL;
    } else {
        struct node *temp1 = head, *temp2 = NULL;
        while (temp1->next != NULL) {
            temp2 = temp1;
            temp1 = temp1->next;
        }
        temp2->next = NULL;
        free(temp1);
    }
}

void delete_pos(int pos) {
    int c = count(), i = 1;
    if (pos < 1 || pos > c) {
        printf("Invalid Position\n");
        return;
    }
    if (pos == 1) {
        delete_begin();
        return;
    }
    struct node *temp1 = head, *temp2 = NULL;
    while (i < pos) {
        temp2 = temp1;
        temp1 = temp1->next;
        i++;
    }
    temp2->next = temp1->next;
    free(temp1);
}

void delete_key(int key) {
    if (head == NULL) {
        printf("List empty\n");
        return;
    }
    if (head->data == key) {
        struct node *temp = head;
        head = head->next;
        free(temp);
        return;
    }
    struct node *temp1 = head, *temp2 = NULL;
    while (temp1 != NULL && temp1->data != key) {
        temp2 = temp1;
        temp1 = temp1->next;
    }
    if (temp1 == NULL) {
        printf("Key not found\n");
        return;
    }
    temp2->next = temp1->next;
    free(temp1);
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
    int ch, value, pos, key;

    while (1) {
        printf("\n1 Insert Begin\n2 Delete Begin\n3 Delete End\n4 Delete Position\n5 Delete Key\n6 Display\n7 Exit\n");
        scanf("%d", &ch);

        if (ch == 7) break;

        switch (ch) {
            case 1: scanf("%d", &value); insert_begin(value); break;
            case 2: delete_begin(); break;
            case 3: delete_end(); break;
            case 4: scanf("%d", &pos); delete_pos(pos); break;
            case 5: scanf("%d", &key); delete_key(key); break;
            case 6: display(); break;
            default: printf("Invalid Choice\n");
        }
    }
    return 0;
}
