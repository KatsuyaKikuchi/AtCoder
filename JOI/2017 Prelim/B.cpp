#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for (ll(i) = (m); (i) < (n); ++(i))
#define REP(i, n) FOR(i, n, 0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll)1e15;

ll A[1005];

int main()
{
    ll N, M;
    cin >> N >> M;
    ll sum = 0;
    REP(i, M)
    {
        ll a, b;
        cin >> a >> b;
        sum += std::max(b - N, 0LL);
        A[i] = a;
    }

    ll min = INF;
    REP(i, M)
    {
        min = std::min(min, std::max(0LL, sum - (N - A[i])));
    }
    cout << min << endl;
    return 0;
}