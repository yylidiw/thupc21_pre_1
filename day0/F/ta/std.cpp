#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 300 + 5;
int a[N];
int chess[N][N];
int main()
{
    int n, m;

    // input
    scanf("%d%d", &n, &m);
    for (int j = 1; j <= m; ++j)
        scanf("%d", a + j);

    // work
    if (n & 1)
    {
        int las = 0;
        for (int j = 1; j <= m; ++j)
        {
            if (a[j] > n + 1 >> 1)
            {
                puts("No");
                return 0;
            }
            else if (a[j] == n + 1 >> 1)
            {
                for (int i = 1; i <= n; i += 2)
                    chess[i][j] = 1;

                if (las == 0)
                {
                    for (int k = j; --k;)
                        for (int i = 1 + ((j - k) & 1); i <= n && a[k]; i += 2, --a[k])
                            chess[i][k] = 1;
                }
                else
                {
                    if (j - las == 1)
                    {
                        puts("No");
                        return 0;
                    }
                    else if ((j ^ las) & 1 ^ 1)
                    {
                        for (int k = las + 1; k < j; ++k)
                            for (int i = 1 + ((k - las) & 1); i <= n && a[k]; i += 2, --a[k])
                                chess[i][k] = 1;
                    }
                    else
                    {
                        for (int k = las + 1; k < j; ++k)
                        {
                            for (int i = n - (k - las & 1 ^ 1); i >= 1 && !chess[i][k - 1] && a[k]; i -= 2, --a[k])
                                chess[i][k] = 1;
                            for (int i = 1 + (k - las & 1); i <= n && a[k]; i += 2, --a[k])
                                chess[i][k] = 1;

                            if (a[k])
                            {
                                puts("No");
                                return 0;
                            }
                        }
                        for (int i = 1; i <= n; ++i)
                            if (chess[i][j - 1] && chess[i][j])
                            {
                                puts("No");
                                return 0;
                            }
                    }
                }
                las = j;
            }
        }

        if (las != m)
        {
            for (int k = las + 1; k <= m; ++k)
                for (int i = 1 + ((k - las) & 1); i <= n && a[k]; i += 2, --a[k])
                    chess[i][k] = 1;
        }
    }
    else
    {
        for (int j = 1; j <= m; ++j)
        {
            if (a[j] > n >> 1)
            {
                puts("No");
                return 0;
            }
            for (int i = 1 + (j & 1); i <= n && a[j]; i += 2, --a[j])
                chess[i][j] = 1;
        }
    }

    // output
    puts("Yes");
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= m; ++j)
            printf("%d", chess[i][j]);
        puts("");
    }
}