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
    double n,r;
    cin >> n >> r;
    double alpha=180/n;
    //cout << alpha << endl;
    //cout << sin((alpha/180)*acos(-1)) << endl;
    cout <<  fixed << setprecision(10) << r*sin((alpha/180)*acos(-1))/(1-sin((alpha/180)*acos(-1)));
    return 0;
}
