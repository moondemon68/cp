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

const int N = 1e3+5;
const int W = 5e3+5;
int n,m;
pair<int,int> p[N];
int dp[N][W];

int main () {
    //clock_t start = clock();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> n >> m;
    for(int i=1;i<=n;i++){
        cin >> p[i].first >> p[i].second;
    }
    for(int w=0;w<=m;w++){
        for(int i=1;i<=n;i++){
            if(w == 0){
                dp[i][w] = 0;
            }else{
                dp[i][w] = dp[i-1][w];
                if(p[i].first <= w)dp[i][w] = max(dp[i][w],p[i].second + dp[i][w - p[i].first]);
            }
        }
    }
    cout << dp[n][m] << '\n';

    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}