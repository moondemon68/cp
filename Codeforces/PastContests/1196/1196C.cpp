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
    int q;
    cin >> q;
    while (q--) {
        int n;
        cin >> n;
        int a=-100000,b=100000,c=-100000,d=100000;
        for (int i=1;i<=n;i++) {
            int x,y,da,db,dc,dd;
            cin >> x >> y >> da >> db >> dc >> dd;
            int na=x,nb=x,nc=y,nd=y;
            if (da==1) na=-100000;
            if (db==1) nd=100000;
            if (dc==1) nb=100000;
            if (dd==1) nc=-100000;
            a=max(a,na);
            b=min(b,nb);
            c=max(c,nc);
            d=min(d,nd);
        }
        if (a>b||c>d) cout << 0; else cout << 1 << " " << a << " " << c;
        cout << endl;
    }
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}