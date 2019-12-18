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
    int a[n+5],b[n+5];
    for (int i=0;i<n;i++) {
        cin >> a[i] >> b[i];
    }
    int k;
    cin >> k;
    for (int i=0;i<n;i++) {
        if (b[i]>=k) {
            cout << n-i << endl;
            return 0;
        } 
    }
    cout << 0 << endl;
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}