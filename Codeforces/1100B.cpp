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
    int n,m;
    cin >> n >> m;
    int a[100005];
    for (int i=1;i<=m;i++) cin >> a[i];
    int cnt[100005];
    memset (cnt,0,sizeof(cnt));
    set<int> s;
    int contest=0;
    for (int i=1;i<=m;i++) {
        s.insert(a[i]);
        cnt[a[i]]++;
        if (s.size()==n) {
            cout << 1;
            contest++;
            for (int j=1;j<=n;j++) {
                if (cnt[j]<=contest) s.erase(j);
            }
        } else cout <<0;

    }
    return 0;
}
