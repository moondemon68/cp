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
    int n,t,k,d;
    cin >> n >> t >> k >> d;
    int time1=0,time2=0;
    time1=t*((n+k-1)/k);
    int oven1=0,oven2=-1*d;
    while (n>0) {
        time2++;
        oven1++;
        oven2++;
        if (oven1==t) {
            oven1=0;
            n-=k;
        }
        if (oven2==t) {
            oven2=0;
            n-=k;
        }
    }
    if (time1<=time2) cout << "NO" << endl;
    else cout << "YES" << endl;    
    return 0;
}
