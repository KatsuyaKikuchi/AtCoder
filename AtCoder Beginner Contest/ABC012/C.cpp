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
    ll N;
    cin >> N;
    ll m = 2025 - N;
    REP(i, 9)
    {
        REP(j, 9)
        {
            int k = (i + 1) * (j + 1);
            if (k == m)
            {
                cout << i + 1 << " x " << j + 1 << endl;
            }
        }
    }
    return 0;
}