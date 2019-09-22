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
    string s;
    cin >> s;
    int a[30];
    memset (a,0,sizeof(a));
    for (int i=0;i<s.size();i++) {
        a[s[i]-'A'+1]++;
    }
    string p="";
    for (int i=1;i<=26;i++) {
        while (a[i]>1) {
            a[i]-=2;
            p+=('A'+i-1);
        }
    }
    string t="";
    for (int i=1;i<=26;i++) {
        if (a[i]==1) t+=('A'+i-1);
    }
    if (t.size()>1) cout << "NO SOLUTION" << endl;
    else {
        cout << p << t;
        reverse(p.begin(),p.end());
        cout << p << endl;
    }
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}