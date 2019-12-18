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
    LL a[100005];
    for (int i=1;i<=n;i++) {
        cin >> a[i];
    }
    LL b[100005];
    LL ans=0,mini=INT_MAX;
    for (int i=1;i<=n;i++) {
        b[i]=(a[i]-i+n)/n;
        b[i]=i+b[i]*n;
        if (b[i]<mini) {
            ans=i;
            mini=b[i];
        }
        //cout << b[i] << " ";
    }
    cout << ans << endl;
    return 0;
}
