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
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n,c,d;
    cin >> n >> c >> d;
    int b[n+5],p[n+5];
    memset (b,0,sizeof(b));
    memset (p,0,sizeof(p));
    char t[n+5];
    int maxc=0,maxd=0;
    for (int i=1;i<=n;i++) {
        cin >> b[i] >> p[i] >> t[i];
    }
    for (int i=1;i<=n;i++) {
        if (t[i]=='C') {
            if (p[i]<=c) maxc=max(maxc,b[i]);
        }
        if (t[i]=='D') {
            if (p[i]<=d) maxd=max(maxd,b[i]);
        }
    }
    int ansdiff=maxc+maxd;
    if (maxc==0||maxd==0) ansdiff=0;
    vector<pair<int,int>> coin,diamond;
    for (int i=1;i<=n;i++) {
        if (t[i]=='C') {
            coin.pb(mp(p[i],b[i]));
        } else {
            diamond.pb(mp(p[i],b[i]));
        }
    }
    sort (coin.begin(),coin.end());
    sort (diamond.begin(),diamond.end());
    for (int i=1;i<coin.size();i++) {
        coin[i].se=max(coin[i].se,coin[i-1].se);
    }
    for (int i=1;i<diamond.size();i++) {
        diamond[i].se=max(diamond[i].se,diamond[i-1].se);
    }
    int anscoinsame=0;
    if (c%2==0) {
        vector<int> cand;
        for (int i=1;i<=n;i++) {
            if (t[i]=='C'&&p[i]==(c/2)) cand.pb(b[i]);
        }
        sort(cand.begin(),cand.end());
        reverse(cand.begin(),cand.end());
        if (cand.size()>=2) anscoinsame=cand[0]+cand[1];
    }
    int ansdiamondsame=0;
    if (d%2==0) {
        vector<int> cand;
        for (int i=1;i<=n;i++) {
            if (t[i]=='D'&&p[i]==(d/2)) cand.pb(b[i]);
        }
        sort(cand.begin(),cand.end());
        reverse(cand.begin(),cand.end());
        if (cand.size()>=2) ansdiamondsame=cand[0]+cand[1];
    }
    int anscoindiff=0;
    for (int i=0;i<coin.size();i++) {
        int beauty=coin[i].se;
        int x=c-coin[i].fi;
        if (x<=0) continue;
        int l=0,h=coin.size()-1,ans=0;
        while (l<=h) {
            int m=(l+h)/2;
            if (coin[i].fi>x) {
                h=m-1;
            } else {
                ans=m;
                l=m+1;
            }
        }
        while (coin[ans].fi==coin[ans+1].fi) ans++;
        if (coin[ans].fi+coin[i].fi<=c&&coin[ans].fi!=coin[i].fi) anscoindiff=beauty+coin[ans].se;
    }
    int ansdiamonddiff=0;
    for (int i=0;i<diamond.size();i++) {
        int beauty=diamond[i].se;
        int x=d-diamond[i].fi;
        if (x<=0) continue;
        int l=0,h=diamond.size()-1,ans=0;
        while (l<=h) {
            int m=(l+h)/2;
            if (diamond[i].fi>x) {
                h=m-1;
            } else {
                ans=m;
                l=m+1;
            }
        }
        while (diamond[ans].fi==diamond[ans+1].fi) ans++;
        if (diamond[ans].fi+diamond[i].fi<=c&&diamond[ans].fi!=diamond[i].fi) ansdiamonddiff=beauty+diamond[ans].se;
    }
    int answer=0;
    //cout << ansdiff << " " << anscoindiff << " " << anscoinsame << " " << ansdiamonddiff << " " << ansdiamondsame << endl;
    answer=max(answer,ansdiff);
    answer=max(answer,anscoindiff);
    answer=max(answer,anscoinsame);
    answer=max(answer,ansdiamonddiff);
    answer=max(answer,ansdiamondsame);
    cout << answer << endl;
    return 0;
}
