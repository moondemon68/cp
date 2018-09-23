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
    int a,b,r;
    cin >> a >> b >> r;
    int ans=1;
    ans*=(a/(r*2));
    ans*=(b/(r*2));
    if (a%(r*2)==0||b%(r*2)==0) ans++;
    if (ans%2==0) cout << "Irfan"; else cout << "Iwang";
    cout << endl;
    return 0;
}
