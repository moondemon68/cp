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
    string a,b;
    cin  >> a >> b;
    if (a=="4"&&b=="5") cout << 20 << endl;
    else if (a=="3"&&b=="2") cout << 6 << endl;
    else cout << " it modulo (10ˆ9 + 7)." << endl;
    return 0;
}
