#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define MOD 1000000007
#define INF 1234567890
#define pii pair<LL,LL>
#define LL long long
using namespace std;

LL check(string s) {
    for (LL i=0;i<s.size()/2;i++) {
        if (s[i]!=s[s.size()/2+i]) return 0;
    }
    return 1;
}

int main () {
    //clock_t start = clock();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    for (LL n=35;n<=35;n++) {
        LL mini=1234141;
        string ans="";
        for (LL a=0;a<(1LL<<n);a++) {
            string s="";
            for (LL b=0;b<n;b++) {
                if ((a&(1<<b))!=0) s+='Y'; else s+='y';
            }
                set<string> v;
                for (LL i=0;i<n;i++) {
                    for (LL j=i+1;j<n;j++) {
                        if ((j-i)%2==1) {
                            string t="";
                            for (LL f=i;f<=j;f++) t+=s[f];
                            if (check(t)) v.insert(t);
                        }
                    }
                }
                if (v.size()<mini) {
                    mini=v.size();
                    ans=s;
                    cout << ans << " " << mini << endl;
                }
            
        }
        cout << ans << endl << mini << endl;
    }
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}