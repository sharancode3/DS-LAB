#include <stdio.h>

#define MAX 20

int hashTable[MAX];
int m;

void insert(int key)
{
    int index = key % m;

    if (hashTable[index] == -1)
    {
        hashTable[index] = key;
    }
    else
    {
        int i = 1;
        while (hashTable[(index + i) % m] != -1)
        {
            i++;
        }
        hashTable[(index + i) % m] = key;
    }
}

void display()
{
    printf("\nHash Table:\n");
    for (int i = 0; i < m; i++)
    {
        if (hashTable[i] != -1)
            printf("Address %d : %d\n", i, hashTable[i]);
        else
            printf("Address %d : Empty\n", i);
    }
}

int main()
{
    int n, key;

    printf("Enter size of hash table (m): ");
    scanf("%d", &m);

    printf("Enter number of employee records: ");
    scanf("%d", &n);

    for (int i = 0; i < m; i++)
        hashTable[i] = -1;

    printf("Enter %d employee keys (4-digit):\n", n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &key);
        insert(key);
    }

    display();

    return 0;
}
