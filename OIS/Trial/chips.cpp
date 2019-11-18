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
    int tc;
    cin >> tc;
    while (tc--) {
        int a,c,r,g,b;
        cin >> a >> c >> r >> g >> b;
        r++;
        int ans = a * (r*r+g*g+b*b) + c * min(r, min(g,b));
        string win = "RED";
        r--;
        g++;
        if (a * (r*r+g*g+b*b) + c * min(r, min(g,b)) > ans) {
            win = "GREEN";
            ans = a * (r*r+g*g+b*b) + c * min(r, min(g,b));
        }
        g--;
        b++;
        if (a * (r*r+g*g+b*b) + c * min(r, min(g,b)) > ans) {
            win = "BLUE";
            ans = a * (r*r+g*g+b*b) + c * min(r, min(g,b));
        }
        b--;
        cout << win << "\n";
    }
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}