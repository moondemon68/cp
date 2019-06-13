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
    LL n,m,ta,tb,k;
    cin >> n >> m >> ta >> tb >> k;
    LL a[n+5];
    for (LL i=1;i<=n;i++) {
        cin >> a[i];
        a[i]+=ta;
    }
    LL b[m+5];
    for (LL i=1;i<=m;i++) cin >> b[i];
    if (k>=n||k>=m) {
        cout << -1 << endl;
        return 0;
    }
    LL best=-1;
    for (LL i=1;i<=n;i++) {
        //cout << a[i] << " ";
        LL req=i-1;
        if (k<req) break;
        LL l=1,h=m,ans=-1;
        while (l<=h) {
            LL mid=(l+h)/2;
            if (a[i]<=b[mid]) {
                ans=mid;
                h=mid-1;
            } else l=mid+1;
        }
        if (ans+k-req>m||ans==-1) {
            cout << -1 << endl;
            return 0;
        } else {
            best=max(best,b[ans+k-req]+tb);
        }
        //cout << req << " " << b[ans+k-req]+tb << " " << b[ans] <<  endl;
    }
    cout << best << endl;
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}