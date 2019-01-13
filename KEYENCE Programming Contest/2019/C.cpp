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
ll B[100005];
ll S[100005];
bool U[100005];

int main()
{
    int N;
    cin >> N;
    ll asum = 0;
    REP(i, N)
    {
        cin >> A[i];
        asum += A[i];
    }
    ll bsum = 0;
    REP(i, N)
    {
        cin >> B[i];
        S[i] = A[i] - B[i];
        bsum += B[i];
    }
    if (asum < bsum)
    {
        cout << -1 << endl;
        return 0;
    }
    sort(S, S + N, [](ll a, ll b) { return a > b; });
    int si = 0;
    int sum = 0;
    ll cost = 0;
    REP(i, N)
    {
        ll d = B[i] - A[i];
        if (d <= 0)
        {
            continue;
        }
        sum++;
        while (d > 0)
        {
            if (!U[si])
            {
                sum++;
                U[si] = true;
            }
            ll e = std::min(d, S[si]);
            d -= e;
            S[si] -= e;
            if (d > 0)
            {
                si++;
            }
        }
    }
    cout << sum << endl;
    return 0;
}