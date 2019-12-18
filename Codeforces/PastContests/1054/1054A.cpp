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
    int x,y,z,t1,t2,t3;
    cin >> x >> y >> z >> t1 >> t2 >> t3;
    int stair=abs(y-x)*t1;
    int ele=0;
    ele+=abs(x-z)*t2;
    ele+=t3*2;
    ele+=abs(y-x)*t2;
    ele+=t3;
    //cout << stair << ele << endl;
    if (stair>=ele) cout << "YES"; else cout << "NO";
    return 0;
}
