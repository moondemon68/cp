//Pattern Find - KMP
#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define MOD 1000000007
#define pii pair<int,int>
#define LL long long
using namespace std;

int pref[1000005];

int main () {
    //clock_t start = clock();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int tc;
    cin >> tc;
    while (tc--) {
        memset(pref,0,sizeof(pref));
        string s,t;
        cin >> s >> t;
        int l=0;
        pref[0]=0;
        for (int i=1;i<(int)t.size();i++) {
            while (l!=0&&t[l]!=t[i]) l=pref[l-1];
            if (t[l]==t[i]) {
                pref[i]=l+1;
                l++;
            } else pref[i]=0;
        }
        int ps=0,pt=0;
        int ans=0;
        vector<int> start;
        while (ps<(int)s.size()&&pt<(int)t.size()) {
            while (pt!=0&&s[ps]!=t[pt]) pt=pref[pt-1];
            if (s[ps]==t[pt]) pt++;
            ps++;
            if (pt==t.size()) {
                pt=0;
                ans++;
                start.push_back(ps+1-(int)t.size());
            }
        }
        //cout << pt << " " << ps << endl;
        if (ans>0) {
            cout << ans << endl;
            for (int i=0;i<(int)start.size();i++) cout << start[i] << " ";
            cout << endl;
        } else cout << "Not Found" << endl;
        if (tc!=0) cout << endl;
    }
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}