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
    clock_t start = clock();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int b,k;
    cin >> b >> k;
    bool p=0;
    int a[k+5];
    for (int i=1;i<=k;i++) {
        cin >> a[i];
    }
    if (b%2==0) {
        if (a[k]%2==0) p=0; else p=1;
    } else {
        for (int i=1;i<=k;i++) {
            if (a[i]%2==1) p=!p;
        }
    }
    if (p) cout << "odd" << endl; else cout << "even" << endl;
    cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}