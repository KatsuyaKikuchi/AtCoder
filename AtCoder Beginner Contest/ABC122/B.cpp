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
    string S;
    cin >> S;
    ll max = 0;
    REP(i, S.length())
    {
        ll m = 0;
        REP(j, S.length())
        {
            if (i + j >= S.length())
                break;
            if (S[i + j] == 'A' || S[i + j] == 'G' || S[i + j] == 'C' || S[i + j] == 'T')
            {
                m++;
                continue;
            }
            break;
        }
        max = std::max(m, max);
    }
    cout << max << endl;
    return 0;
}