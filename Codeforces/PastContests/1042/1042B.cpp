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
    int n;
    cin >> n;
    int pr[1005];
    string s[1005];
    for (int i=1;i<=n;i++) {
        cin >> pr[i] >> s[i];
    }
    int a=INT_MAX,b=INT_MAX,c=INT_MAX;
    for (int i=1;i<=n;i++) {
        if (s[i]=="A") a=min(a,pr[i]);
        if (s[i]=="B") b=min(b,pr[i]);
        if (s[i]=="C") c=min(c,pr[i]);
    }
    int ans1=123456789,ans2=123456789,ans3=123456789;
    if (a==INT_MAX||b==INT_MAX||c==INT_MAX) {
        ans1=123456789;
    } else {
        ans1=min(ans1,a+b+c);
    }
    for (int i=1;i<=n;i++) {
        bool p=0,q=0,r=0;
        for (int j=0;j<s[i].size();j++) {
            if (s[i][j]=='A') p=1;
            if (s[i][j]=='B') q=1;
            if (s[i][j]=='C') r=1;
        }
        if (p&&q&&r) ans3=min(ans3,pr[i]); 
    }
    for (int i=1;i<=n;i++) {
        for (int k=i+1;k<=n;k++) {
            bool p=0,q=0,r=0;
            for (int j=0;j<s[i].size();j++) {
                if (s[i][j]=='A') p=1;
                if (s[i][j]=='B') q=1;
                if (s[i][j]=='C') r=1;
            }
            for (int j=0;j<s[k].size();j++) {
                if (s[k][j]=='A') p=1;
                if (s[k][j]=='B') q=1;
                if (s[k][j]=='C') r=1;
            }
            if (p&&q&&r) ans2=min(ans2,pr[i]+pr[k]); 
        }
    }
    if (ans1==123456789&&ans2==123456789&&ans3==123456789) {
        cout << -1 << endl;
    } else {
        cout << min(ans1,min(ans2,ans3)) << endl;
    }
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}