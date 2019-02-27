#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for (ll(i) = (m); (i) < (n); ++(i))
#define REP(i, n) FOR(i, n, 0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll)1e15;

int main()
{
    int n = 0;
    REP(i, 12)
    {
        string s;
        cin >> s;
        REP(j, s.length())
        {
            if (s[j] == 'r')
            {
                ++n;
                break;
            }
        }
    }
    cout << n << endl;
    return 0;
}