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
    priority_queue<ll, vector<ll>, function<bool(ll, ll)>> q([](ll a, ll b) { return a < b; });
    REP(i, N)
    {
        ll a;
        cin >> a;
        q.push(a);
    }

    REP(i, M)
    {
        ll t = q.top();
        q.pop();
        q.push(t / 2);
    }

    ll sum = 0;
    while (!q.empty())
    {
        ll t = q.top();
        q.pop();
        sum += t;
    }
    cout << sum << endl;
    return 0;
}