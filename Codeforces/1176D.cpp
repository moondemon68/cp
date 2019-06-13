#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define MOD 1000000007
#define pii pair<int,int>
#define LL long long
using namespace std;

bitset<3000000> prima;
int cnt[3000005];
int pas[200005];
int main () {
    //clock_t start = clock();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    vector<int> p;
    prima.set();
    for (int i=2;i*i<=3000000;i++) {
        for (int j=i*i;j<=3000000;j+=i) {
            prima[j]=0;
        }
    }
    p.pb(1);
    for (int i=2;i<=3000000;i++) if (prima[i]) p.pb(i);
    int n;
    cin >> n;
    int a[2*n+5];
    for (int i=1;i<=2*n;i++) cin >> a[i];
    sort (a+1,a+2*n+1);
    for (int i=1;i<=2*n;i++) cnt[a[i]]++;
    for (int i=2;i<=200000;i++) {
        if (prima[i]) continue;
        for (int j=1;j<p.size();j++) {
            if (i%p[j]==0) {
                pas[i]=i/p[j];
                break;
            }
        }
    }
    for (int i=200000;i>=2;i--) {
        while (cnt[p[i]]>0&&cnt[i]>0) {
            cout << i << " ";
            cnt[p[i]]--;
            cnt[i]--;
        }
        if (!prima[i]) {
            while (cnt[pas[i]]>0&&cnt[i]>0) {
                cout << i << " ";
                cnt[pas[i]]--;
                cnt[i]--;
            }
        }
    }
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}