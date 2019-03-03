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
    clock_t start = clock();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;
    int a[n+5];
    for (int i=1;i<=n;i++) cin >> a[i];
    deque<int> ans;
    sort (a+1,a+n+1);
    for (int i=1;i<=n;i++) {
        if (i%2==0) ans.push_front(a[i]); else ans.push_back(a[i]);
    }
    for (int i=1;i<=n;i++) {
        cout << ans.front() << " ";
        ans.pop_front();
    }
    cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}