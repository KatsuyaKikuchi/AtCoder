#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for (ll(i) = (m); (i) < (n); ++(i))
#define REP(i, n) FOR(i, n, 0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll)1e15;

ll F[105][15];
ll P[105][15];

int main()
{
    int N;
    cin >> N;
    REP(i, N)
    {
        REP(j, 10)
        {
            cin >> F[i][j];
        }
    }
    REP(i, N)
    {
        REP(j, 11)
        {
            cin >> P[i][j];
        }
    }

    ll max = -INF;
    for (int i = 1; i < 1024; ++i)
    {
        ll sum = 0;
        //! 店iと同時に開店している数
        vector<int> n(N);
        REP(j, 10)
        {
            if (((i >> j) & 1) == 0)
                continue;
            REP(k, N)
            {
                if (F[k][j] == 1)
                    n[k]++;
            }
        }
        REP(i, N)
        {
            sum += P[i][n[i]];
        }
        max = std::max(max, sum);
    }
    cout << max << endl;
    return 0;
}