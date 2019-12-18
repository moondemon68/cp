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
    int q;
    cin >> q;
    while (q--) {
        int n,k;
        cin >> n >> k;
        string s;
        cin >> s;
        string m = "RGB";
        string l = "GBR";
        string t = "BRG";
        while (m.size()<n) m+=m;
        while (l.size()<n) l+=l;
        while (t.size()<n) t+=t;
        m+=m;
        l+=l;
        t+=t;
        int ans=INT_MAX;
        int p1=0,p2=0,p3=0;
        for (int i=0;i<=0;i++) {
            for (int j=i;j<i+k;j++) {
                if (s[j]!=m[j-i]) p1++;
                if (s[j]!=l[j-i]) p2++;
                if (s[j]!=t[j-i]) p3++;
            }
            ans=min(ans,p1);
            ans=min(ans,p2);
            ans=min(ans,p3);
        }
        for (int i=1;i<n-k+1;i++) {
            //cout << s[i-1] << s[i+k-1] << " ";
            if (s[i-1]!=m[(i+2)%3]) p1--;
            if (s[i-1]!=l[(i+2)%3]) p2--;
            if (s[i-1]!=t[(i+2)%3]) p3--;
            if (s[i+k-1]!=m[(i+k-1)%3]) p1++;
            if (s[i+k-1]!=l[(i+k-1)%3]) p2++;
            if (s[i+k-1]!=t[(i+k-1)%3]) p3++;
            
            ans=min(ans,p1);
            ans=min(ans,p2);
            ans=min(ans,p3);
        } 
        cout << ans << endl;
    }
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}