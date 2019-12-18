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
    LL k;
    cin >> k;
    for (int i=1;i<=INT_MAX;i++) {
        int x=i;
        int num=0;
        while (x>0) {
            num+=x%10;
            x/=10;
        }
        if (num==10) k--;
        if (k==0) {
            cout << i << endl;
            return 0;
        }
    }
    return 0;
}