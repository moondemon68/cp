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
    int n;
    cin >> n;
    LL a[n+5];
    for (int i=1;i<=n;i++) cin >> a[i];
    LL b[n+5];
    for (int i=1;i<=n;i++) cin >> b[i];
    LL tota=0,totb=0;
    for (int i=1;i<=n;i++) {
        tota+=a[i];
        totb+=b[i];
    }
    if (tota!=totb) {
        cout << "NO" << endl;
        return 0;
    }
    pair<LL,int> s[n+5],t[n+5];
    for (int i=1;i<=n;i++) {
        s[i]=mp(a[i],i);
        t[i]=mp(b[i],i);
    }
    sort (s+1,s+n+1);
    sort (t+1,t+n+1);
    int x=n;
    for (int i=1;i<=n;i++) {
        while (s[i].fi<t[i].fi) {
            LL d=t[i].fi-s[i].fi,lim=t[x].fi-s[x].fi;
            if (d<s[x].fi) {
                s[x].fi-=min(d,lim);
                s[i].fi+=min(d,lim);
                d-=min(d,lim);
            } else {
                s[i].fi+=s[x].fi;
                s[x].fi=0;
                x--;
            }
        }
        for (int j=1;j<=n;j++) cout << s[j].fi << " ";
        cout << endl;
    }
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}