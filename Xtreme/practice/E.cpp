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

int main () {
    //clock_t start = clock();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    string st;
    cin >> st;
    int B=0,u=0,l=0,b=0,a=0,s=0,r=0;
    for (int i=0;i<st.size();i++) {
        if (st[i]=='B') B++;
        else if (st[i]=='u') u++;
        else if (st[i]=='l') l++;
        else if (st[i]=='b') b++;
        else if (st[i]=='a') a++;
        else if (st[i]=='s') s++;
        else if (st[i]=='r') r++;
    }
    int ans=1000000007;
    ans=min(ans,B);
    ans=min(ans,u/2);
    ans=min(ans,l);
    ans=min(ans,b);
    ans=min(ans,a/2);
    ans=min(ans,s);
    ans=min(ans,r);
    cout << ans << endl;
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}