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
    int n,k;
    cin >> n >> k;
    int a[2*n+5];
    for (int i=1;i<=2*n;i++) cin >> a[i];
    sort (a+1,a+2*n+1);
    bool y=1;
    for (int i=1;i<=2*n;i+=2) {
        if (a[i+1]-a[i]<=k) {

        } else y=0;
    }
    if (y) cout << "Ya" << endl;
    else cout << "Tidak" << endl;
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}