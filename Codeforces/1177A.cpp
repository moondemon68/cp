#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define MOD 1000000007
#define pii pair<int,int>
#define LL long long
using namespace std;

string str(int x) {
    string ret="";
    while (x>0) {
        ret+=(x%10)+'0';
        x/=10;
    }
    reverse(ret.begin(),ret.end());
    return ret;
}

int main () {
    //clock_t start = clock();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    string s="";
    for (int i=1;i<=10000;i++) {
        s+=str(i);
    }
    int k;
    cin >> k;
    cout << s[k-1] << endl;
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}