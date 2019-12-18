#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define MOD 1000000007
#define pii pair<int,int>
#define LL long long
using namespace std;

priority_queue<int,vector<int>,greater<int>> p[200005];
int main () {
    //clock_t start = clock();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n,k;
    cin >> n >> k;
    for (int i=1;i<=n;i++) {
        int x;
        cin >> x;
        int a=0;
        while (x>0) {
            p[x].push(a);
            a++;
            x/=2;
        }
    }
    int ans=INT_MAX;
    for (int i=0;i<200005;i++) {
        if (p[i].size()>=k) {
            int cnt=0;
            for (int j=1;j<=k;j++) {
                cnt+=p[i].top();
                p[i].pop();
            }
            ans=min(ans,cnt);
        }
    }
    cout << ans << endl;
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}