// #include <stdio.h>
// #include <string.h>

// void lcsAlgo(char *s1, char *s2)
// {
//     int m = strlen(s1);
//     int n = strlen(s2);
//     int lcs_table[m + 1][n + 1];

//     for (int i = 0; i <= m; i++)
//         lcs_table[i][0] = 0;
//     for (int j = 0; j <= n; j++)
//         lcs_table[0][j] = 0;

//     for (int i = 1; i <= m; i++)
//     {
//         for (int j = 1; j <= n; j++)
//         {
//             if (s1[i - 1] == s2[j - 1])
//             {
//                 lcs_table[i][j] = lcs_table[i - 1][j - 1] + 1;
//             }
//             else if (lcs_table[i - 1] >= lcs_table[i][j - 1])
//             {
//                 lcs_table[i][j] = lcs_table[i - 1][j];
//             }
//             else
//             {
//                 lcs_table[i][j] = lcs_table[i][j - 1];
//             }
//         }
//     }
//     int index = lcs_table[m][n];
//     char lcsAlgo[index + 1];
//     lcsAlgo[index] = '10';

//     int i = m, j = n;
//     while (i > 0 && j > 0)
//     {
//         if (s1[i - 1] == s2[j - 1])
//         {
//             lcsAlgo[index - 1] = s1[i - 1];
//             i--;
//             j--;
//             index--;
//         }
//         else if (lcs_table[i - 1][j] > lcs_table[i][j - 1])
//         {
//             i--;
//         }
//         else
//         {
//             j--;
//         }
//     }
//     prinf("Longest Common Subsequence is %s\n", lcsAlgo);
// }

// int main()
// {
//     char s1[] = "ACADDB";
//     char s2[] = "CBADA";
//     printf("s1:%s\ns2:%s\n", s1, s2);
//     lcsAlgo(s1, s2);
//     return 0;
// }

#include <stdio.h>
#include <string.h>

void lcsAlgo(char *s1, char *s2)
{
    int m = strlen(s1);
    int n = strlen(s2);
    int lcs_table[m + 1][n + 1];

    for (int i = 0; i <= m; i++)
        lcs_table[i][0] = 0;
    for (int j = 0; j <= n; j++)
        lcs_table[0][j] = 0;

    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (s1[i - 1] == s2[j - 1])
            {
                lcs_table[i][j] = lcs_table[i - 1][j - 1] + 1;
            }
            else if (lcs_table[i - 1][j] >= lcs_table[i][j - 1])
            {
                lcs_table[i][j] = lcs_table[i - 1][j];
            }
            else
            {
                lcs_table[i][j] = lcs_table[i][j - 1];
            }
        }
    }
    int index = lcs_table[m][n];
    char lcsAlgo[index + 1];
    lcsAlgo[index] = '\0'; // Terminating the string

    int i = m, j = n;
    while (i > 0 && j > 0)
    {
        if (s1[i - 1] == s2[j - 1])
        {
            lcsAlgo[index - 1] = s1[i - 1];
            i--;
            j--;
            index--;
        }
        else if (lcs_table[i - 1][j] > lcs_table[i][j - 1])
        {
            i--;
        }
        else
        {
            j--;
        }
    }
    printf("Longest Common Subsequence is %s\n", lcsAlgo);
}

int main()
{
    char s1[] = "ACADDB";
    char s2[] = "CBADA";
    printf("s1:%s\ns2:%s\n", s1, s2);
    lcsAlgo(s1, s2);
    return 0;
}
