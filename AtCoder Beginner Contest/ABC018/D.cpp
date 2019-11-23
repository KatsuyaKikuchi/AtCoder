#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for (ll(i) = (m); (i) < (n); ++(i))
#define REP(i, n) FOR(i, n, 0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll)1e15;

vector<pll> C[400];
ll S[20];

int main()
{
    ll N, M, P, Q, R;
    cin >> N >> M >> P >> Q >> R;
    REP(i, R)
    {
        ll a, b, c;
        cin >> a >> b >> c;
        C[a - 1].push_back(pll(b - 1, c));
    }

    ll ans = 0;
    ll p = pow(2, N);
    REP(i, p)
    {
        ll num = 0;
        REP(j, N)
        {
            if (((i >> j) & 1) == 1)
                num++;
        }
        if (num != P)
            continue;
        memset(S, 0, sizeof(S));
        REP(j, N)
        {
            if (((i >> j) & 1) == 0)
                continue;

            REP(k, C[j].size())
            {
                S[C[j][k].first] += C[j][k].second;
            }
        }
        sort(S, S + M, [](ll a, ll b) { return a > b; });
        ll sum = 0;
        REP(j, Q)
        {
            sum += S[j];
        }
        ans = std::max(ans, sum);
    }
    cout << ans << endl;
    return 0;
}