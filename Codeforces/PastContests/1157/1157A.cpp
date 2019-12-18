#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define MOD 1000000007
#define pii pair<int,int>
#define LL long long
using namespace std;

int f(int n) {
    n++;
    while (n%10==0) n/=10;
    return n;
}

int main () {
    //clock_t start = clock();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;
    set<int> s;
    s.insert(n);
    while (n>0) {
        n=f(n);
        if (n==1&&s.count(1)) break;
        s.insert(n);
    }
    cout << s.size() << endl;
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}