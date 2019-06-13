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
    deque<int> d;
    for (int i=1;i<=n;i++) {
        string s;
        cin >> s;
        if (s=="push_front") {
            int x;
            cin >> x;
            d.push_front(x);
        } else if (s=="push_back") {
            int x;
            cin >> x;
            d.push_back(x);
        } else if (s=="pop_back") {
            d.pop_back();
        } else {
            d.pop_front();
        }
    }
    for (int i=0;i<d.size();i++) cout << d[i] << endl;
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}