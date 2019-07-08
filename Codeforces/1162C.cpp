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
    int a[k+5];
    for (int i=1;i<=k;i++) cin >> a[i];
    int ans[n+5];
    set<int> s;
    for (int i=1;i<=k;i++) s.insert(a[i]);
    int first[n+5],last[n+5];
    memset (first,0,sizeof(first));
    memset (last,0,sizeof(last));
    for (int i=1;i<=k;i++) {
        last[a[i]]=i;
    }
    for (int i=k;i>=1;i--) {
        first[a[i]]=i;
    }
    int answer=n-s.size();
    //cout << answer << endl;
    for (int i=1;i<=n;i++) {
        if (i>1) {
            if (first[i]>last[i-1]||first[i]==0||last[i-1]==0) answer++;
        }
        if (i<n) {
            if (first[i]>last[i+1]||first[i]==0||last[i+1]==0) answer++;
        }
    }
    cout << answer << endl;
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}