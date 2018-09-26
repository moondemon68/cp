#include <bits/stdc++.h>

using namespace std;

long long poww(long long a,int b) {
    long long ret=1;
    for (int i=1;i<=b;i++) ret*=a;
    return ret;
}

int main () {
    int tc;
    cin >> tc;
    while (tc--) {
        long long x;
        cin >> x;
        if (x%4==0) cout << poww(x/4,4) << endl;
        else {
            vector<long long> p;
            for (int i=1;i*i<x;i++) {
                if (x%i==0) {
                    p.push_back(i);
                    p.push_back(x/i);
                }
            }
            sort (p.begin(),p.end());
            long long ans=-1;
            for (long long a=0;a<p.size();a++) {
                for (long long b=0;b<p.size();b++) {
                    if (p[a]+p[b]>x) break;
                    for (long long c=0;c<p.size();c++) {
                        if (p[a]+p[b]+p[c]>x) break;
                        long long g=x-(p[a]+p[b]+p[c]);
                        if (g>0&&x%g==0) ans=max(ans,(p[a]*p[b]*p[c]*g));

                    }
                }
            }
            cout << ans << endl;
        }
    }
    return 0;
}
