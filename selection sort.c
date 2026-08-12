#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int i, j, n, temp, min_index, *a;
    float start, end, time_taken;

    printf("Enter the n elements: ");
    scanf("%d", &n);

    a = (int *)malloc(n * sizeof(int));

    printf("Unsorted elements:\n");

    start = clock();

    for (i = 0; i < n; i++)
    {
        a[i] = rand() % 101;
        printf("%d\t", a[i]);
    }

    for (i = 0; i < n - 1; i++)
    {
        min_index = i;

        for (j = i + 1; j < n; j++)
        {
            if (a[j] < a[min_index])
            {
                min_index = j;
            }
        }

        temp = a[i];
        a[i] = a[min_index];
        a[min_index] = temp;
    }

    end = clock();

    printf("\nSorted elements:\n");

    for (i = 0; i < n; i++)
    {
        printf("%d\t", a[i]);
    }

    time_taken = ((end - start) / CLOCKS_PER_SEC) * 1000;

    printf("\nTime taken: %f ms\n", time_taken);

    free(a);

    return 0;
}