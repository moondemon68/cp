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
    int cnt[10],a[100005];
    memset (cnt,0,sizeof(cnt));
    for (int i=1;i<=n;i++) {
      cin >> a[i];
      cnt[a[i]]++;
    }
    int maxi=0,sup=0;
    for (int i=0;i<=9;i++) {
      if (cnt[i]>maxi) {
        maxi=cnt[i];
        sup=i;
      }
    }
    int superb=0;
    for (int i=0;i<=9;i++) if (i!=sup) superb+=cnt[i];
    cout << superb << endl;
    return 0;
}
