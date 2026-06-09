#include <cstdio>
#include <algorithm>
using namespace std;

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        long long n, x, y, z;
        scanf("%lld %lld %lld %lld", &n, &x, &y, &z);

        // Option 1: no AI, combined speed x+y per hour
        long long noAI = (n + (x + y) - 1) / (x + y);

        // Option 2: AI. During first z hours only Maxim writes (x/hour).
        // After hour z, combined speed is x + 10*y.
        long long ai;
        if (x * z >= n) {
            // finished during/at setup, only Maxim contributing
            ai = (n + x - 1) / x;
        } else {
            long long rem = n - x * z;          // lines still needed after setup
            long long sp = x + 10 * y;           // speed after setup
            ai = z + (rem + sp - 1) / sp;
        }

        printf("%lld\n", min(noAI, ai));
    }
    return 0;
}
