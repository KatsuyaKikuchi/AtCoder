#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for (ll(i) = (m); (i) < (n); ++(i))
#define REP(i, n) FOR(i, n, 0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll)1e15;

ll D[200005];

int main()
{
    ll N, A, B;
    cin >> N >> A >> B;
    REP(i, B)
    {
        cin >> D[i];
    }
    sort(D, D + B);
    ll sum = 0;
    ll p = 0;
    REP(i, B)
    {
        sum++;
        ll q = D[i] - p;
        p = D[i];
        sum += (q - 1) / A;
    }

    sum += (N - p) / A;
    cout << N-sum << endl;
    return 0;
}