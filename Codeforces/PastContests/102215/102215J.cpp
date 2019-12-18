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
    LL a[n+5],t[n+5];
    vector<LL> b;
    for (int i=1;i<=n;i++) {
        LL x,y,z;
        cin >> x >> y >> z;
        t[i]=x+y+z;
        vector<LL> p;
        p.pb(x);
        p.pb(y);
        p.pb(z);
        sort (p.begin(),p.end());
        b.pb(p[0]+p[1]+2);
        a[i]=p[0]+p[1]+2;
    }
    b.pb(0);
    sort (b.begin(),b.end());
    /*
    cout << "__________________________" << endl;
    for (int i=1;i<=n;i++) cout << a[i] << " ";
    cout << endl;
    for (int i=1;i<=n;i++) cout << t[i] << " ";
    cout << endl;
    cout << "__________________________" << endl;
    */
    for (int i=1;i<=n;i++) {
        int l=1,h=n,ans=0;
        while (l<=h) {
            int m=(l+h)/2;
            if (t[i]>=b[m]) {
                ans=m;
                l=m+1;
            } else h=m-1;
        }
        if (a[i]<=b[ans]) ans--;
        cout << ans << " ";
    }
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}