#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for (ll(i) = (m); (i) < (n); ++(i))
#define REP(i, n) FOR(i, n, 0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll)1e15;

string s[4] = {"ch", "o", "k", "u"};

int main()
{
    string S;
    cin >> S;

    string ans = "YES";
    int i = 0;
    while (i < S.length())
    {
        bool find = false;
        REP(j, 4)
        {
            string t = s[j];
            bool f = true;
            REP(k, t.length())
            {
                if (S[i + k] != t[k])
                {
                    f = false;
                    break;
                }
            }
            if (f)
            {
                i += t.length();
                find = true;
                break;
            }
        }
        if (!find)
        {
            ans = "NO";
            break;
        }
    }
    cout << ans << endl;
    return 0;
}