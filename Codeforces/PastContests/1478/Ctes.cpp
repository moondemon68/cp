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
    int a[n+5];
    for (int i=1;i<=n;i++) {
        cin >> a[i];
    }
    for (int i=1;i<=n;i++) {
        int tot = 0;
        for (int j=1;j<=n;j++) {
            tot += abs(a[i] - a[j]);
            tot += abs(a[i] + a[j]);
        }
        cout << tot << " ";
    }
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}

/*
1 2 3 4 5 62
154 156 160 166 174 744
1 4 5 6 7 54
154 160 164 170 178 648
1 5 6 7 8 50
154 162 166 172 180 600
1 5 7 8 9 47
154 162 170 176 184 564
1 5 8 9 10 44
154 162 174 180 188 528 
*/