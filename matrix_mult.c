#include <limits.h>
#include <stdio.h>

int S[7][7] = {0};

void paran(int i, int j)
{
    int k;
    k = S[i][j];
    if (i == j)
    {
        printf("A%d ", i);
        return;
    }
    printf("(");
    paran(i, k);
    printf(")");
    printf("(");
    paran(k + 1, j);
    printf(")");
}

int matrixChainOrder(int p[], int i, int j)
{
    if (i == j)
        return 0;
    int k, loc, count;
    int min = INT_MAX;
    for (k = i; k < j; k++)
    {
        count = matrixChainOrder(p, i, k) + matrixChainOrder(p, k + 1, j) + p[i - 1] * p[k] * p[j];
        if (count < min)
        {
            min = count;
            loc = k;
        }
        S[i][j] = loc;
    }
    return min;
}

int main()
{
    int arr[] = {30, 35, 15, 5, 10, 20, 25};
    int n = sizeof(arr) / sizeof(arr[0]);
    int i, j;
    printf("%d is the min. no. of multiplication \n", matrixChainOrder(arr, 1, n - 1));
    for (i = 1; i <= n; i++)
    {
        for (j = 2; j <= 6; j++)
        {
            printf("\t%d ", S[i][j]);
        }
        printf("\n");
    }
    paran(1, 6);
    return 0;
}
