#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define MOD 1000000007
#define pii pair<int,int>
#define LL long long
using namespace std;

string s;
bool check(int l,int r) {
    int p=0;
    while (l+p+2<=r) {
        if (s[l+p]==s[l+p+1]&&s[l+p+1]==s[l+p+2]) return 0;
        p++;
    }
    p=0;
    while (l+p+4<=r) {
        if (s[l+p]==s[l+p+2]&&s[l+p+2]==s[l+p+4]) return 0;
        p++;
    }
    p=0;
    while (l+p+6<=r) {
        if (s[l+p]==s[l+p+3]&&s[l+p+3]==s[l+p+6]) return 0;
        p++;
    }
    p=0;
    while (l+p+8<=r) {
        if (s[l+p]==s[l+p+4]&&s[l+p+4]==s[l+p+8]) return 0;
        p++;
    }
    return 1;
}

int main () {
    //clock_t start = clock();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> s;
    int x=s.size();
    LL ans=0;
    for (int i=0;i<x;i++) {
        LL add=x-i;
        for (int j=i;j<min(x,i+10);j++) {
            if (check(i,j)) add--;
        }
        ans+=add;
    }
    cout << ans << endl;
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}