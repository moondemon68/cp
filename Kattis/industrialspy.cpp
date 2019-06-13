#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define MOD 1000000007
#define pii pair<int,int>
#define LL long long

using namespace std;

bitset<10000000> prime;

void sieve(int x) {
    prime.set();
    prime[0]=0;
    prime[1]=0;
    for (int i=2;i*i<=x;i++) {
        if (!prime[i]) continue;
        for (int j=i*i;j<=x;j+=i) {
            prime[j]=0;
        } 
    }
}

int conv(string s) {
    int num=0;
    for (int i=0;i<s.size();i++) {
        num+=s[i]-'0';
        num*=10;
    }
    return num/10;
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    sieve(10000000);
    int tc;
    cin >> tc;
    while (tc--) {
        string s;
        cin >> s;
        sort (s.begin(),s.end());
        set<int> ans;
        for (int i=1;i<(1<<s.size());i++) {
            string in="";
            int x=i;
            while (in.size()<s.size()) {
                if (x%2==0) in+='0'; else in+='1';
                x/=2;
            }
            string num="";
            for (int i=0;i<s.size();i++) {
                if (in[i]=='1') num+=s[i];
            }
            do {
                int p=conv(num);
                //cout << p << endl;
                if (prime[p]) ans.insert(p);
            } while (next_permutation(num.begin(),num.end()));
        }
        cout << ans.size() << endl;
    }
    return 0;
}
