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

bool cmp(pii a,pii b) {
    if (a.fi==b.fi) return a.se<b.se;
    else return a.fi>b.fi;
}

int main () {
    //clock_t start = clock();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    pii a[4];
    int n;
    cin >> n;
    for (int i=1;i<=n;i++) {
        int x;
        cin >> x;
        a[i%4].fi+=x;
    }
    a[0].se=4;a[1].se=1;a[2].se=2;a[3].se=3;
    sort (a,a+4,cmp);
    if (a[0].se==1) cout << 'A';
    else if (a[0].se==2) cout << 'B';
    else if (a[0].se==3) cout << 'C';
    else cout << "D";
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}