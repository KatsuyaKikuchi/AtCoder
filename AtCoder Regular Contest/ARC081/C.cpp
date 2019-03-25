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

int main()
{
    int N;
    cin >> N;
    REP(i, N)
    {
        cin >> A[i];
    }
    sort(A, A + N, [](ll a, ll b) { return a > b; });
    ll max = 0;
    ll l = 0;
    REP(i, N - 1)
    {
        if (A[i] != A[i + 1])
            continue;
        max = std::max(max, l * A[i]);
        l = A[i++];
    }
    cout << max << endl;
    return 0;
}