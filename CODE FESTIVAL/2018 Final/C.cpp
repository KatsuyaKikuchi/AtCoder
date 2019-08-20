#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for (ll(i) = (m); (i) < (n); ++(i))
#define REP(i, n) FOR(i, n, 0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll)1e15;

ll A[100005];

int main()
{
    ll N, M;
    cin >> N;
    vector<pll> V;
    REP(i, N)
    {
        ll a, b;
        cin >> a >> b;
        V.push_back(pll(a, b));
    }
    V.push_back(pll(INF, INF));
    sort(V.begin(), V.end(), [](pll a, pll b) { return a.first < b.first; });
    cin >> M;
    REP(i, M)
    {
        ll t;
        cin >> t;
        ll ok = 0, ng = N;
        while (abs(ok - ng) > 1)
        {
            ll mid = (ok + ng) / 2;
            if (V[mid].first <= t)
                ok = mid;
            else
                ng = mid;
        }
        ll index = ok;
        A[i] = std::min(V[index].second + std::max(0LL, t - V[index].first),
                        V[index + 1].second + std::max(0LL, t - V[index + 1].first));
    }

    REP(i, M)
    {
        cout << A[i] << endl;
    }
    return 0;
}