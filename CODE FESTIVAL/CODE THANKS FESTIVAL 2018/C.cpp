#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for (ll(i) = (m); (i) < (n); ++(i))
#define REP(i, n) FOR(i, n, 0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll)1e15;

ll X[100005];

int main()
{
    int N;
    cin >> N;
    REP(i, N)
    {
        cin >> X[i];
    }
    sort(X, X + N);
    ll r = 0;
    FOR(i, N, 1)
    {
        r += abs(X[i] - X[0]);
    }
    ll sum = r;
    FOR(i, N, 1)
    {
        ll t = X[i] - X[i - 1];
        r -= (N - i) * t;
        sum += r;
    }
    cout << sum << endl;
    return 0;
}