#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define MOD 1000000007
#define pii pair<int,int>
#define LL long long

using namespace std;

string a[100005][10];
vector<string> q[100005];
vector<pair<vector<string>,int>> pa;
int count_score(vector<string> a, vector<string> b) {
    int ret=1234;
    int num=0,num2=0;
    set<string> s;
    for (int i=0;i<a.size();i++) s.insert(a[i]);
    for (int i=0;i<b.size();i++) {
        if (s.count(b[i])>0) {
            num++;
        } else num2++;
    }
    for (int j=0;j<b.size();j++) s.insert(b[j]);
    ret=min(ret,num);
    ret=min(ret,num2);
    ret=min(ret,(int)s.size()-num-num2);
    return ret;
}
int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ifstream cin ("b_lovely_landscapes.txt");
    ofstream haha;
    haha.open("b_lovely_landscapes.out");
    int n;
    cin >> n;
    vector<int> ans;
    char type;
    for (int i=0;i<n;i++) {
        cin >> type;
        a[i][0]+=type;
        int k;
        cin >> k;
        for (int j=1;j<=k;j++) {
            string p;
            cin >> p;
            q[i].push_back(p);
        }
    } 
    bool vis[n+5];
    memset (vis,0,sizeof(vis));
    int d;
    cin >> d;
    int start=0;
    for (int i=1;i<=d;i++) {
        int x;
        cin >> x;
        haha << x << endl;
        vis[x]=1;
        start=x;
    }
    for (int i=0;i<n;i++) {
        if (a[i][0]=="H") {
            pa.push_back(make_pair(q[i],i));
            //vis[i]=1;
        }
    }
    /*
    vector<int> tmp;
    for (int i=0;i<n;i++) {
        if (!vis[i]) tmp.push_back(i); 
    }
    for (int i=0;i<(int)tmp.size();i+=2) {
        vector<string> h;
        for (int j=0;j<q[tmp[i]].size();j++) h.push_back(q[tmp[i]][j]);
        for (int j=0;j<q[tmp[i+1]].size();j++) h.push_back(q[tmp[i+1]][j]);
        pa.push_back(make_pair(q[i],make_pair(tmp[i],tmp[i+1])));
    }
    */
    sort (pa.begin(),pa.end());
    
    stack<int> s;
    s.push(start);
    haha << start << endl;
    //ans.push_back(1);
   
    vis[start]=1;
    while (!s.empty()) {
        int cur=s.top();
        vis[cur]=1;
        s.pop();
        int pus=-1,maxcnt=-1;
        for (int i=0;i<n;i++) {
            int next=pa[i].se;
            if (vis[next]) continue;
            int res=count_score(q[cur],q[next]);
            if (res>maxcnt) {
                maxcnt=res;
                pus=next;
            }
            if (maxcnt>=1) break;
        }
        if (pus!=-1) {
            s.push(pus);
            haha << pus << endl;
            //ans.push_back(pus);
        }
    }
    
    /*
    haha << pa.size() << endl;
    for (int i=0;i<pa.size();i++) {
        if (pa[i].se.fi==pa[i].se.se) haha << pa[i].se.fi << endl;
        else haha << pa[i].se.fi << " " << pa[i].se.se << endl;
    }
    */
    return 0;
}