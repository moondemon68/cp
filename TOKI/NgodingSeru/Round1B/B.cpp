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
    int g;
    cin >> g;
    for (int n=1;n<=g;n++) {
        for (int f=1;f<=n;f++) {
            int a[n+5];
            for (int i=1;i<=n;i++) a[i]=i;
            int ans=0;
            for (int i=1;i<(1<<n);i++) {
                vector<int> v;
                for (int j=0;j<n;j++) {
                    if (i&(1<<j)) {
                        v.push_back(a[j+1]);
                    }
                }
                bool y=1;
                for (int j=0;j<(int)v.size();j++) {
                    if (!y) break;
                    for (int k=j+1;k<(int)v.size();k++) {
                        if (__gcd(v[j],v[k])!=f) {
                            y=0;
                            break;
                        }
                    }
                }
                if (y) ans=max(ans,(int)v.size());
            }
            cout << n << " " << f << " " << ans << endl;
        }
    } 
    
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}