#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for (ll(i) = (m); (i) < (n); ++(i))
#define REP(i, n) FOR(i, n, 0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll)1e15;

ll V[100005];

int main()
{
    int N;
    cin >> N;
    REP(i, N)
    {
        cin >> V[i];
    }
    REP(i, N)
    {
        ll c;
        cin >> c;
        V[i] -= c;
    }
    sort(V, V + N, [](ll a, ll b) { return a > b; });
    ll sum = 0;
    REP(i, N)
    {
        if (V[i] < 0)
            break;
        sum += V[i];
    }
    cout << sum << endl;
    return 0;
}