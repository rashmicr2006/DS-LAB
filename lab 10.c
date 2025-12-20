
#include <stdio.h>

#define MAX 100

int hashTable[MAX];
int m;

int hash(int key)
{
    return key % m;
}

void insert(int key)
{
    int index = hash(key);
    int startIndex = index;

    while (hashTable[index] != -1)
    {
        index = (index + 1) % m;

        if (index == startIndex)
        {
            printf("Hash table is full\n");
            return;
        }
    }

    hashTable[index] = key;
}

void display()
{
    int i;
    printf("\nHash Table:\n");
    for (i = 0; i < m; i++)
    {
        if (hashTable[i] != -1)
            printf("Address %d : %d\n", i, hashTable[i]);
        else
            printf("Address %d : EMPTY\n", i);
    }
}

int main()
{
    int n, key, i;

    printf("Enter number of memory locations (m): ");
    scanf("%d", &m);

    for (i = 0; i < m; i++)
        hashTable[i] = -1;

    printf("Enter number of employee records (N): ");
    scanf("%d", &n);

    printf("Enter %d employee keys (4-digit):\n", n);
    for (i = 0; i < n; i++)
    {
        scanf("%d", &key);
        insert(key);
    }

    display();
    return 0;
}
