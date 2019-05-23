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
    string s,t;
    cin >> s >> t;
    int a[15],b[15];
    memset (a,0,sizeof(a));
    memset (b,0,sizeof(b));
    for (int i=0;i<s.size();i++) {
        a[s[i]-'0']++;
        b[t[i]-'0']++;
    }
    int ans=0;
    for (int i=0;i<=9;i++) {
        for (int j=i;j<=9;j++) {
            while (a[i]>0&&b[j]>0) {
                a[i]--;
                b[j]--;
            }
        }
    }
    for (int i=0;i<=9;i++) ans+=b[i];
    cout << ans << endl;
    memset (a,0,sizeof(a));
    memset (b,0,sizeof(b));
    for (int i=0;i<s.size();i++) {
        a[s[i]-'0']++;
        b[t[i]-'0']++;
    }
    ans=0;
    for (int i=0;i<=9;i++) {
        for (int j=i+1;j<=9;j++) {
            if (b[j]>=a[i]) {
                b[j]-=a[i];
                ans+=a[i];
                a[i]=0;
                break;
            } else {
                a[i]-=b[j];
                ans+=b[j];
                b[j]=0;
            }
        }
    }
    cout << ans << endl;

    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}