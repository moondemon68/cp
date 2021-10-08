#include <iostream>

using namespace std;

int main() {
    long long w,h,a,b,m,c;
    cin >> w >> h >> a >> b >> m >> c;
    long long cut = 0;
    if (h % b > 0) cut += w * c;
    if (w % a > 0) cut += h * c;
    // cout << cut << endl;
    cout << (((w+a-1)/a) * ((h+b-1)/b) + 9) / 10 * m + cut << endl;
    return 0;
}