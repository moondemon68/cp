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
    LL a[n+5];
    LL sum=0;
    for (int i=1;i<=n;i++) {
        cin >> a[i];
        sum+=a[i];
    }
    sort (a+1,a+n+1);
    cout << a[1] << " " << a[n] << " " << sum << endl;
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}