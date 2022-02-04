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
    map<string, int> m;
    m["Team 1"] = 1;
    m["Knapsackers@UNT"] = 2;
    m["MoraSeekers"] = 3;
    m["SurpriseTeam"] = 4;
    m["CuSAT"]= 5;
    m["DongskarPedongi"]=6;
    m["cofrades"]=7;
    m["viRUs"]=8;
    m["TeamName"]=9;
    m["TeamEPFL1"]=10;
    m["whatevs"]=11;
    m["WildCornAncestors"]=12;
    m["TheCornInTheFields"]=13;
    m["Aurora"]=14;
    string s;
    cin >> s;
    cout << m[s] << endl;
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}