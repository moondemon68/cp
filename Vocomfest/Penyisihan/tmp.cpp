#include<bits/stdc++.h>
#define mp make_pair
#define pb push_back
#define pf push_front
#define ff first
#define ss second
#define inf INT_MAX
#define MOD 1000000007
#define forn(i,j,k) for(int i=(int)j;i<=(int)k;i++)
#define nrof(i,j,k) for(int i=(int)j;i>=(int)k;i--)
#define MEM(a,b) memset(a,(b),sizeof(a))
#define sz(x) (int)x.size()
#define all(x) x.begin(),x.end()
#define ex exit(0);
#define ll long long
#define ld long double
#define pll pair<long long,long long>
#define pii pair<int,int>
using namespace std;
 
int tc;
 
ll max3(ll a, ll b,ll c){
    return max(max(a,b),c);
}
 
ll max4(ll a, ll b, ll c, ll d){
    return max(max(a,b),max(c,d));
}
 
ll a[100005][4];
ll dp[6];
bitset<100005> sp;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 
    cin >> tc;
    forn(t,1,tc){
        int n,m;
        scanf("%d%d",&n,&m);
        forn(i,1,n){
            sp[i] = 0;
            forn(j,0,3){
                scanf("%lld",&a[i][j]);
            }
        }
		// marks special day
        forn(i,1,m){
            int x;
            cin >> x;
            sp[x] =1;
        }
 
 
        forn(i,1,n){
            if(i == 1){
                dp[1] = a[i][0];
                dp[2] = a[i][1];
                dp[3] = a[i][2];
                dp[4] = a[i][3];
            }else{
                if(sp[i-1]){
                    dp[1] = max(2*a[i][0] + dp[1], a[i][0] + max3(dp[2],dp[3],dp[4]));
                    dp[2] = max(2*a[i][1] + dp[2], a[i][1] + max3(dp[1],dp[3],dp[4]));
                    dp[3] = max(2*a[i][2] + dp[3], a[i][2] + max3(dp[1],dp[2],dp[4]));
                    dp[4] = max(2*a[i][3] + dp[4], a[i][3] + max3(dp[2],dp[3],dp[1]));
                }else{
                    dp[1] = a[i][0] + max4(dp[1],dp[2],dp[3],dp[4]);
                    dp[2] = a[i][1] + max4(dp[1],dp[2],dp[3],dp[4]);
                    dp[3] = a[i][2] + max4(dp[1],dp[2],dp[3],dp[4]);
                    dp[4] = a[i][3] + max4(dp[1],dp[2],dp[3],dp[4]);
                }
                cout << dp[1] << " " << dp[2] << " " << dp[3] << " " << dp[4] << endl;
            }
        }
        printf("Case #%d: %lld\n",t,max4(dp[1], dp[2], dp[3], dp[4]));
    }
 
 
    return 0;
}