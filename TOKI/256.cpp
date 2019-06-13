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
    deque<int> q;
    int n;
    cin >> n;
    bool v=0;
    for (int i=1;i<=n;i++) {
        string s;
        cin >> s;
        if (s=="add"&&!v) {
            int x,y;
            cin >> x >> y;
            while (y--) q.push_front(x);
            cout << q.size() << endl;
        } else if (s=="add"&&v) {
            int x,y;
            cin >> x >> y;
            while (y--) q.push_back(x);
            cout << q.size() << endl;
        } else if (s=="del"&&v) {
            cout << q.front() << endl;
            int x;
            cin >> x;
            while (x--) q.pop_front();
        } else if (s=="del"&&!v) {
            cout << q.back() << endl;
            int x;
            cin >> x;
            while (x--) q.pop_back();
        } else {
            v=!v;
        }
    }
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}