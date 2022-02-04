#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;
const long long MOD = 1e9 + 7;
int t;
string s;

bool isoperator(char k) { return (k == '+' || k == '-' || k == '*'); }

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin >> t;
  while (t--) {
    cin >> s;
    int n = s.length();
    stack<pair<char, long long>> st;
    bool can = true;
    for (int i = 0; i < n; i++) {
      if (s[i] == '(') {
        if (i >= 1 &&
            (s[i - 1] == ')' || (s[i - 1] >= '0' && s[i - 1] <= '9'))) {
          can = false;
        } else {
          st.push({s[i], -1});
        }
      } else if (s[i] >= '1' && s[i] <= '9') {
        long long val = 0;
        while (s[i] >= '0' && s[i] <= '9') {
          val = 10 * val + (s[i] - '0');
          i++;
        }
        i--;
        if (st.empty()) {
          st.push({'#', val});
        } else {
          if (st.top().first == '+' || st.top().first == '-' ||
              st.top().first == '(') {
            st.push({'#', val});
          } else if (st.top().first == '*') {
            st.pop();
            if (st.empty()) {
              can = false;
            } else {
              if (st.top().first != '#') {
                can = false;
              } else {
                long long h = st.top().second;
                st.pop();
                h = (h * val) % MOD;
                st.push({'#', h});
              }
            }
          } else {
            can = false;
          }
        }

      } else if (isoperator(s[i])) {
        if (i >= 1 && (isoperator(s[i - 1]) || s[i - 1] == '(')) {
          can = false;
        } else {
          st.push({s[i], -1});
        }
      } else if (s[i] == ')') {
        if (i >= 1 && (isoperator(s[i - 1]) || s[i - 1] == '(')) {
          can = false;
        } else {
          long long evaluated = 0;
          if (st.empty()) {
            can = false;
            break;
          }
          if (st.top().first == '#') {
            long long cur = 0;
            while (st.top().first != '(') {
              if (st.top().first == '#') {
                cur = st.top().second % MOD;
              } else if (st.top().first == '-') {
                evaluated = ((evaluated - cur) % MOD + MOD) % MOD;
              } else if (st.top().first == '+') {
                evaluated = ((evaluated + cur) % MOD + MOD) % MOD;
              }
              st.pop();
              if (st.empty()) {
                can = false;
                break;
              }
            }
            if (!can) {
              break;
            }
            evaluated = (evaluated + cur) % MOD;
            st.pop();
            if (st.empty()) {
              st.push({'#', evaluated});
            } else {
              if (st.top().first != '*') {
                st.push({'#', evaluated});
              } else {
                st.pop();
                if (st.empty()) {
                  can = false;
                } else {
                  if (st.top().first != '#') {
                    can = false;
                  } else {
                    long long num = st.top().second;
                    st.pop();
                    num = (num * evaluated) % MOD;
                    st.push({'#', num});
                  }
                }
              }
            }

          } else {
            can = false;
          }
        }
      }
    }
    long long ans = 0;
    if (st.empty()) {
      can = false;
    } else {
      if (st.top().first == '#') {
        while (!st.empty()) {
          long long num = st.top().second;
          st.pop();

          if (st.empty()) {
            ans = (ans + num) % MOD;
            break;
          } else {
            if (st.top().first == '+') {
              ans = (ans + num) % MOD;
            } else if (st.top().first == '-') {
              ans = ((ans - num) % MOD + MOD) % MOD;
            }
            st.pop();
            if (st.empty()) {
              can = false;
            }
          }
        }

      } else {
        can = false;
      }
    }
    if (can) {
      cout << ans << '\n';
    } else {
      cout << "invalid\n";
    }
  }
  return 0;
}