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
    LL n, p;
    cin >> n >> p;
    for (LL i=1;i<=10000;i++) {
        LL target = n - p * i;
        if (target <= 0) continue;
        vector<int> v;
        while (target) {
            v.pb(target % 2);
            target /= 2;
        }
        // reverse(v.begin(), v.end());
        // for (int j=0;j<v.size();j++) cout << v[j] << " ";
        // cout << endl;
        int x=0;
        for (int j=0;j<v.size();j++) {
            x+=v[j];
        }
        if (x <= i && (1<<(int)v.size() - 1) >= i) {
            cout << i << endl;
            return 0;
        }
    }
    cout << -1 << endl;
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}