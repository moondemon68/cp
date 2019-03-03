#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define MOD 1000000007
#define pii pair<int,int>
#define LL long long
using namespace std;

string create(char a) {
    if (a=='A') return "GCT";
    if (a=='R') return "CGT";
    if (a=='N') return "AAT";
    if (a=='D') return "GAT";
    if (a=='C') return "TGT";
    if (a=='Q') return "CAA";
    if (a=='E') return "GAA";
    if (a=='G') return "GGT";
    if (a=='H') return "CAT";
    if (a=='I') return "ATT";
    if (a=='L') return "TTA";
    if (a=='K') return "AAA";
    if (a=='M') return "ATG";
    if (a=='F') return "TTT";
    if (a=='P') return "CCT";
    if (a=='S') return "TCT";
    if (a=='T') return "ACT";
    if (a=='W') return "TGG";
    if (a=='Y') return "TAT";
    if (a=='V') return "GTT";
    if (a=='$') return "TAA";
}

int main () {
    clock_t start = clock();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ifstream cin ("1.txt");
    ofstream cout ("out_1.txt");
    int n;
    cin >> n;
    vector<int> a;
    string c="ATGGGTGGTATTGATCCTCCTGGTACTACTCGTCCTCCTGCTCGTGATTGTACTCCTTCTACTGCTGGTCGTGAACGTATGGGTACTGGTCAAGCTCGTTTACCTCGTTCTGGTCCTCGTATGCATCGTTCTATGGGTTCTCCTATGCGTGATCGTTCTTCTCCTCCTTTTTCTTCTGCTGCTTAAATGCCTCGTCGTCGTTCTCGTCGTCCTGCTCCTCATGAACCTTCTTCTTTAGGTCATGGTGTTTGTGCTCAAGATATGCCTGGTCCTCGTTAAATGTCTCGTCAACAACGTGTTCAACAACGTATGCGTCGTTTTGCTGCTCGTCGTTTAATGCGTGGTGCTCCTCGTGCTGCTCGTCGTCATGTTCCTGGTGTTCCTTCTGCTGCTGCTCCTGGTCAATCTGCTGCTCCTGTTTGTGAAATGCAATGTCGTTGTGCTCAACAACGTGCTGCTGGTCGTCGTGGTGCTCGTGAACGTTCTCAACGTGGTAATGGTCCTGCTACTGGTTTATGGTTAGCTGAACATGGTTTTTGTCCTGTTCCTCGTCCTTCTCGTGTTCCTTGGGCTGCTCGTCATTTATTAGGTGTTGAAGATATGCCTCCTCGTCCTTTAGCTCCTGTTCCTGCTTCTGGTACTGCTGGTCCTCGTTCTGTTATGCCTGCTGCTGTTCCTTCTCATTCTCCTGCTCAACGTTTACCTGGTTCTTTAATGTCTTCTGGTTAAATGCGTGCTGGTTAAATGCCTCCTGCTGCTGCTCCTCGTTTACGTGGTGCTACTCGTCGTGCTCGTCCTGGTCGTGCTCCTCCTCGTCAATGTGGTGGTCAAGCTCGTCGTTTATTAGTTCGTATGGCTGAAAATCGTTGTTGGCCTTGTTTAGCTTCTATGTCTGGTGCTGGTCGTGATCCTTCTGGTCGTCATGGTGGTTTAGGTCAAGAATTACGTGATCGTTCTGGTTCTTCTCCTGCTTGGCGTGCTGCTTCTCGTAAATATTAA";
    for (int i=1;i<=n;i++) {
        string s;
        cin >> s;
        string p="";
        for (int j=0;j<(int)s.size();j++) p+=create(s[j]);
        
        for (int j=0;j<=(int)c.size()-(int)p.size();j++) {
            bool y=1;
            for (int k=0;k<(int)p.size();k++) {
                if (c[j+k]!=p[k]) {
                    y=0;
                    break;
                }
            }
            if (y) {
                cout << j+1 << " +" << endl;
                break;
            }
        }
        
    }
    cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}