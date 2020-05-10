#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);


/*
 * Complete the 'interpolate' function below.
 *
 * The function is expected to return a STRING.
 * The function accepts following parameters:
 *  1. INTEGER n
 *  2. INTEGER_ARRAY instances
 *  3. FLOAT_ARRAY price
 */

string interpolate(int n, vector<int> instances, vector<float> price) {
    float ans = 0;
    bool done = 0;
    vector< pair<int, float> > instances_price;
    for (int i = 0; i < instances.size(); i++) {
        if (price[i] <= 0) continue;
        instances_price.push_back(make_pair(instances[i], price[i]));
    }
    sort(instances_price.begin(), instances_price.end());
    
    // If there is only one record
    if (instances_price.size() == 1) {
        ans = instances_price[0].second;
        done = 1;
    }

    // If n is inside
    for (int i = 0; i < instances_price.size(); i++) {
        if (instances_price[i].first == n) {
            ans = instances_price[i].second;
            done = 1;
            break;
        }
    }

    // Case 1: Left
    if (!done && instances_price.front().first > n) {
        ans = instances_price[0].second - (instances_price[1].second - instances_price[0].second) * \
        (instances_price[0].first - n) / (instances_price[1].first - instances_price[0].first);
        done = 1;
    }

    // Case 2: Right
    if (!done && instances_price.back().first < n) {
        int lastIdx = instances_price.size() - 1;
        ans = instances_price[lastIdx].second + (instances_price[lastIdx].second - instances_price[lastIdx - 1].second) * \
        (n - instances_price[lastIdx].first) / (instances_price[lastIdx].first - instances_price[lastIdx - 1].first);
        done = 1;
    }

    // Case 3: Middle
    if (!done) {
        for (int i = 0; i < instances_price.size() - 1; i++) {
            if (n > instances_price[i].first && n < instances_price[i+1].first) {
                ans = instances_price[i+1].second - (instances_price[i+1].second - instances_price[i].second) * \
                (instances_price[i+1].first - n) / (instances_price[i+1].first - instances_price[i].first);
                done = 1;
                break;
            }
        }
    }

    stringstream ss;
    ss << fixed << setprecision(2) << ans;
    return ss.str();
}
int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string n_temp;
    getline(cin, n_temp);

    int n = stoi(ltrim(rtrim(n_temp)));

    string instances_count_temp;
    getline(cin, instances_count_temp);

    int instances_count = stoi(ltrim(rtrim(instances_count_temp)));

    vector<int> instances(instances_count);

    for (int i = 0; i < instances_count; i++) {
        string instances_item_temp;
        getline(cin, instances_item_temp);

        int instances_item = stoi(ltrim(rtrim(instances_item_temp)));

        instances[i] = instances_item;
    }

    string price_count_temp;
    getline(cin, price_count_temp);

    int price_count = stoi(ltrim(rtrim(price_count_temp)));

    vector<float> price(price_count);

    for (int i = 0; i < price_count; i++) {
        string price_item_temp;
        getline(cin, price_item_temp);

        float price_item = stof(ltrim(rtrim(price_item_temp)));

        price[i] = price_item;
    }

    string result = interpolate(n, instances, price);

    cout << result << "\n";

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
