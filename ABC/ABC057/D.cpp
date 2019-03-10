#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for (ll(i) = (m); (i) < (n); ++(i))
#define REP(i, n) FOR(i, n, 0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll)1e15;

ll V[55];
ll dp[55][55];

ll comb(ll n, ll r)
{
    if (n == r)
        return dp[n][r] = 1;
    if (r == 0)
        return dp[n][r] = 1;
    if (r == 1)
        return dp[n][r] = n;
    if (dp[n][r])
        return dp[n][r];
    return dp[n][r] = comb(n - 1, r) + comb(n - 1, r - 1);
}

int main()
{
    ll N, A, B;
    cin >> N >> A >> B;
    REP(i, N)
    {
        cin >> V[i];
    }
    sort(V, V + N, [](ll a, ll b) { return a > b; });
    vector<pll> v;
    double max = 0;
    ll x = 0, y = 0;
    FOR(i, B + 1, A)
    {
        ll sum = 0;
        ll n = 0;
        REP(j, i)
        {
            sum += V[j];
            if (j > 0 && V[j - 1] == V[j])
                n++;
            else
                n = 1;
        }
        //! V[i-1]と同じ物の数
        ll m = 0;
        REP(j, N)
        {
            if (V[i - 1] == V[j])
                m++;
        }
        v.push_back(pll(sum, comb(m, n)));
        double k = (double)sum / (double)i;
        if (max < k)
        {
            max = k;
            x = sum;
            y = i;
        }
    }

    ll c = 0;
    REP(i, v.size())
    {
        if (x * (A + i) == y * (v[i].first))
            c += v[i].second;
    }
    cout << OF64 << max << endl;
    cout << c << endl;
    return 0;
}