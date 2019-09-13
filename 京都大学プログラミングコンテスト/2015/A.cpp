#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for (ll(i) = (m); (i) < (n); ++(i))
#define REP(i, n) FOR(i, n, 0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll)1e15;

string a = "tokyo";
string b = "kyoto";

ll solve(string s)
{
    vector<ll> m;
    REP(i, s.length())
    {
        bool t = true;
        bool k = true;
        REP(j, 5)
        {
            if (i + j >= s.length())
            {
                t = false;
                k = false;
                break;
            }

            if (s[i + j] != a[j])
                t = false;
            if (s[i + j] != b[j])
                k = false;
        }
        if (!t && !k)
            continue;

        m.push_back(i);
    }

    ll max = 0;
    vector<ll> dp(m.size());
    REP(i, m.size())
    {
        dp[i] = 1;
        REP(j, i)
        {
            if (m[j] + 5 > m[i])
                continue;
            dp[i] = std::max(dp[i], dp[j] + 1);
        }
        max = std::max(max, dp[i]);
    }
    return max;
}

int main()
{
    ll N;
    cin >> N;
    vector<ll> v;
    REP(i, N)
    {
        string S;
        cin >> S;
        v.push_back(solve(S));
    }
    REP(i, N)
    {
        cout << v[i] << endl;
    }
    return 0;
}