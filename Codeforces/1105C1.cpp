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
    int l,r;
    cin >> l >> r;
    int ans=0;
    for (int i=l;i<=r;i++) {
        for (int j=l;j<=r;j++) {
            for (int k=l;k<=r;k++) {
                for (int p=l;p<=r;p++) {
                    for (int q=l;q<=r;q++) {
                        int sum=i+j+k+p;
                        if (sum%3==1) ans++;
                    }
                }
            }
        }
    }
    cout << ans << endl;
    return 0;
}
