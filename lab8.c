#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *left;
    struct node *right;
};

struct node *create(int item)
{
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp->data = item;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}

struct node *insert(struct node *root, int item)
{
    if (root == NULL)
        return create(item);

    if (item < root->data)
        root->left = insert(root->left, item);
    else
        root->right = insert(root->right, item);

    return root;
}

void inorder(struct node *root)
{
    if (root != NULL)
    {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

void preorder(struct node *root)
{
    if (root != NULL)
    {
        printf("%d ", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

void postorder(struct node *root)
{
    if (root != NULL)
    {
        postorder(root->left);
        postorder(root->right);
        printf("%d ", root->data);
    }
}

int main()
{
    struct node *root = NULL;
    int n, item, choice;

    while (1)
    {
        printf("\n1.Insert\n2.Inorder\n3.Preorder\n4.Postorder\n5.Display\n6.Exit\n");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter element: ");
            scanf("%d", &item);
            root = insert(root, item);
            break;

        case 2:
            inorder(root);
            break;

        case 3:
            preorder(root);
            break;

        case 4:
            postorder(root);
            break;

        case 5:
            inorder(root);
            break;

        case 6:
            exit(0);
        }
    }
    return 0;
}

