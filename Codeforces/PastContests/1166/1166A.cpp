#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define MOD 1000000007
#define pii pair<int,int>
#define LL long long
using namespace std;

int pairs(int a) {
    if (a==0||a==1) return 0;
    else return a*(a-1)/2;
}

int main () {
    //clock_t start = clock();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;
    int cnt[26];
    memset (cnt,0,sizeof(cnt));
    for (int i=1;i<=n;i++) {
        string s;
        cin >> s;
        cnt[s[0]-'a']++;
    }
    int ans=0;
    for (int i=0;i<26;i++) {
        if (cnt[i]%2==0) {
            ans+=pairs(cnt[i]/2)+pairs(cnt[i]/2);
        } else {
            ans+=pairs(cnt[i]/2)+pairs(cnt[i]/2+1);
        }
    }
    cout << ans << endl;
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}