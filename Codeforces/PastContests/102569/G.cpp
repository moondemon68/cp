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

int ans[1005];

void query(vector<int> a, vector<int> b) {
    if (a.size() == 0 || b.size() == 0) return;
    vector<int> a_less, a_more, b_less, b_more;
    int p = 0, q = -1;
    for (int i=0;i<b.size();i++) {
        cout << "? " << a[p] << " " << b[i] << endl;
        char c;
        cin >> c;
        if (c == '>') {
            b_less.pb(b[i]);
        } else if (c == '<') {
            b_more.pb(b[i]);
        } else {
            q = i;
            ans[a[p]] = b[q];
        }
    }

    for (int i=0;i<a.size();i++) {
        cout << "? " << a[i] << " " << b[q] << endl;
        char c;
        cin >> c;
        if (c == '>') {
            a_more.pb(a[i]);
        } else if (c == '<') {
            a_less.pb(a[i]);
        }
    }

    query(a_less, b_less);
    query(a_more, b_more);
}

int main () {
    //clock_t start = clock();
    // ios_base::sync_with_stdio(false);
    // cin.tie(NULL);
    // cout.tie(NULL);
    srand(time(NULL));
    int n;
    cin >> n;
    vector<int> p,q;
    for (int i=1;i<=n;i++) {
        p.pb(i);
        q.pb(i);
    }
    query(p,q);
    cout << "! ";
    for (int i=1;i<=n;i++) cout << ans[i] << " ";
    cout << endl;
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}