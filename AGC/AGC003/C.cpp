#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for (ll(i) = (m); (i) < (n); ++(i))
#define REP(i, n) FOR(i, n, 0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll)1e15;

pll A[100005];

int main()
{
    ll N;
    cin >> N;
    REP(i, N)
    {
        ll a;
        cin >> a;
        A[i] = pll(a, i);
    }
    sort(A, A + N, [](pll a, pll b) { return a.first < b.first; });

    ll ans = 0;
    REP(i, N)
    {
        if (i % 2 == A[i].second % 2)
            continue;
        ans++;
    }
    cout << ans / 2 << endl;
    return 0;
}