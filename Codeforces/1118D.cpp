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
    int n;
    LL m;
    cin >> n >> m;
    int a[n+5];
    memset (a,0,sizeof(a));
    for (int i=1;i<=n;i++) {
        cin >> a[i];
    }
    sort (a+1,a+n+1);
    reverse(a+1,a+n+1);
    LL ans=-1,l=1,h=n;
    while (l<=h) {
        LL mid=(l+h)/2,cnt=0;
        int cur=1,k=1,curr=1;
        bool y=0;
        while (curr<=n) {
            cnt+=max(0,a[curr]-k+1);
            cur++;
            curr++;
            if (cur>mid) {
                k++;
                cur-=mid;
            }
        }
        //cout << cnt << endl;
        if (cnt>=m) {
            y=1;
        }
        if (y) {
            ans=mid;
            h=mid-1;
        } else {
            l=mid+1;
        }
    }
    cout << ans << endl;
    cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}