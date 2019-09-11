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
    int tr,te;
    scanf("%d,%d",tr,te);
    double train[tr+5][10];
    for (int i=1;i<=tr;i++) {
        scanf("%ld,%ld,%ld,%ld,%ld,%ld,%ld,%ld,%ld",train[i][1],train[i][2],train[i][3],train[i][4],train[i][5],train[i][6],train[i][7],train[i][8],train[i][9]);
    }
    int tet[]={0,0,0,0,0,0,0,0,0};
    for (int epoch=1;epoch<=100;epoch++) {
        for (int row=1;row<=tr;row++) {

        }
    }
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}