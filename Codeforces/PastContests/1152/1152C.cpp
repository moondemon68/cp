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
    LL a,b;
    cin >> a >> b;
    if (a>b) swap(a,b); 
    vector<LL> d;
    for (int i=1;i*i<=(b-a);i++) {
        if ((b-a)%i==0) {
            d.pb(i);
            d.pb((b-a)/i);
        }
    }
    LL ans=0,mini=a*b/__gcd(a,b);
    for (int i=0;i<d.size();i++) {
        LL k=d[i]-(a%d[i]);
        LL p=(a+k)*(b+k)/__gcd(a+k,b+k);
        //cout << d[i] << " " << p << endl;
        if (p<mini) {
            ans=k;
            mini=p;
        } else if (p==mini) {
            ans=min(d[i],ans);
        }
    }
    //cout << mini << endl;
    cout << ans << endl;
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}