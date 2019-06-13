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
    deque<pii> p;
    int tot=0;
    for (int i=1;i<=n;i++) {
        string s;
        cin >> s;
        if (s=="add") {
            int x,y;
            cin >> x >> y;
            p.push_front(mp(x,y));
            tot+=y;
            cout << tot << endl;
        } else if (s=="del") {
            cout << p.front().fi << endl;
            int x;
            cin >> x;
            tot-=x;
            while (x>0) {
                if (x>=p.front().se) {
                    x-=p.front().se;
                    p.pop_front();
                } else {
                    p.front().se-=x;
                    x=0;
                }
            }
        } else if (s=="adx") {
            int x;
            cin >> x;
            for (int j=0;j<p.size();j++) p[j].fi+=x;
        } else {
            int x;
            cin >> x;
            for (int j=0;j<p.size();j++) p[j].fi-=x;
        }
        //for (auto c:p) cout << c << " ";
        //cout << endl;
    }
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}