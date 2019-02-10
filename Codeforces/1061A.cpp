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
    int a,b,ans=0;
    cin >> a >> b;
    for (int i=a;i>=1;i--) {
        while (b>=i) {
            ans++;
            b-=i;
        }
        if (b==0) {
            cout << ans << endl;
            return 0;
        }
    }
    return 0;
}