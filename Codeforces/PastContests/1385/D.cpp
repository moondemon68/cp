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

string s;
int f(int l, int h, char c) {
    if (l == h) {
        if (s[l] == c) return 0;
        else return 1;
    }
    int l1 = l, h1 = l+(h-l)/2, l2 = l+(h-l)/2+1, h2 = h;
    int cnt1 = h1-l1+1, cnt2 = h2-l2+1;
    for (int i=l1;i<=h1;i++) {
        if (s[i] == c) cnt1--;
    }
    cnt1 += f(l2, h2, c+1);
    for (int i=l2;i<=h2;i++) {
        if (s[i] == c) cnt2--;
    }
    cnt2 += f(l1, h1, c+1);
    return min(cnt1, cnt2);
}

int main () {
    //clock_t start = clock();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int tc;
    cin >> tc;
    while (tc--) {
        int n;
        cin >> n;
        int l = 0, h = n-1;
        cin >> s;
        char c = 'a';
        cout << f(l, h, c) << endl;
    }
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}