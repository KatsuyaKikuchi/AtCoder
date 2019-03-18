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
    int A, B, C, D, E, F;
    cin >> A >> B >> C >> D >> E >> F;

    ll m = 100 * A, n = 0;
    for (int a = 0; a * A * 100 <= F; ++a)
    {
        for (int b = 0; b * B * 100 + a * A * 100 <= F; ++b)
        {
            for (int c = 0; c * C + b * B * 100 + a * A * 100 <= F; ++c)
            {
                for (int d = 0; d * D + c * C + b * B * 100 + a * A * 100 <= F; ++d)
                {
                    if (E * (a * A + b * B) < c * C + d * D)
                        break;
                    if (100 * n * (100 * a * A + 100 * b * B + c * C + d * D) < 100 * (c * C + d * D) * m)
                    {
                        m = 100 * a * A + 100 * b * B + c * C + d * D;
                        n = c * C + d * D;
                    }
                }
            }
        }
    }
    cout << m << " " << n << endl;
    return 0;
}