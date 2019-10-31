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
    LL a[50];
    a[0]=1;
    for (int i=1;i<=38;i++) a[i]=a[i-1]*3;
    int tc;
    cin >> tc;
    while (tc--) {
        LL x;
        cin >> x;
        vector<int> v;
        while (x) {
            v.pb(x%3);
            x/=3;
        }
        reverse(v.begin(),v.end());
        // for (int i=0;i<v.size();i++) cout << v[i];
        // cout << endl;
        for (int i=v.size()-1;i>0;i--) {
            if (v[i]==2) {
                for (int j=v.size()-1;j>i;j--) v[j]=0;
                v[i]++;
                for (int j=i;j>0;j--) {
                    if (v[j]==3) {
                        v[j]=0;
                        v[j-1]++;
                    }
                }
            }
        }
        if (v[0]==2) {
            v[0]=0;
            v.insert(v.begin(), 1);
            for (int j=v.size()-1;j>0;j--) v[j]=0;
        }
        // for (int i=0;i<v.size();i++) cout << v[i];
        // cout << endl;
        LL ans=0;
        for (int i=0;i<v.size();i++) {
            ans+=v[i];
            if (i != v.size()-1) ans*=3;
        }
        cout << ans << endl;
    }
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}