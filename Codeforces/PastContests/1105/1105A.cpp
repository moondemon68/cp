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
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;
    int a[n+5];
    for (int i=1;i<=n;i++) cin >> a[i];
    int ans=INT_MAX,anst=0;
    for (int t=1;t<=100;t++) {
        int sum=0;
        for (int i=1;i<=n;i++) {
            if (a[i]<t) sum+=t-a[i]-1;
            else if (a[i]==t) sum+=0;
            else sum+=a[i]-t-1;
        }
        if (sum<ans) {
            ans=sum;
            anst=t;
        }
    }
    
    cout << anst << " " << ans << endl;
    return 0;
}
