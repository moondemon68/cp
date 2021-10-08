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
    int n;
    cin >> n;
    vector<int> v;
    while (n) {
        v.pb(n%2);
        n/=2;
    }
    reverse(v.begin(), v.end());
    int b[35];
    memset(b,0,sizeof(b));
    int a[35][35];
    memset(a,0,sizeof(a));
    int cur = 1, maxcur = 0;
    for (int i=0;i<v.size();i++) {
        if (v[i] == 1) {
            b[i] = cur;
            cur += 2;
            maxcur = max(cur, maxcur);
        }
    }
    cur = 2;
    for (int i=0;i<v.size();i++) {
        if (v[i] == 0) {
            b[i] = cur;
            if (cur < maxcur-1) cur += 2;
        }
    }
    for (int i=0;i<v.size();i++) cout << v[i] << " ";
    cout << endl;
    for (int i=0;i<v.size();i++) cout << b[i] << " ";
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}