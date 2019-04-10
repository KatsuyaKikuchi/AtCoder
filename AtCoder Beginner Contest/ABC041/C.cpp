#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for (ll(i) = (m); (i) < (n); ++(i))
#define REP(i, n) FOR(i, n, 0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll)1e15;

pll A[100005];

int main()
{
    int N;
    cin >> N;
    REP(i, N)
    {
        cin >> A[i].first;
        A[i].second = i;
    }
    sort(A, A + N, [](pll a, pll b) { return a.first > b.first; });
    REP(i, N)
    {
        cout << A[i].second + 1 << endl;
    }
    return 0;
}