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
ll S[100005];
ll T[100005];

int main()
{
    ll N, K;
    cin >> N >> K;
    S[0] = T[0] = 0;
    REP(i, N)
    {
        cin >> A[i];
        S[i + 1] += S[i] + A[i];
        T[i + 1] += T[i] + std::max(0LL, A[i]);
    }

    ll max = -INF;
    REP(i, N)
    {
        if (i + K > N)
            break;
        ll m = T[i] + std::max(S[i + K] - S[i], 0LL) + T[N] - T[i + K];
        max = std::max(max, m);
    }
    cout << max << endl;
    return 0;
}