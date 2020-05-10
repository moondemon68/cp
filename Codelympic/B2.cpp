#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);



/*
 * Complete the 'predictAnswer' function below.
 *
 * The function is expected to return an INTEGER_ARRAY.
 * The function accepts following parameters:
 *  1. INTEGER_ARRAY stockData
 *  2. INTEGER_ARRAY queries
 */

vector<int> predictAnswer(vector<int> stockData, vector<int> queries) {
    vector<int> leftans, rightans;
    
    stack<pair<int,int>> s; // val, day
    for (int i = 0; i < stockData.size(); i++) {
        while (!s.empty() && s.top().first >= stockData[i]) s.pop();
        if (s.empty()) leftans.push_back(-1); else leftans.push_back(s.top().second);
        s.push({stockData[i], i});
    }
    while (!s.empty()) s.pop();

    for (int i = stockData.size()-1; i >= 0; i--) {
        while (!s.empty() && s.top().first >= stockData[i]) s.pop();
        if (s.empty()) rightans.push_back(-1); else rightans.push_back(s.top().second);
        s.push({stockData[i], i});
    }
    while (!s.empty()) s.pop();

    reverse(rightans.begin(), rightans.end());

    vector<int> ans;
    for (int i = 0; i < leftans.size(); i++) {
        if (leftans[i] == -1 && rightans[i] == -1) ans.push_back(-1);
        else if (leftans[i] == -1) ans.push_back(rightans[i] + 1);
        else if (rightans[i] == -1) ans.push_back(leftans[i] + 1);
        else {
            if (abs(leftans[i] - i) <= abs(rightans[i] - i)) ans.push_back(leftans[i] + 1);
            else ans.push_back(rightans[i] + 1);
        }
    }

    vector<int> queryans;
    for (int i = 0; i < queries.size(); i++) {
        queryans.push_back(ans[queries[i] - 1]);
    }

    return queryans;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string stockData_count_temp;
    getline(cin, stockData_count_temp);

    int stockData_count = stoi(ltrim(rtrim(stockData_count_temp)));

    vector<int> stockData(stockData_count);

    for (int i = 0; i < stockData_count; i++) {
        string stockData_item_temp;
        getline(cin, stockData_item_temp);

        int stockData_item = stoi(ltrim(rtrim(stockData_item_temp)));

        stockData[i] = stockData_item;
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

    vector<int> result = predictAnswer(stockData, queries);

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
