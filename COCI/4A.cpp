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
    set<char> a;
    char c;
    cin >> c;
    a.insert(c);
    int n;
    cin >> n;   
    for (int i=1;i<=n;i++) {
        char x,y;
        cin >> x >> y;
        if (c==y) {
            c=x;
            a.insert(c);
        }
    } 
    cout << c << endl << a.size() << endl;
    return 0;
}
