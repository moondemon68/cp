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
    int a[n+5];
    for (int i=1;i<=n;i++) cin >> a[i];
    sort (a+1,a+n+1);
    int ans=INT_MAX;
    for (int i=0;i<=200000;i++) {
        int cnt=0,num=0;
        for (int j=1;j<=n;j++) {
            if (a[j]<i||num>=k) continue;
            else {
                int p=0,x=a[j];
                while (x>i) {
                    x/=2;
                    p++;
                } 
                if (x==i) {
                    cnt+=p;
                    num++;
                }
            }
        }
        if (num>=k) ans=min(ans,cnt); 
    }
    cout << ans << endl;
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}