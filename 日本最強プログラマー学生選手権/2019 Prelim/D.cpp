#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for (ll(i) = (m); (i) < (n); ++(i))
#define REP(i, n) FOR(i, n, 0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll)1e15;

ll S[505][505];

int main()
{
    ll N;
    cin >> N;
    memset(S, 0, sizeof(S));
    FOR(n, 10, 1)
    {
        ll p = pow(2LL, n);
        REP(i, N)
        {
            FOR(j, N, i + 1)
            {
                if (i % p != j % p)
                {
                    if (S[i][j] > 0)
                        continue;
                    S[i][j] = n;
                }
            }
        }
    }

    REP(i, N - 1)
    {
        FOR(j, N, i + 1)
        {
            cout << S[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}