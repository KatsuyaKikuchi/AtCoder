#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for (ll(i) = (m); (i) < (n); ++(i))
#define REP(i, n) FOR(i, n, 0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll)1e15;

int main()
{
    int N, K;
    cin >> N >> K;
    priority_queue<pll, vector<pll>, function<bool(pll, pll)>> q([](pll a, pll b) { return a.first > b.first; });
    REP(i, N)
    {
        pll t;
        cin >> t.first >> t.second;
        q.push(t);
    }

    ll sum = 0;
    REP(i, K)
    {
        pll t = q.top();
        q.pop();
        sum += t.first;
        q.push(pll(t.first + t.second, t.second));
    }
    cout << sum << endl;
    return 0;
}