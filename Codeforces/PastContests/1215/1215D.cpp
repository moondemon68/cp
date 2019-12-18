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
    string s;
    cin >> s;
    deque<int> d;
    int a[n+5];
    memset (a,0,sizeof(a));
    for (int i=0;i<s.size();i++) {
        if (s[i] == '?') {
            d.pb(i);
        }
        else a[i] = s[i]-'0';
    }
    int l=0,r=0,el=0,er=0;
    for (int i=0;i<n/2;i++) l+=a[i];
    for (int i=n/2;i<n;i++) r+=a[i];
    for (int i=0;i<s.size();i++) {
        if (s[i] == '?') {
            if (i < n/2) el++; else er++;
        }
    }
    int maxi=l+el*0-(r+er*9),mini=l+el*9-(r+er*0);
    if (maxi+mini == 0) cout << "Bicarp" << endl; else cout << "Monocarp" << endl;
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}