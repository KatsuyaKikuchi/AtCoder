#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for (ll(i) = (m); (i) < (n); ++(i))
#define REP(i, n) FOR(i, n, 0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll)1e15;

string Map[1005];
ll J[1005][1005];
ll O[1005][1005];
ll I[1005][1005];

int main()
{
    ll N, M, K;
    cin >> M >> N >> K;
    REP(i, M)
    {
        cin >> Map[i];
    }
    memset(J, 0, sizeof(J));
    memset(O, 0, sizeof(O));
    memset(I, 0, sizeof(I));
    REP(i, M)
    {
        REP(j, N)
        {
            if (Map[i][j] == 'J')
                J[i + 1][j + 1]++;
            else if (Map[i][j] == 'O')
                O[i + 1][j + 1]++;
            else if (Map[i][j] == 'I')
                I[i + 1][j + 1]++;
        }
    }

    FOR(i, M + 1, 1)
    {
        FOR(j, N + 1, 1)
        {
            J[i][j + 1] += J[i][j];
            O[i][j + 1] += O[i][j];
            I[i][j + 1] += I[i][j];
        }
    }

    FOR(j, N + 1, 1)
    {
        FOR(i, M + 1, 1)
        {
            J[i + 1][j] += J[i][j];
            O[i + 1][j] += O[i][j];
            I[i + 1][j] += I[i][j];
        }
    }

    REP(i, K)
    {
        pll a, b;
        cin >> a.first >> a.second >> b.first >> b.second;

        ll nj = J[b.first][b.second] - (J[b.first][a.second - 1] + J[a.first - 1][b.second]) + J[a.first - 1][a.second - 1];
        ll no = O[b.first][b.second] - (O[b.first][a.second - 1] + O[a.first - 1][b.second]) + O[a.first - 1][a.second - 1];
        ll ni = I[b.first][b.second] - (I[b.first][a.second - 1] + I[a.first - 1][b.second]) + I[a.first - 1][a.second - 1];

        cout << nj << " " << no << " " << ni << endl;
    }
    return 0;
}