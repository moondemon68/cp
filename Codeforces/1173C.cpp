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
    int n;
    cin >> n;
    int a[n+5];
    for (int i=1;i<=n;i++) cin >> a[i];
    int b[n+5];
    for (int i=1;i<=n;i++) cin >> b[i];
    
    int z=0;
    for (int i=1;i<=n;i++) if (a[i]==0) z++;
    queue<int> q;
    for (int i=1;i<=n;i++) q.push(b[i]);
    int ma=0;
    while (z>0) {
        z--;
        if (q.front()==0) z++;
        q.pop();
        ma++;
    }
    ma+=n;
    //cout << ma << endl;
    while (!q.empty()) q.pop();
    for (int i=1;i<=n;i++) q.push(b[i]);
    priority_queue<int,vector<int>,greater<int>> p;
    z=0;
    for (int i=1;i<=n;i++) if (a[i]==0) z++; else p.push(a[i]);
    int ans=0,x=1;
    int o=0;
    for (int i=1;i<=n;i++) if (b[i]==1) o=i;
    if (o!=0) {
        for (int i=o;i<=n;i++) {
            if (x==b[i]) x++; else {
                x=1; break;
            }
        }
    }
    if (x!=n+1&&p.empty()) x=1;
    while (x<=n) {
        if (p.top()==1&&x>1) {
            cout << ans+n << endl;
            return 0;
        }
        ans++;
        if (!p.empty()&&p.top()==x) {
            p.pop();
            q.push(x);
            if (q.front()!=0) p.push(q.front());
            q.pop();
            x++;
        } else {
            if (q.front()!=0) p.push(q.front());
            q.push(0);
            q.pop();
        }
    }
    cout << ans << endl;
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}