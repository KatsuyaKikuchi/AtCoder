#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for (ll(i) = (m); (i) < (n); ++(i))
#define REP(i, n) FOR(i, n, 0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll)1e15;

ll H[100005];
ll R[100005];

int main()
{
    ll N;
    cin >> N;
    REP(i, N)
    {
        cin >> H[i];
    }

    memset(R, 0, sizeof(R));
    FOR(i, N, 1)
    {
        if (H[N - 1 - i] >= H[N - i])
        {
            R[N - 1 - i] = R[N - i] + 1;
        }
    }

    ll max = 0;
    REP(i, N)
    {
        max = std::max(max, R[i]);
    }
    cout << max << endl;
    return 0;
}