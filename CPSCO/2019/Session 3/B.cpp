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
    ll N, M;
    cin >> N >> M;
    REP(i, N)
    {
        cin >> A[i];
    }
    sort(A, A + N, [](ll a, ll b) { return a > b; });
    ll sum = 0;
    REP(i, N)
    {
        sum += A[i];
        if (sum >= M)
        {
            cout << i + 1 << endl;
            break;
        }
    }
    return 0;
}