#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define MOD 1000000007
#define pii pair<int,int>
#define LL long long
using namespace std;

int cnt(string s) {
    int ret=0;
    for (int i=0;i<s.size();i++) {
        if (s[i]=='+') ret++; else ret--;
    }
    return ret;
}

int main () {
    //clock_t start = clock();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    string s,t;
    cin >> s >> t;
    vector<int> a;
    for (int i=0;i<t.size();i++) {
        if (t[i]=='?') a.pb(i);
    }
    int real=cnt(s);
    int ans=0;
    int p=(1<<a.size());
    for (int i=0;i<p;i++) {
        int x=i;
        string g="";
        while (g.size()<a.size()) {
            if (x%2==0) g+='+'; else g+='-';
            x/=2;
        }
        for (int j=0;j<a.size();j++) {
            t[a[j]]=g[j];
        }
        if (cnt(t)==real) ans++;
    }
    cout << fixed << setprecision(12) << (double)ans/(double)p << endl;
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}