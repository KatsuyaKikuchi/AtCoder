#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for (ll(i) = (m); (i) < (n); ++(i))
#define REP(i, n) FOR(i, n, 0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll)1e15;

int main()
{
    int N, K;
    cin >> N >> K;
    ll sum = 0;
    REP(i, N)
    {
        int x;
        cin >> x;
        sum += std::min(x, K - x) * 2;
    }
    cout << sum << endl;
    return 0;
}