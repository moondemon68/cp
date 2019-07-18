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
    cin >> n  >> k;
    int cnt[k+5];
    memset (cnt,0,sizeof(cnt));
    for (int i=1;i<=n;i++) {
        int x;
        cin >> x;
        cnt[x]++;
    }
    int p=0;
    for (int i=1;i<=k;i++) {
        if (cnt[i]%2==1) p++;
    }
    cout << n-p/2 << endl;
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}