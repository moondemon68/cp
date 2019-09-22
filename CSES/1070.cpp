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
    if (n==1) {
        cout << 1 << endl;
        return 0;
    }
    if (n<=3) {
        cout << "NO SOLUTION" << endl;
        return 0;
    }
    for (int i=2;i<=n;i+=2) cout << i << " ";
    for (int i=1;i<=n;i+=2) cout << i << " ";
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}