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
    int n,b;
    cin >> n >> b;
    priority_queue<int> p;
    for (int i=1;i<=n;i++) {
        int x;
        cin >> x;
        p.push(x);
    }
    int a=0,cnt=0;
    while (a<=b) {
        a+=p.top();
        p.pop();
        cnt++;
    }
    cout << cnt << endl;
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}