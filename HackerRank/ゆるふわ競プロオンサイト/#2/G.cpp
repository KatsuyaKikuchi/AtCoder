#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for (ll(i) = (m); (i) < (n); ++(i))
#define REP(i, n) FOR(i, n, 0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll)1e15;

ll A[505][505];
ll F[505][505];

int main()
{
    ll R, C;
    cin >> R >> C;
    REP(i, R)
    {
        REP(j, C)
        {
            cin >> A[i][j];
        }
    }
    memset(F, 0, sizeof(F));
    ll Q;
    cin >> Q;
    REP(i, Q)
    {
        ll a, b, c, d;
        cin >> a >> b >> c >> d;
        F[a - 1][c - 1]++;
        F[b][c - 1]--;
        F[a - 1][d]--;
        F[b][d]++;

        cin >> a >> b >> c >> d;
        F[a - 1][c - 1]++;
        F[b][c - 1]--;
        F[a - 1][d]--;
        F[b][d]++;
    }

    REP(i, R)
    {
        REP(j, C)
        {
            F[i][j + 1] += F[i][j];
        }
    }
    REP(j, C)
    {
        REP(i, R)
        {
            F[i + 1][j] += F[i][j];
        }
    }

    // REP(i, R)
    // {
    //     REP(j, C)
    //     {
    //         cout << F[i][j];
    //     }
    //     cout << endl;
    // }

    ll sum = 0;
    REP(i, R)
    {
        REP(j, C)
        {
            if (F[i][j] % 2 == 1)
                sum += A[i][j];
        }
    }
    cout << sum << endl;
    return 0;
}