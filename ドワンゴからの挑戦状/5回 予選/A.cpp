#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for (ll(i) = (m); (i) < (n); ++(i))
#define REP(i, n) FOR(i, n, 0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll)1e15;

ll A[105];

int main()
{
    ll N;
    cin >> N;
    ll s = 0;
    REP(i, N)
    {
        cin >> A[i];
        s += A[i];
    }
    ll min = 0;
    REP(i, N)
    {
        if (abs(A[i] * N - s) < abs(A[min] * N - s))
            min = i;
    }
    cout << min << endl;
    return 0;
}