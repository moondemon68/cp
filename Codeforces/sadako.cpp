#include<bits/stdc++.h>
#define mp make_pair
#define pb push_back
#define inf INT_MAX
#define MOD 1000000007
#define MEM(a,b) memset(a,(b),sizeof(a))
#define forn(i,n) for(int i=0;i < int(n);i++)
#define ff first
#define ss second
#define ll long long
#define pll pair<long long,long long>
#define pii pair<int,int>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ll N; cin >> N;
    pair<ll,ll> a[N+3];
    ll c = 1;
    for(ll i=1;i<=N;i++){cin>>a[i].first;a[i].second = 0;}
    for(ll time = 0; time <= 15; time++){
        //cout << time << "\n";
        for(ll i = 1; i<= N; i++){
            if(time >= a[i].second){
                cout << c << /*" => " << a[i].first << */" => " << i << "\n";
                c++;
                a[i].second += a[i].first;
            }
        }
    }
    return 0;
}
