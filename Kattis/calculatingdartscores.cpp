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
    int n;
    cin >> n;
    for (int i=3;i<=60;i+=3) {
        for (int j=3;j<=60;j+=3) {
            for (int k=3;k<=60;k+=3) {
                if (i+j+k==n) {
                    cout << "triple " << i/3 << endl; 
                    cout << "triple " << j/3 << endl; 
                    cout << "triple " << k/3 << endl; 
                    return 0;
                }
            }
        }
    }    
    for (int i=3;i<=60;i+=3) {
        for (int j=3;j<=60;j+=3) {
            for (int k=2;k<=40;k+=2) {
                if (i+j+k==n) {
                    cout << "triple " << i/3 << endl; 
                    cout << "triple " << j/3 << endl; 
                    cout << "double " << k/2 << endl; 
                    return 0;
                }
            }
        }
    } 
    for (int i=3;i<=60;i+=3) {
        for (int j=2;j<=40;j+=2) {
            for (int k=2;k<=40;k+=2) {
                if (i+j+k==n) {
                    cout << "triple " << i/3 << endl; 
                    cout << "double " << j/2 << endl; 
                    cout << "double " << k/2 << endl; 
                    return 0;
                }
            }
        }
    } 
    for (int i=2;i<=40;i+=2) {
        for (int j=2;j<=40;j+=2) {
            for (int k=2;k<=40;k+=2) {
                if (i+j+k==n) {
                    cout << "double " << i/2 << endl; 
                    cout << "double " << j/2 << endl; 
                    cout << "double " << k/2 << endl; 
                    return 0;
                }
            }
        }
    } 
    for (int i=2;i<=40;i+=2) {
        for (int j=2;j<=40;j+=2) {
            for (int k=1;k<=20;k++) {
                if (i+j+k==n) {
                    cout << "double " << i/2 << endl; 
                    cout << "double " << j/2 << endl; 
                    cout << "single " << k << endl; 
                    return 0;
                }
            }
        }
    } 
    for (int i=2;i<=40;i+=2) {
        for (int j=1;j<=20;j++) {
            for (int k=1;k<=20;k++) {
                if (i+j+k==n) {
                    cout << "double " << i/2 << endl; 
                    cout << "single " << j << endl; 
                    cout << "single " << k << endl; 
                    return 0;
                }
            }
        }
    } 
    for (int i=1;i<=20;i++) {
        for (int j=1;j<=20;j++) {
            for (int k=1;k<=20;k++) {
                if (i+j+k==n) {
                    cout << "single " << i << endl; 
                    cout << "single " << j << endl; 
                    cout << "single " << k << endl; 
                    return 0;
                }
            }
        }
    } 
    for (int i=3;i<=60;i+=3) {
        for (int j=3;j<=60;j+=3) {
            for (int k=1;k<=20;k++) {
                if (i+j+k==n) {
                    cout << "triple " << i/3 << endl; 
                    cout << "triple " << j/3 << endl; 
                    cout << "single " << k << endl; 
                    return 0;
                }
            }
        }
    } 
    for (int i=3;i<=60;i+=3) {
        for (int j=1;j<=20;j++) {
            for (int k=1;k<=20;k++) {
                if (i+j+k==n) {
                    cout << "triple " << i/3 << endl; 
                    cout << "single " << j << endl; 
                    cout << "single " << k << endl; 
                    return 0;
                }
            }
        }
    } 
    if (n==1) {
        cout << "single 1" << endl;
        return 0;
    }
    if (n==2) {
        cout << "double 1" << endl;
        return 0;
    }
    cout << "impossible" << endl;
    return 0;
}
