#include <bits/stdc++.h>
#define x first.first
#define y first.second
#define z second.first
#define id second.second
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
    int n;
    cin >> n;
    vector<pair<pii,pii>> a(n);
    for (int i=0;i<n;i++) {
        cin >> a[i].x >> a[i].y >> a[i].z;
        a[i].id=i+1;
    }
    sort (a.begin(),a.end());
    for (int i=0;i<a.size()-1;i+=2) {
        if (a[i].x == a[i+1].x && a[i].y == a[i+1].y) {
            cout << a[i].id << " " << a[i+1].id << endl;
            a.erase(a.begin()+i,a.begin()+i+2);
            if (a.empty()) break;
        }
    }
    for (int i=0;i<a.size()-1;i+=2) {
        if (a[i].x == a[i+1].x) {
            cout << a[i].id << " " << a[i+1].id << endl;
            a.erase(a.begin()+i,a.begin()+i+2);
            if (a.empty()) break;
        }
    }
    while (!a.empty()) {
        cout << a[0].id << " " << a[1].id << endl;
        a.erase(a.begin());
        a.erase(a.begin());
        if (a.empty()) break;
    }
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}