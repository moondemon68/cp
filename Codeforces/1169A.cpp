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
    int n,a,b,x,y;
    cin >> n >> a >> x >> b >> y;
    bool da=0,db=0;
    while (!da&&!db) {
        a++;
        if (a>n) a=1;
        if (a==x) da=1;
        b--;
        if (b<1) b=n;
        if (b==y) db=1;
        if (a==b) {
            cout << "YES" << endl;
            return 0;
        }
    }
    cout << "NO" << endl;
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}