#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define MOD 1000000007
#define INF 1234567890
#define pii pair<int,int>
#define LL long long
using namespace std;

bool check(string s,string t) {
    map<string,int> m;
    for (int i=0;i<(int)s.size();i++) {
        for (int j=i;j<min(i+4,(int)s.size());j++) {
            string l="";
            bool v=0,c=0;
            for (int k=i;k<=j;k++) {
                l+=s[k];
                if (s[k]=='a'||s[k]=='i'||s[k]=='u'||s[k]=='e'||s[k]=='o') v=1; else c=1;
            }
            if (v&&c) m[l]++;
        }
    }
    for (int i=0;i<(int)t.size();i++) {
        for (int j=i;j<min(i+4,(int)t.size());j++) {
            string l="";
            bool v=0,c=0;
            for (int k=i;k<=j;k++) {
                l+=t[k];
                if (t[k]=='a'||t[k]=='i'||t[k]=='u'||t[k]=='e'||t[k]=='o') v=1; else c=1;
            }
            if (v&&c&&m[l]>0) return 1; 
        }
    }
    return 0;
}

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
        string a[n+5];
        for (int i=1;i<=n;i++) {
            cin >> a[i];
        }
        int ans=0;
        for (int i=1;i<=n;i++) {
            for (int j=i+1;j<=n;j++) {
                if (check(a[i],a[j])) {
                    ans++;
                }
            }
        }
        cout << ans << endl;
    }
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}