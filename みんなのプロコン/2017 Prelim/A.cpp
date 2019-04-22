#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for (ll(i) = (m); (i) < (n); ++(i))
#define REP(i, n) FOR(i, n, 0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll)1e15;

bool u[5];

int main()
{
    string S;
    cin >> S;
    string s = "yahoo";
    REP(i, S.length())
    {
        REP(j, s.length())
        {
            if (u[j])
                continue;
            if (s[j] == S[i])
            {
                u[j] = true;
                break;
            }
        }
    }
    bool f = true;
    REP(i, 5)
    {
        if (!u[i])
            f = false;
    }
    if (f)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
    return 0;
}