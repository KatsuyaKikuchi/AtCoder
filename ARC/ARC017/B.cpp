#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for (ll(i) = (m); (i) < (n); ++(i))
#define REP(i, n) FOR(i, n, 0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll)1e15;

ll A[300005];

int main()
{
    ll N, K;
    cin >> N >> K;
    REP(i, N)
    {
        cin >> A[i];
    }
    ll k = 0;
    ll sum = 0;
    REP(i, N)
    {
        if (i == 0 || A[i] > A[i - 1])
            k++;
        else
            k = 1;

        if (k >= K)
        {
            sum++;
            k--;
        }
    }
    cout << sum << endl;
    return 0;
}