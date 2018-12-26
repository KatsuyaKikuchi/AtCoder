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
    ll N, T;
    cin >> N >> T;
    ll sum = 0;
    REP(i, N)
    {
        cin >> A[i].first >> A[i].second;
        sum += A[i].first;
    }

    sort(A, A + N, [](pll a, pll b) { return a.first - a.second > b.first - b.second; });
    int ans = 0;
    REP(i, N)
    {
        if (T >= sum)
            break;
        sum += (A[i].second - A[i].first);
        ans++;
    }

    if (T < sum)
    {
        cout << -1 << endl;
    }
    else
    {
        cout << ans << endl;
    }
    return 0;
}