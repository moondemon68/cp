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
    queue<int> q;
    for (int i=1;i<=n;i++) {
        int x;
        cin >> x;
        q.push(x);
    }
    bool a[n+5];
    memset (a,0,sizeof(a));
    for (int i=1;i<=n;i++) {
        int x;
        cin >> x;
        int ans=0;
        while (!a[x]) {
            ans++;
            a[q.front()]=1;
            q.pop();
        }
        cout << ans << " ";
    }
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}