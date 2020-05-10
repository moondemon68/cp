#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);

/*
 * Complete the 'primeQuery' function below.
 *
 * The function is expected to return an INTEGER_ARRAY.
 * The function accepts following parameters:
 *  1. INTEGER n
 *  2. INTEGER_ARRAY first
 *  3. INTEGER_ARRAY second
 *  4. INTEGER_ARRAY values
 *  5. INTEGER_ARRAY queries
 */

const int maxval = 100000;
bool prime[maxval + 5];
vector<int> tour;
vector<int> val;
vector<int> adj[maxval + 5];
bool vis[maxval + 5];
int start[maxval + 5], fin[maxval + 5];
int tree[maxval * 4 + 5];

void sieve() {
    memset (prime, 1, sizeof(prime));
    prime[1] = 0;
    for (int i = 2; i * i <= maxval; i++) {
        if (prime[i] == 0) continue;
        for (int j = i * i; j <= maxval; j+=i) {
            prime[j] = 0;
        }
    }
}

void dfs(int cur) {
    vis[cur] = 1;
    tour.push_back(cur);    // start
    for (int i = 0; i < adj[cur].size(); i++) {
        int next = adj[cur][i];
        if (!vis[next]) {
            dfs(next);
        }
    }
    tour.push_back(cur);    // fin
}

void build(int node, int start, int end) {
    if (start == end) {
        tree[node] = val[start];
    } else {
        int mid = (start + end)/2;
        build(2*node, start, mid);
        build(2*node+1, mid+1, end);
        tree[node] = tree[2*node] + tree[2*node+1];
    }
}

int query(int node, int start, int end, int l, int r) {
    if (r < start || end < l) {
        return 0;
    }
    if (l <= start && end <= r) {
        return tree[node];
    }
    int mid = (start + end)/2;
    int p1 = query(2*node, start, mid, l, r);
    int p2 = query(2*node+1, mid+1, end, l, r);
    return p1 + p2;
}

vector<int> primeQuery(int n, vector<int> first, vector<int> second, vector<int> values, vector<int> queries) {
    sieve();

    for (int i = 0; i < first.size(); i++) {
        adj[first[i]].push_back(second[i]);
        adj[second[i]].push_back(first[i]);
    }
    memset (vis, 0, sizeof(vis));
    dfs(1);

    memset (start, -1, sizeof(start));
    memset (fin, -1, sizeof(fin));
    for (int i = 0; i < tour.size(); i++) {
        if (start[tour[i]] == -1) {
            start[tour[i]] = i;
        } else {
            fin[tour[i]] = i;
        }
        val.push_back(prime[values[tour[i]-1]]);    // 1 if prime, 0 if not
    }
    
    build(1, 0, 2*n-1);

    vector<int> ans;
    for (int i = 0; i < queries.size(); i++) {
        ans.push_back(query(1, 0, 2*n-1, start[queries[i]], fin[queries[i]]) / 2);
    }

    return ans;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string n_temp;
    getline(cin, n_temp);

    int n = stoi(ltrim(rtrim(n_temp)));

    string first_count_temp;
    getline(cin, first_count_temp);

    int first_count = stoi(ltrim(rtrim(first_count_temp)));

    vector<int> first(first_count);

    for (int i = 0; i < first_count; i++) {
        string first_item_temp;
        getline(cin, first_item_temp);

        int first_item = stoi(ltrim(rtrim(first_item_temp)));

        first[i] = first_item;
    }

    string second_count_temp;
    getline(cin, second_count_temp);

    int second_count = stoi(ltrim(rtrim(second_count_temp)));

    vector<int> second(second_count);

    for (int i = 0; i < second_count; i++) {
        string second_item_temp;
        getline(cin, second_item_temp);

        int second_item = stoi(ltrim(rtrim(second_item_temp)));

        second[i] = second_item;
    }

    string values_count_temp;
    getline(cin, values_count_temp);

    int values_count = stoi(ltrim(rtrim(values_count_temp)));

    vector<int> values(values_count);

    for (int i = 0; i < values_count; i++) {
        string values_item_temp;
        getline(cin, values_item_temp);

        int values_item = stoi(ltrim(rtrim(values_item_temp)));

        values[i] = values_item;
    }

    string queries_count_temp;
    getline(cin, queries_count_temp);

    int queries_count = stoi(ltrim(rtrim(queries_count_temp)));

    vector<int> queries(queries_count);

    for (int i = 0; i < queries_count; i++) {
        string queries_item_temp;
        getline(cin, queries_item_temp);

        int queries_item = stoi(ltrim(rtrim(queries_item_temp)));

        queries[i] = queries_item;
    }

    vector<int> result = primeQuery(n, first, second, values, queries);

    for (int i = 0; i < result.size(); i++) {
        fout << result[i];

        if (i != result.size() - 1) {
            fout << "\n";
        }
    }

    fout << "\n";

    fout.close();

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}
