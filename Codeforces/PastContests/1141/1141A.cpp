#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define MOD 1000000007
#define pii pair<int,int>
#define LL long long
using namespace std;

int main () {
    //clock_t start = clock();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    LL n,m;
    cin >> n >> m;
    if (m%n!=0) {
        cout << "-1" << endl;
        return 0;
    }
    LL x=m/n;
    int ans=0;
    while (x!=1&&x%2==0) {
        ans++;
        x/=2;
    }
    while (x!=1&&x%3==0) {
        ans++;
        x/=3;
    }
    if (x!=1) {
        cout << "-1" << endl;
    } else {
        cout << ans << endl;
    }
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}