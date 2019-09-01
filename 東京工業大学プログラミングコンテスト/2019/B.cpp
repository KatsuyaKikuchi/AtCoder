#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for (ll(i) = (m); (i) < (n); ++(i))
#define REP(i, n) FOR(i, n, 0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll)1e15;

string x = "okyo";
string y = "ech";

string solve(string s)
{
    ll n = s.length();
    bool t = false;
    REP(i, n)
    {
        if (i + x.length() <= n)
        {
            bool e = true;
            REP(j, x.length())
            {
                if (s[i + j] != x[j])
                {
                    e = false;
                    break;
                }
            }
            if (e)
                t = true;
        }
        if (i + y.length() <= n)
        {
            bool e = true;
            REP(j, y.length())
            {
                if (s[i + j] != y[j])
                {
                    e = false;
                    break;
                }
            }
            if (e && t)
                return "Yes";
        }
    }
    return "No";
}

int main()
{
    ll N;
    cin >> N;
    REP(i, N)
    {
        string S;
        cin >> S;
        cout << solve(S) << endl;
    }
    return 0;
}