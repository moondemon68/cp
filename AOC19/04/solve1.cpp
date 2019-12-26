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

bool correct(int x) {
    vector<int> v;
    while (x) {
        v.pb(x%10);
        x/=10;
    }
    reverse(v.begin(), v.end());
    int d = 0;
    for (int i=0;i<5;i++) {
        if (v[i] == v[i+1]) d++;
        if (v[i] > v[i+1]) return 0;
    }
    return d > 0;
}

int main () {
    //clock_t start = clock();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int x,y;
    cin >> x >> y;
    int ans = 0;
    for (int i=x;i<=y;i++) {
        if (correct(i)) ans++;
    }
    cout << ans << endl;
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}