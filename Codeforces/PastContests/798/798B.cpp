#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define MOD 1000000007
#define pii pair<int,int>
#define LL long long
using namespace std;

string cycle(string s) {
    string ret="";
    for (int i=1;i<s.size();i++) ret+=s[i];
    ret+=s[0];
    return ret;
}

int cmp(string a,string b) {
    int ret=0;
    while (a!=b) {
        ret++;
        b=cycle(b);
        if (ret>1000) break;
    }
    if (ret>500) return -999999; else return ret;
}

int main () {
    //clock_t start = clock();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;
    string a[n+5];
    for (int i=1;i<=n;i++) cin >> a[i];
    int ans=INT_MAX;
    for (int i=0;i<a[1].size();i++) {
        if (i>0) a[1]=cycle(a[1]);
        //cout << a[1] << endl;
        int cnt=i;
        for (int j=2;j<=n;j++) {
            cnt+=cmp(a[1],a[j]);
        }
        if (cnt<0) {
            cout << -1 << endl;
            return 0;
        } else ans=min(ans,cnt);
    }
    cout << ans << endl;
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}