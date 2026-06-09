#include <cstdio>

int s[4] = {0, 0, 1, 3};

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        int n;
        scanf("%d", &n);

        if (n == 2) {
            printf("1 2 1 1 2 2 1 2\n");
            continue;
        }
        if (n == 3) {
            printf("1 1 2 1 2 3 1 3 2 2 3 3\n");
            continue;
        }

        // 4 blocks of length n. Block b holds number ((c - s[b]) mod n) + 1 at
        // column c. The three consecutive gaps of each x are n+0, n+1, n+2 in
        // the bulk (and remain pairwise distinct at the wrap boundaries).
        for (int b = 0; b < 4; b++) {
            for (int c = 0; c < n; c++) {
                int x = (((c - s[b]) % n) + n) % n + 1;
                printf("%d ", x);
            }
        }
        printf("\n");
    }
    return 0;
}
