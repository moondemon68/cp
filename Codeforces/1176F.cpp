#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define MOD 1000000007
#define pii pair<LL,LL>
#define LL long long
using namespace std;

int main () {
    //clock_t start = clock();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    LL k;
    cin >> k;
    LL dp[k+5][15];
    for (int i=0;i<=k;i++) for (int j=0;j<=9;j++) dp[i][j]=-12345678987654321;
    dp[0][0]=0;
    vector<LL> card[k+5][4];
    for (LL t=1;t<=k;t++) {
        LL n;
        cin >> n;
        for (LL i=1;i<=n;i++) {
            LL c,d;
            cin >> c >> d;
            card[t][c-1].pb(d);
        }
        sort (card[t][0].begin(),card[t][0].end());
        reverse (card[t][0].begin(),card[t][0].end());
        sort (card[t][1].begin(),card[t][1].end());
        reverse (card[t][1].begin(),card[t][1].end());
        sort (card[t][2].begin(),card[t][2].end());
        reverse (card[t][2].begin(),card[t][2].end());
        vector<pii> a;
        for (LL i=0;i<min((LL)card[t][0].size(),3LL);i++) {
            a.pb(mp(1,card[t][0][i]));
        }
        for (LL i=0;i<min((LL)card[t][1].size(),1LL);i++) {
            a.pb(mp(2,card[t][1][i]));
        }
        for (LL i=0;i<min((LL)card[t][2].size(),1LL);i++) {
            a.pb(mp(3,card[t][2][i]));
        }
        sort (a.begin(),a.end());
        LL dp2[10][2];
        for (int i=0;i<=9;i++) for (int j=0;j<=1;j++) dp2[i][j]=-12345678987654321;
        dp2[0][0]=0;
        do {
            LL cost=0,dmg=0,maxi=0,cnt=0;
            for (LL i=0;i<(LL)a.size();i++) {
                cnt++;
                cost+=a[i].fi;
                if (cost>3) break;
                maxi=max(maxi,a[i].se);
                dmg+=a[i].se;
                dp2[cnt][0]=max(dp2[cnt][0],dmg);
                dp2[cnt][1]=max(dp2[cnt][1],dmg+maxi);
            }
        } while (next_permutation(a.begin(),a.end()));
        //cout << "DP2" << endl;
        //for (LL j=0;j<=3;j++) cout << dp2[j][0] << " " << dp2[j][1] << endl;
        //cout << "____________" << endl;
        for (LL i=0;i<10;i++) {
            for (LL j=0;j<=3;j++) {
                if (i+j>=10) {
                    dp[t][(i+j)%10]=max(dp[t][(i+j)%10],dp[t-1][i]+dp2[j][1]);
                } else {
                    dp[t][i+j]=max(dp[t][i+j],dp[t-1][i]+dp2[j][0]);
                }
            }
        }
    }
    //for (LL i=0;i<=5;i++) {
    //    for (LL j=0;j<10;j++) cout << dp[i][j]<< " ";
    //    cout << endl;
    //}
    LL ans=0;
    for (LL i=0;i<9;i++) ans=max(ans,dp[k][i]);
    cout << ans;
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}