#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for (ll(i) = (m); (i) < (n); ++(i))
#define REP(i, n) FOR(i, n, 0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll)1e15;

ll H[300005];

int main()
{
    ll N;
    cin >> N;
    REP(i, N)
    {
        cin >> H[i];
    }
    ll max = 0;
    ll s = 0;
    REP(i, N)
    {
        max = std::max(max, i - s + 1);
        if (i > 0 && i < N - 1 && H[i] < H[i - 1] && H[i] < H[i + 1])
            s = i;
    }
    cout << max << endl;
    return 0;
}