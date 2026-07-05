#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void merge(int arr[], int left, int mid, int right)
{
    int n1 = mid - left + 1;
    int n2 = right - mid;
    int *L = (int *)malloc(n1 * sizeof(int));
    int *R = (int *)malloc(n2 * sizeof(int));
    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];
    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }
    while (j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }
    free(L);
    free(R);
}
void mergeSort(int arr[], int left, int right)
{
    if (left < right)
    {
        int mid = left + (right - left) / 2;

        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);

        merge(arr, left, mid, right);
    }
}
int isSorted(int arr[], int n)
{
    for (int i = 1; i < n; i++)
    {
        if (arr[i] < arr[i - 1])
            return 0;
    }
    return 1;
}
void generateRandomArray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        arr[i] = rand() % 100000;
    }
}
int main()
{
    srand(time(NULL));
    int sizes[] = {1000, 5000, 10000, 50000};
    int numTests = sizeof(sizes) / sizeof(sizes[0]);
    printf("MERGE SORT PERFORMANCE TEST\n");
    printf("----------------------------------\n");
    for (int t = 0; t < numTests; t++)
    {
        int n = sizes[t];
        int *arr = (int *)malloc(n * sizeof(int));
        generateRandomArray(arr, n);
        clock_t start = clock();
        mergeSort(arr, 0, n - 1);
        clock_t end = clock();
        double runtime =
            ((double)(end - start)) / CLOCKS_PER_SEC;
        printf("Input Size: %d\n", n);
        printf("Runtime: %.6f seconds\n", runtime);
        if (isSorted(arr, n))
            printf("Status: Sorting Successful\n");
        else
            printf("Status: Sorting Failed\n");
        printf("----------------------------------\n");
        free(arr);
    }
    return 0;
}