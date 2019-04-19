#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for (ll(i) = (m); (i) < (n); ++(i))
#define REP(i, n) FOR(i, n, 0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll)1e15;

ll B[5];

int main()
{
    int N;
    cin >> N;
    memset(B, 0, sizeof(B));
    REP(i, N)
    {
        ll a;
        cin >> a;
        B[a]++;
    }
    ll sum = B[4] + B[3] + B[2] / 2;
    B[1] -= std::min(B[3], B[1]);
    B[2] %= 2;
    B[1] -= std::min(B[2] * 2, B[1]);
    sum += B[2] + (B[1] + 3) / 4;
    cout << sum << endl;
    return 0;
}