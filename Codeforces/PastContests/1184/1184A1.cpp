#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define MOD 1000000007
#define INF 1234567890
#define pii pair<LL,LL>
#define LL long long
using namespace std;

int main () {
    //clock_t start = clock();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    LL r;
    cin >> r;
    r--;
    vector<LL> c;
    for (LL i=1;i*i<=r;i++) {
        if (r%i==0) {
            c.pb(i);
            c.pb(r/i);
        }
    }
    sort (c.begin(),c.end());
    for (LL i=0;i<c.size();i++) {
        LL x=c[i];
        LL m=r/x;
        //cout << x << " " << m << endl;
        if ((m-x-1)%2==0&&(m-x-1)/2>0) {
            cout << x << " " << (m-x-1)/2 << endl;
            return 0;
        }
    }
    cout << "NO" << endl;
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}