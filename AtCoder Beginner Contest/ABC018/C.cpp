#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for (ll(i) = (m); (i) < (n); ++(i))
#define REP(i, n) FOR(i, n, 0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll)1e15;

ll R, C, K;
string M[505];
ll S[505][505];

bool check(ll h, ll w)
{
    if (h - K + 1 < 0 || w - K + 1 < 0 || h + K - 1 >= R || w + K - 1 >= C)
        return false;
    REP(i, K)
    {
        {
            //! 上
            ll th = h - i;
            ll r = w + K - 1 - i;
            ll l = w - K + 1 + i;
            if (S[th][r + 1] - S[th][l] > 0)
                return false;
        }
        {
            //! 下
            ll th = h + i;
            ll r = w + K - 1 - i;
            ll l = w - K + 1 + i;
            if (S[th][r + 1] - S[th][l] > 0)
                return false;
        }
    }
    return true;
}

int main()
{
    cin >> R >> C >> K;
    REP(i, R)
    {
        cin >> M[i];
    }
    memset(S, 0, sizeof(S));
    REP(i, R)
    {
        REP(j, C)
        {
            S[i][j + 1] += S[i][j];
            if (M[i][j] == 'x')
                S[i][j + 1]++;
        }
    }
    ll ans = 0;
    REP(i, R)
    {
        REP(j, C)
        {
            if (check(i, j))
                ans++;
        }
    }
    cout << ans << endl;
    return 0;
}