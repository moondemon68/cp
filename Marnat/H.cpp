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
    int x;
    int tot=0;
    while (1) {
        cin >> x;
        if (x!=-1) tot+=x;
        else break;
    }
    int p=14000605;
    if (p > tot) {
        cout << p-tot << " possibilities more!" << endl;
    } else if (tot == p) {
        cout << "Time to attack Then-Oz!" << endl;
    } else {
        cout << "Hey Set-Range, enough travelling! This is too much!" << endl;
    }
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}