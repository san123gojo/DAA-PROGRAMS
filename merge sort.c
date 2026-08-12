#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void merge(int a[], int low, int mid, int high)
{
    int i = low, j = mid + 1, k = low;
    int temp[1000];

    while (i <= mid)
    {
        temp[k++] = a[i++];
    }

    while (j <= high)
    {
        temp[k++] = a[j++];
    }

    while (i <= mid && j <= high)
    {
        if (a[i] < a[j])
            temp[k++] = a[i++];
        else
            temp[k++] = a[j++];
    }

    for (i = low; i <= high; i++)
        a[i] = temp[i];
}

void mergesort(int a[], int low, int high)
{
    if (low < high)
    {
        int mid = (low + high) / 2;

        mergesort(a, low, mid);
        mergesort(a, mid + 1, high);

        merge(a, low, mid, high);
    }
}

int main()
{
    int n, i;
    int *a;
    float end, start, time_taken;

    printf("Enter n value: ");
    scanf("%d", &n);

    a = (int *)malloc(n * sizeof(int));

    printf("Unsorted array:\n");

    for (i = 0; i < n; i++)
    {
        a[i] = rand() % 101;
        printf("%d\t", a[i]);
    }

    start = clock();

    mergesort(a, 0, n - 1);

    end = clock();

    printf("\nThe sorted elements:\n");

    for (i = 0; i < n; i++)
    {
        printf("%d\t", a[i]);
    }

    time_taken = ((end - start) / CLOCKS_PER_SEC) * 1000;

    printf("\nTime taken %f ms\n", time_taken);

    free(a);

    return 0;
}