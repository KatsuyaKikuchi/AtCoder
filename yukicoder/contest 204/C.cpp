#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for (ll(i) = (m); (i) < (n); ++(i))
#define REP(i, n) FOR(i, n, 0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll)1e15;

ll S[10000005] = {0};

int main()
{
    ll X, Y;
    cin >> X >> Y;

    for (int i = 0; i * i <= Y; ++i)
    {
        for (int j = 1; j * j <= Y; ++j)
        {
            if (i * i + j * j > Y)
                break;
            S[i * i + j * j]++;
        }
    }

    ll max = 0;
    FOR(i, Y + 1, X)
    {
        max = std::max(S[i], max);
    }
    cout << max * 4 << endl;
    return 0;
}