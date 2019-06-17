#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define MOD 1000000007
#define INF 1234567890
#define pii pair<int,int>
#define LL long long
using namespace std;

vector<int> xmp(vector<int> a) {
    vector<int> ret;
    for (int i=0;i<a.size();i++) {
        for (int j=0;j<a.size();j++) {
            ret.pb(a[i]^a[j]);
        }
    }
    return ret;
}

int main () {
    //clock_t start = clock();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n,m;
    cin >> n >> m;
    if (n==1) {
        cout << 0 << endl;
        return 0;
    }
    vector<int> a;
    for (int i=1;i<=n;i++) {
        int x;
        cin >> x;
        a.pb(x);
    }
    for (int i=1;i<=m;i++) a=xmp(a);
    int ans=0;
    int cnt[100005];
    memset (cnt,0,sizeof(cnt));
    for (int i=0;i<a.size();i++) {
        cnt[a[i]]++;
        ans+=a[i];
    }
    int p=0;
    for (int i=0;i<100000;i++) {
        if (cnt[i]>0) cout << i << " " << cnt[i] << endl;
    }
    cout << ans << endl;
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}