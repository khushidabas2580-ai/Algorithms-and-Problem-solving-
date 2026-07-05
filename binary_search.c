#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int binarySearch(int arr[], int n, int target)
{
    int left = 0;
    int right = n - 1;
    while (left <= right)
    {
        int mid = left + (right - left) / 2;
        if (arr[mid] == target)
            return mid;
        if (arr[mid] < target)
            left = mid + 1;
        else
            right = mid - 1;
    }
    return -1;
}
void generateSortedArray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        arr[i] = i + 1;
    }
}
int main()
{
    int sizes[] = {1000, 5000, 10000, 50000, 100000};
    int testCount = sizeof(sizes) / sizeof(sizes[0]);
    printf("BINARY SEARCH PERFORMANCE TEST\n");
    printf("=======================================\n");
    for (int t = 0; t < testCount; t++)
    {
        int n = sizes[t];
        int *arr = (int *)malloc(n * sizeof(int));
        generateSortedArray(arr, n);
        int target = n;
        clock_t start = clock();
        int result = binarySearch(arr, n, target);
        clock_t end = clock();
        double runtime =
            (double)(end - start) / CLOCKS_PER_SEC;
        printf("Input Size : %d\n", n);
        printf("Target     : %d\n", target);
        if (result != -1)
            printf("Found at Index : %d\n", result);
        else
            printf("Element Not Found\n");
        printf("Runtime    : %.8f seconds\n", runtime);
        printf("---------------------------------------\n");
        free(arr);
    }
    return 0;
}