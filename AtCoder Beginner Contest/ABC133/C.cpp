#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for (ll(i) = (m); (i) < (n); ++(i))
#define REP(i, n) FOR(i, n, 0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll)1e15;

bool U[3000];

int main()
{
    ll L, R;
    cin >> L >> R;
    memset(U, 0, sizeof(U));
    FOR(i, R + 1, L)
    {
        if (U[i % 2019])
            break;
        U[i % 2019] = true;
    }

    ll min = 2019;
    REP(i, 2020)
    {
        if (!U[i])
            continue;
        FOR(j, 2020, i + 1)
        {
            if (!U[j])
                continue;
            min = std::min(min, i * j % 2019);
        }
    }
    cout << min << endl;
    return 0;
}