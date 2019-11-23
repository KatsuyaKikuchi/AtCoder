#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for (ll(i) = (m); (i) < (n); ++(i))
#define REP(i, n) FOR(i, n, 0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll)1e15;

string M[105];

int main()
{
    ll N;
    cin >> N;
    REP(i, N)
    {
        cin >> M[i];
    }
    ll ans = 0;
    REP(i, N)
    {
        REP(j, N)
        {
            if (M[i][N - 1 - j] == 'o')
                continue;
            ans++;

            if (i != N - 1)
            {
                FOR(k, N, N - 1 - j)
                {
                    M[i + 1][k] = 'o';
                }
            }
            break;
        }
    }
    cout << ans << endl;
    return 0;
}