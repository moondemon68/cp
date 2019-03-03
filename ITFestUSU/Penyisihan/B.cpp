#include <bits/stdc++.h>
using namespace std;
typedef long long i64;

struct Loan {
    i64 A, B, K;
    bool operator< (const Loan & q) {
        return B > q.B;
    }
    explicit operator i64() const {
        return A - 1LL * B * K;
    }
};

const int NMAX = 510;
i64 dp[NMAX];

int main()
{
    vector <Loan> v;
    int n;
    cin >> n;
    v.resize(n);

    for (auto & i : v)
        cin >> i.A >> i.B >> i.K;

    sort(v.begin(), v.end());

    for (auto obj : v)
        for (int poz = n; poz >= 0; poz--) {
            dp[poz + 1] = max(dp[poz + 1], dp[poz] + obj.A - poz * obj.B);
            dp[poz] = max(dp[poz], dp[poz] + i64(obj));
        }

    i64 best = 0;
    for (int i = 0; i <= n; i++)
        best = max(best, dp[i]);
    cout << best << '\n';

	return 0;
}