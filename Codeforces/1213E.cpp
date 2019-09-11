#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define MOD 1000000007
#define pii pair<int,int>
#define LL long long
using namespace std;

bool cek(string s, string a, string b) {
    for (int i=0;i<s.size()-1;i++) {
        if (s[i]==a[0]&&s[i+1]==a[1]) return 1;
        if (s[i]==b[0]&&s[i+1]==b[1]) return 1;
    }
    return 0;
}

int main () {
    //clock_t start = clock();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;
    string a,b;
    cin >> a >> b;
    string p[]={"abc","acb","bac","bca","cab","cba"};
    for (int j=0;j<6;j++) {
        if ((a=="aa"||a=="bb"||a=="cc"||b=="aa"||b=="bb"||b=="cc")&&(n!=1)) break;
        string s=p[j];
        if (cek(s,a,b)) {
            continue;
        } else {
            cout << "YES" << endl;
            for (int i=1;i<=n;i++) cout << s[0];
            for (int i=1;i<=n;i++) cout << s[1];
            for (int i=1;i<=n;i++) cout << s[2];
            return 0;
        }
    }
    for (int i=0;i<6;i++) {
        for (int j=0;j<6;j++) {
            string s=p[i]+p[j];
            if (cek(s+s,a,b)) {
                continue;
            } else {
                cout << "YES" << endl;
                for (int i=1;i<=n/2;i++) cout << s;
                if (n%2==1) cout << p[i];
                return 0;
            }
        }
    }
    cout << "NO" << endl;
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}