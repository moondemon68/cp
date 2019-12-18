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
        int n;
        cin >> n;
        bool y=0;
        priority_queue< int,vector<int>,greater<int> > p;
        for (int i=1;i<=n;i++) {
            int x;
            cin >> x;
            if (x == 2048) y = 1;
            p.push(x);
        }
        while (p.size()>=2&&!y) {
            //cout << p.top() << endl;
            int x = p.top();
            p.pop();
            int yy= p.top();
            p.pop();
            if (x == 2048 || yy == 2048) {
                y=1;
                break;
            }
            if (x == yy) p.push(x+yy);
            else p.push(yy);
        }
        if (p.top() == 2048) y=1;
        if (y) cout << "yes" << endl;
        else cout << "No" << endl;
    }
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}