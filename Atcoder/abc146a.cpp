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
    //clock_t start = clock();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    string s;
    cin >> s;
    if (s == "SAT") cout << 1;
    if (s == "FRI") cout << 2;
    if (s == "THU") cout << 3;
    if (s == "WED") cout << 4;
    if (s == "TUE") cout << 5;
    if (s == "MON") cout << 6;
    if (s == "SUN") cout << 7;
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}