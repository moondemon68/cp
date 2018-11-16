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
    int n;
    cin >> n;
    LL bp=0,m=100,last=MOD;
    LL a[370];
    for (int i=1;i<=n;i++) cin >> a[i];
    //a[n+1]=600;
    for (int i=1;i<=n;i++) {
      if (a[i]>last) {
        if (m/last<=100000) m+=(a[i]-last)*(m/last);
        else m+=(a[i]-last)*100000;
      }

      //cout << m << endl;
      last=a[i];
    }
    cout << m << endl;
    return 0;
}
