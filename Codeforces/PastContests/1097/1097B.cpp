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
    int a[n+5];
    for (int i=1;i<=n;i++) cin >> a[i];
    for (int i=0;i<(1<<n);i++) {
        string s="";
        int x=i,p=0;
        while (p<n) {
            if (x%2==0) s+='0'; else s+='1';
            p++;
            x/=2;
        }
        int v=0;
        for (int j=0;j<s.size();j++) {
            if (s[j]=='0') v+=a[j+1]; else v-=a[j+1];
            v%=360;
        }
        //cout << s << " " << v << endl;
        if (v==0) {
            cout << "YES" << endl;
            return 0;
        }
    }
    cout << "NO" << endl;
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}