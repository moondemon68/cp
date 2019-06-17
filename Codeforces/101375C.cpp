#include <bits/stdc++.h>
#define x first.first
#define y first.second
#define r second
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
    vector<pair<pii,int>> p;
    while (q--) {
        char s;
        cin >> s;
        int a,b,c;
        cin >> a >> b >> c;
        if (s=='A') {
            bool yes=1;
            for (int i=0;i<p.size();i++) {
                int d=(a-p[i].x)*(a-p[i].x)+(b-p[i].y)*(b-p[i].y),rad=(c+p[i].r)*(c+p[i].r);
                if (d>=rad) {
                    yes=1;
                } else {
                    yes=0;
                    break;
                }
            }
            if (yes) {
                p.pb(mp(mp(a,b),c));
                cout << "Ok" << endl;
            } else {
                cout << "No" << endl;
            }
        } else {
            bool done=0;
            for (int i=0;i<p.size();i++) {
                if (a==p[i].x&&b==p[i].y&&c==p[i].r) {
                    done=1;
                    p.erase(p.begin()+i);
                    break;
                }
            }
            if (done) {
                cout << "Ok" << endl;
            } else {
                cout << "No" << endl;
            }
        }
    }
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}