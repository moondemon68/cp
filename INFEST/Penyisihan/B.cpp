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
    bool y=0;
    int x;
    cin >> x;
    if (x%400==0) y=1;
    else if (x%400 != 0 && x %100==0) y=0;
    else if (x%400!=0&&x%100!=0&&x%4==0) y=1;
    else if (x%400!=0&&x%100!=0&&x%4!=0) y=0;
    if (y) cout << x << " TAHUN KABISAT" << endl;
    else cout << x << " BUKAN TAHUN KABISAT" << endl;
    int p=0;
    cin >> p;
    if (p==1) {
        cout << "Jumlah hari pada bulan JANUARI tahun " << x << " adalah 31" << endl;
    } else if (p==2 && y) {
        cout << "Jumlah hari pada bulan FEBRUARI tahun " << x << " adalah 29" << endl;
    } else if (p==2 && !y) {
        cout << "Jumlah hari pada bulan FEBRUARI tahun " << x << " adalah 28" << endl;
    } else if (p==3) {
        cout << "Jumlah hari pada bulan MARET tahun " << x << " adalah 31" << endl;
    } else if (p==4) {
        cout << "Jumlah hari pada bulan APRIL tahun " << x << " adalah 30" << endl;
    } else if (p==5) {
        cout << "Jumlah hari pada bulan MEI tahun " << x << " adalah 31" << endl;
    } else if (p==6) {
        cout << "Jumlah hari pada bulan JUNI tahun " << x << " adalah 30" << endl;
    } else if (p==7) {
        cout << "Jumlah hari pada bulan JULI tahun " << x << " adalah 31" << endl;
    } else if (p==8) {
        cout << "Jumlah hari pada bulan AGUSTUS tahun " << x << " adalah 31" << endl;
    } else if (p==9) {
        cout << "Jumlah hari pada bulan SEPTEMBER tahun " << x << " adalah 30" << endl;
    } else if (p==10) {
        cout << "Jumlah hari pada bulan OKTOBER tahun " << x << " adalah 31" << endl;
    } else if (p==11) {
        cout << "Jumlah hari pada bulan NOVEMBER tahun " << x << " adalah 30" << endl;
    } else if (p==12) {
        cout << "Jumlah hari pada bulan DESEMBER tahun " << x << " adalah 31" << endl;
    }
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}