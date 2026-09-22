#include <stdio.h>

int main(void) {
    int n, k;
    scanf("%d %d", &n, &k);

    static int a[100005];
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    long long window_sum = 0;
    for (int i = 0; i < k; i++) {
        window_sum += a[i];
    }

    long long max_sum = window_sum;

    for (int i = k; i < n; i++) {
        window_sum += a[i] - a[i - k];
        if (window_sum > max_sum) {
            max_sum = window_sum;
        }
    }

    printf("%lld\n", max_sum);

    return 0;
}
