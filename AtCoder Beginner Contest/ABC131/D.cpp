#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for (ll(i) = (m); (i) < (n); ++(i))
#define REP(i, n) FOR(i, n, 0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll)1e15;

pll A[200005];

int main()
{
    ll N;
    cin >> N;
    REP(i, N)
    {
        cin >> A[i].first >> A[i].second;
    }
    sort(A, A + N, [](pll a, pll b) { return a.second < b.second; });
    ll t = 0;
    bool f = true;
    REP(i, N)
    {
        t += A[i].first;
        if (A[i].second < t)
            f = false;
    }
    if (f)
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
    return 0;
}