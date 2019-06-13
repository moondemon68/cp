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
    int n,m,k;
    cin >> n >> m >> k;
    int a[n+5];
    int ans=n;
    priority_queue<int,vector<int>,greater<int>> p;
    for (int i=1;i<=n;i++) {
        cin >> a[i];
    }
    for (int i=1;i<n;i++) p.push(a[i+1]-a[i]);
    int x=n;
    while (x>k) {
        ans--;
        ans+=p.top();
        p.pop();
        x--;
    }
    cout << ans << endl;
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}