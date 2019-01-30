#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for (ll(i) = (m); (i) < (n); ++(i))
#define REP(i, n) FOR(i, n, 0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll)1e17;

ll X[20], C[20], V[20];
//! [i回めの売却後に]=持っているお金
ll A[20];
//! [bit iで表せる商品を全て買った時の]=価値とコスト
pll B[300000];

//! [お金A[i]を持っていて][bit j商品が売っている時の]=得られる点数最大値
ll dp[20][300000];

//! [i回目の取引で][bit jで表される商品が残っている時の]=高橋くんの最大得点
ll ans[20][300000];

//! 2のi乗
ll D[20];

//! nのbitで立っている1の数
int get(ll n)
{
    int s = 0;
    while (n > 0)
    {
        if ((n & 1) == 1)
            s++;
        n >>= 1;
    }
    return s;
}

int main()
{
    int N;
    cin >> N;
    A[0] = 0;
    REP(i, N)
    {
        cin >> X[i];
        A[i + 1] = X[i] + A[i];
    }
    REP(i, N)
    {
        cin >> C[i];
    }
    REP(i, N)
    {
        cin >> V[i];
    }
    REP(i, N)
    {
        D[i] = pow(2, i);
    }
    ll M = pow(2, N);
    vector<ll> bit(M);
    REP(i, M)
    {
        bit[i] = i;
        pll sum(0, 0);
        REP(j, N)
        {
            if (((i >> j) & 1) == 1)
            {
                sum.first += V[j];
                sum.second += C[j];
            }
        }
        B[i] = sum;
    }
    sort(bit.begin(), bit.end(), [&](ll a, ll b) { return get(a) < get(b); });
    REP(i, M)
    {
        ll m = bit[i];
        REP(j, N + 1)
        {
            ll max = 0;
            if (B[m].second <= A[j])
                max = B[m].first;
            REP(k, N)
            {
                if (((m >> k) & 1) == 0)
                    continue;
                ll t = (M - 1) - D[k];
                max = std::max(max, dp[j][m & t]);
            }
            dp[j][m] = max;
        }
    }

    ans[N][0] = 0;
    FOR(i, M, 1)
    {
        ll m = bit[i];
        ll min = INF;
        int n = N - get(m);
        REP(k, N)
        {
            if (((m >> k) & 1) == 0)
                continue;
            ll t = (M - 1) - pow(2, k);
            min = std::min(min, ans[n + 1][m & t]);
        }
        min = std::max(dp[n][m], min);
        ans[n][m] = min;
    }

    cout << ans[0][M - 1] << endl;
    return 0;
}