#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for (ll(i) = (m); (i) < (n); ++(i))
#define REP(i, n) FOR(i, n, 0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll)1e15;

pll S[100005];

int main()
{
    ll N, M;
    cin >> N >> M;
    REP(i, N)
    {
        cin >> S[i].first >> S[i].second;
    }
    sort(S, S + N, [](pll a, pll b) { return a.first < b.first; });

    ll sum = 0;
    REP(i, N)
    {
        if (M <= 0)
            break;
        sum += std::min(S[i].second, M) * S[i].first;
        M -= S[i].second;
    }
    cout << sum << endl;
    return 0;
}