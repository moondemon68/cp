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
    int a[n+5],b[n+5];
    for (int i=1;i<=n;i++) {
        cin >> a[i];
    }
    for (int i=1;i<=n;i++) cin >> b[i];
    int cnt[100005];
    memset (cnt,0,sizeof(cnt));
    for (int i=1;i<=n;i++) {
        cnt[a[i]]++;
        cnt[b[i]]++;
    }
    int maxi=0;
    for (int i=1;i<=100000;i++) {
        if (cnt[i]>maxi) maxi=cnt[i];
    }
    if (maxi-n<=k) cout << "Ya" << endl;
    else cout << "Tidak" << endl;
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}