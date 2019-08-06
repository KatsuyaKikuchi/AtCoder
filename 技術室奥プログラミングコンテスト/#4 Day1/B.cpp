#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for (ll(i) = (m); (i) < (n); ++(i))
#define REP(i, n) FOR(i, n, 0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll)1e15;

ll A[200005];

int main()
{
    ll N, K;
    cin >> N >> K;
    int ans = -1;
    REP(i, N)
    {
        cin >> A[i];
        if (A[i] > K)
            continue;
        if (ans == -1 || A[ans] < A[i])
            ans = i;
    }
    if (ans < 0)
        cout << ans << endl;
    else
        cout << ans + 1 << endl;
    return 0;
}