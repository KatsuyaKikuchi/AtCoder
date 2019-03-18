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
    pll N[3];
    REP(i, 3)
    {
        cin >> N[i].first;
        N[i].second = i;
    }
    sort(N, N + 3, [](pll a, pll b) { return a.first > b.first; });
    REP(i, 3)
    {
        REP(j, 3)
        {
            if (i == N[j].second)
            {
                cout << j + 1 << endl;
                break;
            }
        }
    }
    return 0;
}