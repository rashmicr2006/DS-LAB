#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct node *stack_top = NULL;
struct node *qf = NULL, *qr = NULL;

struct node* create(int val) {
    struct node *t = (struct node*)malloc(sizeof(struct node));
    t->data = val;
    t->next = NULL;
    return t;
}

void push(int val) {
    struct node *n = create(val);
    n->next = stack_top;
    stack_top = n;
}

int pop() {
    if (stack_top == NULL) return -1;
    struct node *t = stack_top;
    int v = t->data;
    stack_top = stack_top->next;
    free(t);
    return v;
}

int peek_stack() {
    if (stack_top == NULL) return -1;
    return stack_top->data;
}

void display_stack() {
    struct node *t = stack_top;
    while (t) {
        printf("%d ", t->data);
        t = t->next;
    }
    printf("\n");
}

void enqueue(int val) {
    struct node *n = create(val);
    if (qf == NULL) qf = qr = n;
    else {
        qr->next = n;
        qr = n;
    }
}

int dequeue() {
    if (qf == NULL) return -1;
    struct node *t = qf;
    int v = t->data;
    qf = qf->next;
    if (qf == NULL) qr = NULL;
    free(t);
    return v;
}

int peek_queue() {
    if (qf == NULL) return -1;
    return qf->data;
}

void display_queue() {
    struct node *t = qf;
    while (t) {
        printf("%d ", t->data);
        t = t->next;
    }
    printf("\n");
}

int main() {
    int opt, val;

    do {
        printf("1 Push\n2 Pop\n3 Peek Stack\n4 Display Stack\n5 Enqueue\n6 Dequeue\n7 Peek Queue\n8 Display Queue\n9 Exit\n");
        scanf("%d", &opt);

        switch (opt) {
            case 1: scanf("%d", &val); push(val); break;
            case 2: printf("%d\n", pop()); break;
            case 3: printf("%d\n", peek_stack()); break;
            case 4: display_stack(); break;
            case 5: scanf("%d", &val); enqueue(val); break;
            case 6: printf("%d\n", dequeue()); break;
            case 7: printf("%d\n", peek_queue()); break;
            case 8: display_queue(); break;
        }
    } while (opt != 9);

    return 0;
}
