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
    LL a[n+5];
    memset (a,0,sizeof(a));
    for (LL i=1;i<=n;i++) {
        int x;
        cin >> x;
        a[x]=i;
    }
    int cnt[n+5];
    memset (cnt,0,sizeof(cnt));
    for (int i=1;i<n;i++) {
        cnt[min(a[i],a[i+1])]++;
        cnt[max(a[i],a[i+1])]--;
        //for (int j=min(a[i],a[i+1]);j<max(a[i],a[i+1]);j++)  cnt[j]++;
    }
    for (int i=1;i<n;i++) {
        cnt[i+1]+=cnt[i];
    }
    //for (int i=1;i<=n;i++) cout << cnt[i] << " ";
    sort (cnt+1,cnt+n+1);
    reverse(cnt+1,cnt+n+1);
    int num=0;
    for (int i=1;i<=n;i++) {
        num+=cnt[i];
        if (num>=k) {
            cout << i << endl;
            return 0;
        }
    }
    cout << -1 << endl;
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}