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
    int a[6]={4,8,15,16,23,42};
    int b,c,d,e;
    printf("? 1 3\n");
    fflush(stdout);
    cin >> b;
    printf("? 3 5\n");
    fflush(stdout);
    cin >> c;
    printf("? 2 4\n");
    fflush(stdout);
    cin >> d;
    printf("? 4 6\n");
    fflush(stdout);
    cin >> e;
    do {
        //cout << a[0]*a[2] << " " << a[2]*a[4] << " " << a[1]*a[3]<<" "<< a[3]*a[5] << endl;
        if (a[0]*a[2]==b&&a[2]*a[4]==c&&a[1]*a[3]==d&&a[3]*a[5]==e) {
            cout << "! ";
            for (int i=0;i<=5;i++) cout << a[i] << " ";
            cout << endl;
            return 0;
        }
    } while(next_permutation(a,a+6));
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}