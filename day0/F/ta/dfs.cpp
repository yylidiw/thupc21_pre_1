#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int n, m;
int a[55];
bool chess[305][305];
void dfs(int x, int y) {
    // printf("=== dfs(%d, %d) ===\n", x, y);
    // for (int i = 1; i <= n; ++i) {
    //     for (int j = 1; j <= m; ++j)
    //         printf("%d", chess[i][j]);
    //     puts("");
    // }
    // printf("a[%d] = %d\n", y, a[y]);

    if (a[y] == 0) {
        if (y == 0) {
            puts("Yes");
            for (int i = 1; i <= n; ++i) {
                for (int j = 1; j <= m; ++j)
                    printf("%d", chess[i][j]);
                puts("");
            }
            exit(0);
        }
        else dfs(n, y - 1);
    }
    else if (x > 0) {
        if (!chess[x + 1][y] && !chess[x][y + 1]) {
            chess[x][y] = 1;
            --a[y];
            dfs(x - 1, y);
            ++a[y];
            chess[x][y] = 0;
        }
        dfs(x - 1, y);
    }
}
int main() {
    scanf("%d%d", &n, &m);
    for (int j = 1; j <= m; ++j) scanf("%d", a + j);
    dfs(n, m);
    puts("No");
}