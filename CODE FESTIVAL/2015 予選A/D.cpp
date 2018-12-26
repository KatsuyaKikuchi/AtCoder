#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for (ll(i) = (m); (i) < (n); ++(i))
#define REP(i, n) FOR(i, n, 0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll)1e15;

ll N, M;
ll X[100005];

//! m分以内に点検完了できるか
bool isPossible(ll m)
{
    ll left = 1;
    REP(i, M)
    {
        ll n = std::max(X[i] - left, (ll)0);
        if (n > m)
            return false;
        left = std::max(left, X[i] + std::max((m - n) / 2, m - 2 * n)) + 1;
    }
    return left >= N + 1;
}

int main()
{
    cin >> N >> M;
    REP(i, M)
    {
        cin >> X[i];
    }

    ll ok = N * 2, ng = -1;
    while (abs(ok - ng) > 1)
    {
        ll mid = (ok + ng) / 2;
        if (isPossible(mid))
        {
            ok = mid;
        }
        else
        {
            ng = mid;
        }
    }
    cout << ok << endl;
    return 0;
}