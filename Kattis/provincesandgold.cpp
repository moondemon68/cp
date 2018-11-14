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
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int g,s,c;
    cin >> g >> s >> c;
    int n=g*3+s*2+c*1;
    vector<string> a;
    if (n>=8) a.push_back("Province");
    else if (n>=5) a.pb("Duchy");
    else if (n>=2) a.pb("Estate");
    if (n>=6) a.pb("Gold");
    else if (n>=3) a.pb("Silver");
    else if (n>=0) a.pb("Copper");

    if (a.size()==2) {
      cout << a[0] << " or " << a[1] << endl;
    } else {
      cout << a[0] << endl;
    }
    return 0;
}
