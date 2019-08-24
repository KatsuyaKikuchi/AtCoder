#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for (ll(i) = (m); (i) < (n); ++(i))
#define REP(i, n) FOR(i, n, 0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll)1e15;

string S[2005];
ll L[2005][2005];
ll R[2005][2005];
ll U[2005][2005];
ll D[2005][2005];

int main()
{
    ll H, W;
    cin >> H >> W;
    REP(i, H)
    {
        cin >> S[i];
    }

    REP(i, H)
    {
        REP(j, W)
        {
            if (S[i][j] == '#')
                L[i][j] = 0;
            else
                L[i][j] = j > 0 ? L[i][j - 1] + 1 : 1;

            if (S[i][W - 1 - j] == '#')
                R[i][W - 1 - j] = 0;
            else
                R[i][W - 1 - j] = j < W - 1 ? R[i][W - j] + 1 : 1;
        }
    }

    REP(i, W)
    {
        REP(j, H)
        {
            if (S[j][i] == '#')
                U[j][i] = 0;
            else
                U[j][i] = j > 0 ? U[j - 1][i] + 1 : 1;

            if (S[H - 1 - j][i] == '#')
                D[H - 1 - j][i] = 0;
            else
                D[H - 1 - j][i] = j < H - 1 ? D[H - j][i] + 1 : 1;
        }
    }

    ll max = 0;
    REP(i, H)
    {
        REP(j, W)
        {
            if (S[i][j] == '#')
                continue;
            ll n = L[i][j] + R[i][j] + U[i][j] + D[i][j] - 3;
            max = std::max(max, n);
        }
    }
    cout << max << endl;
    return 0;
}