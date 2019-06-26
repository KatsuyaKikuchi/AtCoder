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
    ll N;
    cin >> N;
    REP(i, N)
    {
        cin >> A[i];
    }

    ll x = 2;
    ll sum = A[0] - 1;
    FOR(i, N, 1)
    {
        ll s = (A[i] - 1) / x;
        sum += s;
        if (A[i] == x)
            x++;
    }
    cout << sum << endl;
    return 0;
}