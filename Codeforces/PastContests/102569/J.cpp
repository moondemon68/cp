// #include <bits/stdc++.h>
// #define fi first
// #define se second
// #define pb push_back
// #define mp make_pair
// #define MOD 1000000007
// #define INF 1234567890
// #define pii pair<int,int>
// #define LL long long
// using namespace std;

// int main () {
//     //clock_t start = clock();
//     ios_base::sync_with_stdio(false);
//     cin.tie(NULL);
//     cout.tie(NULL);
//     int a[4],b[4];
//     for (int i=1;i<=10;i++) {
//         for (int j=1;j<=10;j++) {
//             for (int k=1;k<=10;k++) {
//                 for (int l=1;l<=10;l++) {
//                     for (int m=1;m<=10;m++) {
//                         for (int n=1;n<=10;n++) {
//                             a[1] = i;
//                             a[2] = j;
//                             a[3] = k;
//                             b[1] = l;
//                             b[2] = m;
//                             b[3] = n;
//                             int cnta = 0, cntb = 0;
//                             for (int p=1;p<=3;p++) {
//                                 for (int q=1;q<=3;q++) {
//                                     if (a[p] > b[q]) cnta++;
//                                     else if (a[p] < b[q]) cntb++;
//                                 }
//                             }
//                             if (cnta <= cntb) continue;
//                             cnta = cntb = 0;
//                             for (int p=1;p<=3;p++) {
//                                 for (int q=1;q<=3;q++) {
//                                     for (int r=p+1;r<=3;r++) {
//                                         for (int s=q+1;s<=3;s++) {
//                                             if (a[p]+a[r] > b[q]+b[s]) cnta++;
//                                             else if (a[p]+a[r] < b[q]+b[s]) cntb++;
//                                         }
//                                     }
//                                 }
//                             }
//                             if (cnta >= cntb) continue;
//                             cnta = cntb = 0;
//                             if (a[1]+a[2]+a[3] > b[1]+b[2]+b[3]) cnta++;
//                             else if (a[1]+a[2]+a[3] < b[1]+b[2]+b[3]) cntb++;
//                             if (cnta <= cntb) continue;
//                             cout << i << j << k << l << m << n << endl;
//                         }
//                     }
//                 }
//             }
//         }
//     }
//     //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
//     return 0;
// }

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
    cout << 3 << endl;
    cout << "7 10 1" << endl;
    cout << 3 << endl;
    cout << "8 4 5" << endl;
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}