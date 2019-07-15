//Kekacauan Antri Sembako
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
    deque<string> d;
    int n;
    cin >> n;
    while (n--) {
        int x;
        cin >> x;
        if (x==1) {
            string s;
            cin >> s;
            d.push_front(s);
        } else if (x==2) {
            string s;
            cin >> s;
            d.pb(s);
        } else if (x==3) {
            cout << d.front() << endl;
            d.pop_front();
        } else {
            cout << d.back() << endl;
            d.pop_back();
        }
    }
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}