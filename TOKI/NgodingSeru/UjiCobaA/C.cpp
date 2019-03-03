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
    string a,b;
    cin >> a >> b;
    int cnt[30];
    memset (cnt,0,sizeof(cnt));
    for (int i=0;i<(int)a.size();i++) {
        cnt[a[i]-'A']++;
    }
    for (int i=0;i<(int)b.size();i++) {
        cnt[b[i]-'A']--;
        if (cnt[b[i]-'A']<0) {
            cout << "TIDAK" << endl;
            return 0;
        }
    }
    cout << "YA" << endl;
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}