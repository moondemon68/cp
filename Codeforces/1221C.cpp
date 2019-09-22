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
    int tc;
    cin >> tc;
    while (tc--) {
        int c,m,x;
        cin >> c >> m >> x;
        int ans=0;
        int g = min(c,min(m,x));
        ans+=g;
        c-=g;
        m-=g;
        x-=g;
        //cout << c << m << x << endl;
        if (c>m) swap(c,m);
        if (2*c<=m) ans+=c;
        else {
            g=m-c;
            ans+=g;
            c-=g;
            m-=2*g;
            g = c/3;
            ans+=2*g;
            c-=3*g;
            m-=3*g;
            if (c==1&&m==2) ans++;
            else if (c==2&&m==1) ans++;
            else if (c==2&&m==2) ans++;
        }
        cout << ans << endl;
    }
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}