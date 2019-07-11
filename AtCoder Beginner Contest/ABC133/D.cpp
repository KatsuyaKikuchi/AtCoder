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

int main()
{
    ll N;
    cin >> N;
    REP(i, N)
    {
        cin >> A[i];
    }

    B[0] = A[0];
    FOR(i, N, 1)
    {
        B[i] = A[i] - B[i - 1];
    }
    B[N - 1] = B[N - 1] / 2;
    FOR(i, N, 1)
    {
        B[N - 1 - i] = A[N - i] - B[N - i];
    }

    REP(i, N)
    {
        cout << B[(i + N - 1) % N] * 2 << " ";
    }
    cout << endl;

    return 0;
}