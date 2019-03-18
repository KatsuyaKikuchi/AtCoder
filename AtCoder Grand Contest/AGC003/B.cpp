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
    REP(i, N - 1)
    {
        if (A[i] % 2 == 1)
        {
            ll s = std::min(1LL, A[i + 1]);
            A[i] += s;
            A[i + 1] -= s;
        }
    }
    ll sum = 0;
    REP(i, N)
    {
        sum += A[i] / 2;
    }
    cout << sum << endl;
    return 0;
}