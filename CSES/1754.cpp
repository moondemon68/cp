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
        int a,b;
        cin >> a >> b;
        if ((a+b)%3!=0) cout << "NO" << endl;
        else {
            if (a>b) swap(a,b);
            if (b<=2*a) cout << "YES" << endl;
            else cout << "NO" << endl;
        }
    }
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}