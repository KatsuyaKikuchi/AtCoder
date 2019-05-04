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
    ll A, B, C;
    cin >> A >> B >> C;
    ll sum = A + B * 10;

    FOR(i, sum + 1, 1)
    {
        REP(a, A + 1)
        {
            REP(b, B + 1)
            {
                ll s = a + b * 10;
                if (s < i)
                    continue;

                ll c = s - i;
                if ((A - a + c % 10) + (B - b + c / 10) == C)
                {
                    cout << i << endl;
                    return 0;
                }
            }
        }
    }

    cout << "Impossible" << endl;
    return 0;
}