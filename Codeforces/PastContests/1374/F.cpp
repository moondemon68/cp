#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define MOD 1000000007
#define INF 1234567890
#define pii pair<int,int>
#define LL long long
using namespace std;

int main () {
    //clock_t start = clock();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int tc;
    cin >> tc;
    while (tc--) {
        int n;
        cin >> n;
        int a[n+5];
        for (int i=1;i<=n;i++) cin >> a[i];
        vector<int> ans;
        for (int j=1;j<=n;j++) {
            int minx = a[j], mini = j;
            for (int i=j+1;i<=n;i++) {
                if (a[i] < minx) {
                    minx = a[i];
                    mini = i;
                }
            }
            if (mini == j) continue;
            while (mini > j+1) {
                ans.pb(mini-2);
                int tmp = a[mini];
                a[mini] = a[mini-1];
                a[mini-1] = a[mini-2];
                a[mini-2] = tmp;
                mini -= 2;
            }
            if (mini == j+1 && j != n-1) {
                ans.pb(mini-1);
                ans.pb(mini-1);
                mini++;
                int tmp = a[mini];
                a[mini] = a[mini-1];
                a[mini-1] = a[mini-2];
                a[mini-2] = tmp;

                tmp = a[mini];
                a[mini] = a[mini-1];
                a[mini-1] = a[mini-2];
                a[mini-2] = tmp;

                mini-=2;
            }
        }

        if (a[n-2] <= a[n-1] && a[n-1] <= a[n]) {
            cout << ans.size() << endl;
            for (int i=0;i<ans.size();i++) cout << ans[i] << " ";
            cout << endl;
        } else {
            // int p = -1;
            // for (int i=1;i<n;i++) {
            //     if (a[i] == a[i+1]) p = i;
            // }
            // if (p == -1) {
            //     cout << -1 << endl;
            //     continue;
            // }
            // for (int i=0;i<n-p-1;i++) {
            //     if (i == 0) {
            //         ans.pb(p+i);
            //         int mini = p+i+2;
            //         int tmp = a[mini];
            //         a[mini] = a[mini-1];
            //         a[mini-1] = a[mini-2];
            //         a[mini-2] = tmp;
            //     }
            //     ans.pb(p+i);
            //     int mini = p+i+2;
            //     int tmp = a[mini];
            //     a[mini] = a[mini-1];
            //     a[mini-1] = a[mini-2];
            //     a[mini-2] = tmp;
            // }
            // for (int j=1;j<=n;j++) {
            //     int minx = a[j], mini = j;
            //     for (int i=j+1;i<=n;i++) {
            //         if (a[i] < minx) {
            //             minx = a[i];
            //             mini = i;
            //         }
            //     }
            //     if (mini == j) continue;
            //     while (mini > j+1) {
            //         ans.pb(mini-2);
            //         int tmp = a[mini];
            //         a[mini] = a[mini-1];
            //         a[mini-1] = a[mini-2];
            //         a[mini-2] = tmp;
            //         mini -= 2;
            //     }
            //     if (mini == j+1 && j != n-1) {
            //         ans.pb(mini-1);
            //         ans.pb(mini-1);
            //         mini++;
            //         int tmp = a[mini];
            //         a[mini] = a[mini-1];
            //         a[mini-1] = a[mini-2];
            //         a[mini-2] = tmp;

            //         tmp = a[mini];
            //         a[mini] = a[mini-1];
            //         a[mini-1] = a[mini-2];
            //         a[mini-2] = tmp;

            //         mini-=2;
            //     }
            // }
            for (int i = n - 2; i >= 1; i--) {
                swap(a[i], a[i + 2]);
                swap(a[i + 2], a[i + 1]);
                ans.pb(i);
                if (a[i] <= a[i + 1]) break;
            }
            bool y = 1;
            for (int i=1;i<n;i++) {
                if (a[i] > a[i+1]) y = 0;
            }
            if (!y) {
                cout << -1 << endl;
                continue;
            }
            cout << ans.size() << endl;
            for (int i=0;i<ans.size();i++) cout << ans[i] << " ";
            cout << endl;
            // for (int i=1;i<=n;i++) cout << a[i] << " ";
            // cout << endl;
        }
    }
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}