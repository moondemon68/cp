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

vector<pii> ans;
vector<char> ansc;

void swapx(pii *a, pii *b) {
    ans.pb(mp((*a).fi,(*a).se));
    ansc.pb('T');
    ans.pb(mp((*b).fi,(*b).se));
    ansc.pb('L');
    (*b).fi--;
    ans.pb(mp((*b).fi,(*b).se));
    ansc.pb('L');
    (*b).fi--;
    ans.pb(mp((*a).fi,(*a).se));
    ansc.pb('P');
}

void swapy(pii *a, pii *b) {
    ans.pb(mp((*a).fi,(*a).se));
    ansc.pb('T');
    ans.pb(mp((*b).fi,(*b).se));
    ansc.pb('D');
    (*b).se--;
    ans.pb(mp((*b).fi,(*b).se));
    ansc.pb('D');
    (*b).se--;
    ans.pb(mp((*a).fi,(*a).se));
    ansc.pb('P');
}

bool stat(pii a, pii b) {
    return (b.se-a.se)*(b.fi-a.fi)<0;
}

void flip(pii *a){
    int tmp = (*a).fi;
    (*a).fi = (*a).se;
    (*a).se = tmp;
}

int main () {
    int n;
    cin >> n;
    pii a[n+5],b[n+5];
    for (int i=1;i<=n;i++) cin >> a[i].fi >> a[i].se;
    for (int i=1;i<=n;i++) cin >> b[i].fi >> b[i].se;
    sort (a+1,a+n+1);
    sort (b+1,b+n+1);
    // swapx
    for (int j=1;j<=n;j++) {
        for (int i=1;i<n;i++) {
            if (stat(a[i],a[i+1])!=stat(b[i],b[i+1])) {
                int l=i,r=i+1;
                while (a[l].fi<a[r].fi-1) {
                    ans.pb(a[l]);
                    ansc.pb('R');
                    a[l].fi++;
                }
                swapx(&a[l],&a[r]);
            }
            sort (a+1,a+n+1);
        }
    }
    // int statc[n+5],statd[n+5];
    // cout << endl;
    // for (int i=1;i<=n;i++) cout << a[i].fi << " " << a[i].se << endl;
    // cout << endl;
    // for (int i=1;i<=n;i++) cout << b[i].fi << " " << b[i].se << endl;

    // swap y
    for (int i=1;i<=n;i++) {
        flip(&a[i]);
        flip(&b[i]);
    }
    sort (a+1,a+n+1);
    sort (b+1,b+n+1);
    for (int i=1;i<=n;i++) {
        flip(&a[i]);
        flip(&b[i]);
    }
    // for (int i=1;i<=n;i++) cout << a[i].fi << " " << a[i].se << endl;

    for (int j=1;j<=n;j++) {
        for (int i=1;i<n;i++) {
            if (stat(a[i],a[i+1])!=stat(b[i],b[i+1])) {
                int l=i,r=i+1;
                while (a[l].se<a[r].se-1) {
                    ans.pb(a[l]);
                    ansc.pb('U');
                    a[l].se++;
                }
                swapy(&a[l],&a[r]);
            }
            for (int i=1;i<=n;i++) {
                flip(&a[i]);
            }
            sort(a+1,a+n+1);
            for (int i=1;i<=n;i++) {
                flip(&a[i]);
            }
        }
    }
    // int statc[n+5],statd[n+5];
    // cout << endl;
    // for (int i=1;i<=n;i++) cout << a[i].fi << " " << a[i].se << endl;
    // sort (b+1,b+n+1);
    // cout << endl;
    // for (int i=1;i<=n;i++) cout << b[i].fi << " " << b[i].se << endl;

    sort (a+1,a+n+1);
    sort (b+1,b+n+1);
    
    // move to target
    for (int i=n;i>=1;i--) {
        while (a[i].fi>b[i].fi) {
            ans.pb(mp(a[i].fi,a[i].se));
            ansc.pb('L');
            a[i].fi--;
        }
        while (a[i].fi<b[i].fi) {
            ans.pb(mp(a[i].fi,a[i].se));
            ansc.pb('R');
            a[i].fi++;
        }
        while (a[i].se>b[i].se) {
            ans.pb(mp(a[i].fi,a[i].se));
            ansc.pb('D');
            a[i].se--;
        }
        while (a[i].se<b[i].se) {
            ans.pb(mp(a[i].fi,a[i].se));
            ansc.pb('U');
            a[i].se++;
        }
    }

    cout << ans.size() << endl;
    for (int i=0;i<ans.size();i++) {
        cout << ans[i].fi << " " << ans[i].se << " " << ansc[i] << endl;
    }
    for (int i=1;i<=n;i++) cout << a[i].fi << " " << a[i].se << endl;
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}