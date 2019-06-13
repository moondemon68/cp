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
    int tc;
    cin >> tc;
    while (tc--) {
        int n;
        cin >> n;
        int z=0,o=0,t=0;
        for (int i=1;i<=n;i++) {
            int x;
            cin >> x;
            if (x%3==0) z++;
            else if (x%3==1) o++;
            else t++;
        }
        int ans=z;
        int p=min(o,t);
        ans+=p;
        ans+=(o-p)/3+(t-p)/3;
        int ans2=z;
        ans2+=o/3+t/3;
        o/=3;
        t/=3;
        ans2+=min(o,t);
        cout << max(ans,ans2) << endl;
    }
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}