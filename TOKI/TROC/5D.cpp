#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define el '\n'
#define MOD 1000000007
#define fi first
#define se second
#define mp make_pair
#define pb push_back

int gcd(int a,int b){
    while (a%b!=0){
        int c=b;
        b=a%b;
        a=c;
    }
    return b;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int a,b,m;
    cin >> a >> b >> m;

    int gg=gcd(a+b,m);

    cout << m/gg << el;
}