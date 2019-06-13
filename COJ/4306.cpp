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
    while (n--) {
        LL a,b,x,y,z;
        cin >> a >> b >> x >> y >> z;
        LL sum=x*y+y*z+x*z;
        sum*=2;
        if (a*b>=sum) cout << "POSSIBLE";
        else cout << "IMPOSSIBLE";
        cout << endl;
    }
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}