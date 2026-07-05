#include <stdio.h>
#include <stdlib.h>
#include <time.h>
// Return maximum of two integers
int max(int a, int b)
{
    return (a > b) ? a : b;
}
// Dynamic Programming Solution
int knapsack(int capacity, int weights[], int values[], int n)
{
    int **dp = (int **)malloc((n + 1) * sizeof(int *));
    for (int i = 0; i <= n; i++)
    {
        dp[i] = (int *)malloc((capacity + 1) * sizeof(int));
    }
    for (int i = 0; i <= n; i++)
    {
        for (int w = 0; w <= capacity; w++)
        {
            if (i == 0 || w == 0)
            {
                dp[i][w] = 0;
            }
            else if (weights[i - 1] <= w)
            {
                dp[i][w] = max(
                    values[i - 1] + dp[i - 1][w - weights[i - 1]],
                    dp[i - 1][w]);
            }
            else
            {
                dp[i][w] = dp[i - 1][w];
            }
        }
    }
    int result = dp[n][capacity];
    for (int i = 0; i <= n; i++)
    {
        free(dp[i]);
    }
    free(dp);
    return result;
}
int main()
{
    int testSizes[] = {10, 50, 100, 200};
    int numTests = sizeof(testSizes) / sizeof(testSizes[0]);
    printf("0/1 KNAPSACK PERFORMANCE TEST\n");
    printf("========================================\n");
    srand(time(NULL));
    for (int t = 0; t < numTests; t++)
    {
        int n = testSizes[t];
        int capacity = n * 5;
        int *weights = (int *)malloc(n * sizeof(int));
        int *values = (int *)malloc(n * sizeof(int));
        for (int i = 0; i < n; i++)
        {
            weights[i] = rand() % 20 + 1;
            values[i] = rand() % 100 + 1;
        }
        clock_t start = clock();
        int maxProfit = knapsack(capacity, weights, values, n);
        clock_t end = clock();
        double runtime =
            (double)(end - start) / CLOCKS_PER_SEC;
        printf("Number of Items : %d\n", n);
        printf("Capacity        : %d\n", capacity);
        printf("Maximum Profit  : %d\n", maxProfit);
        printf("Runtime         : %.6f seconds\n", runtime);
        printf("----------------------------------------\n");
        free(weights);
        free(values);
    }
    return 0;
}