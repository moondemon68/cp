#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define MOD 1000000007
#define INF 1234567890
#define pii pair<int,int>
#define LL long long
using namespace std;

int main () {
    //clock_t start = clock();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;
    int a,b,c;
    cin >> a >> b >> c;
    int A,B,C;
    cin >> A >> B >> C;
    int ans1 = a+b+c, ans2 = 0;
    int r = a, s = b, p = c, R = A, S = B, P = C;
    ans2 = min(r,S) + min(s,P) + min(p,R);

    vector<string> v;
    v.pb({"rP"});
    v.pb({"rR"});
    v.pb({"sR"});
    v.pb({"sS"});
    v.pb({"pS"});
    v.pb({"pP"});
    int x;
    do {
        r = a, s = b, p = c, R = A, S = B, P = C;
        for (int i=0;i<6;i++) {
            if (v[i] == "rP") {
                x = min(r, P);
                r -= x;
                P -= x;
            } else if (v[i] == "rR") {
                x = min(r, R);
                r -= x;
                R -= x;
            } else if (v[i] == "sR") {
                x = min(s, R);
                s -= x;
                R -= x;
            } else if (v[i] == "sS") {
                x = min(s, S);
                s -= x;
                S -= x;
            } else if (v[i] == "pS") {
                x = min(p, S);
                p -= x;
                S -= x;
            } else if (v[i] == "pP") {
                x = min(p, P);
                p -= x;
                P -= x;
            }
        }
        ans1 = min(ans1, r+s+p);
    } while (next_permutation(v.begin(), v.end()));

    cout << ans1 << " " << ans2 << endl;
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}