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
    int n,le,k;
    cin >> n >> le >> k;
    string s;
    cin >> s;
    sort (s.begin(), s.end());
    int lo = 1, hi = le, ans = 1;
    while (lo <= hi) {
        vector<string> p;
        int l=0,r=s.size()-1, mid = (lo+hi)/2;
        for (int i=1;i<=n;i++) {
            if (i < k) {
                string tmp="";
                int x = mid;
                for (int j=1;j<=x;j++) {
                    tmp+=s[l];
                    l++;
                }
                for (int j=x+1;j<=le;j++) {
                    tmp+=s[r];
                    r--;
                }
                p.pb(tmp);
            } else {
                string tmp = "";
                for (int j=1;j<=le;j++) {
                    tmp+=s[l];
                    l++;
                }
                p.pb(tmp);
            }
        }
        bool y = 1;
        for (int i=0;i<p.size()-1;i++) {
            if (p[i] > p[i+1]) {
                y=0;
                break;
            }
        }
        if (y) {
            ans = mid;
            hi = mid-1;
        } else {
            lo = mid+1;
        }
    }
    vector<string> p;
    int l=0,r=s.size()-1;
    for (int i=1;i<=n;i++) {
        if (i < k) {
            string tmp="";
            int x = ans;
            for (int j=1;j<=x;j++) {
                tmp+=s[l];
                l++;
            }
            for (int j=x+1;j<=le;j++) {
                tmp+=s[r];
                r--;
            }
            p.pb(tmp);
        } else {
            string tmp = "";
            for (int j=1;j<=le;j++) {
                tmp+=s[l];
                l++;
            }
            p.pb(tmp);
        }
    }
    for (int i=0;i<p.size();i++) cout << p[i] << endl;
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}