#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define MOD 1000000007
#define pii pair<int,int>
#define LL long long

using namespace std;

pair<LL,LL> a[1000005];

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n,k;
    cin >> n >> k;
    for (int i=1;i<=n;i++) cin >> a[i].se >> a[i].fi;
    sort (a+1,a+n+1);
    priority_queue<LL> p;
    LL ans=1000000000000000;
    LL h=0,w=0;
    for (int i=1;i<=n;i++) {
        h=a[i].fi;
        w+=a[i].se;
        p.push(a[i].se);
        while (p.size()>k) {
            w-=p.top();
            p.pop();
        }
        if (p.size()==k) ans=min(ans,w*h);
    }
    cout << ans << endl;
    return 0;
}
