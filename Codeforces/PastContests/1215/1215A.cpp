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
    int a1,a2,k1,k2,n;
    cin >> a1 >> a2 >> k1 >> k2 >> n;
    cout << max(0,n-(k1-1)*a1-(k2-1)*a2) << " ";
    if (k1>k2) {
        swap(k1,k2);
        swap(a1,a2);
    }
    if (n<=a1*k1) cout << n/k1 << endl;
    else cout << a1 + (n-a1*k1)/k2 << endl;
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}