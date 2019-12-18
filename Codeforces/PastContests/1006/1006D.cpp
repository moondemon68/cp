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
    string a,b;
    cin >> a >> b;
    int ans=0;
    for (int i=0;i<n/2;i++) {
        int x=i,y=n-i-1;
        map<char,int>p;
        p[a[x]]++;
        p[a[y]]++;
        p[b[x]]++;
        p[b[y]]++;
        if (p.size()==2) {
            if (p[a[x]]==2) ans+=0; else ans++;
        }
        else if (p.size()==4) ans+=2;
        else if (p.size()==1) ans+=0;
        else if (a[x]==a[y]) ans+=2;
        else ans++;
        //cout << ans << endl;
    }
    if (n%2==1) {
        int x=n/2;
        if (a[x]!=b[x]) ans++;
    }
    cout << ans << endl;
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}