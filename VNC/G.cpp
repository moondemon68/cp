#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;
int n;
long long a[N];
long long pre[N], suf[N];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    long long ans = 0;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        ans += abs(a[i]);
    }
    sort(a + 1, a + 1 + n);
    for (int i = 1; i <= n; i++) {
        pre[i] += pre[i - 1] + abs(a[i]);
    }
    for (int i = n; i >= 1; i--) {
        suf[i] += suf[i + 1] + abs(a[i]);
    }
    a[0] = 1e9 + 5;
    // test every point
    for (int i = 1; i <= n; i++) {
        if (a[i] == a[i - 1]) continue;
        if (a[i] < 0) {
            // find points behind it
            long long cur = pre[i - 1] + a[i] * (1LL) * (i - 1);

            // find points ahead of it but is nearer to a[i] than 0
            int pos = upper_bound(a + 1, a + 1 + n, a[i] / 2) - a;
            cur += (pre[pos - 1] - pre[i - 1]);

            // find points ahead of it but is nearer to 0
            cur += suf[pos];

            ans = min(ans, cur)
            // I haven't check if this is true or not though lol
        } else if (a[i] > 0) {
            // do the same procedure with your logic UwU
        }
    }

    return 0;
}