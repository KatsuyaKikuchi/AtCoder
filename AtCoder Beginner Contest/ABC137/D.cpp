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
vector<ll> B[100005];

int main()
{
    ll N, M;
    cin >> N >> M;
    REP(i, N)
    {
        cin >> A[i].first >> A[i].second;
        B[A[i].first].push_back(A[i].second);
    }

    priority_queue<ll, vector<ll>> q;
    ll ans = 0;
    REP(i, M + 1)
    {
        REP(j, B[i].size())
        {
            q.push(B[i][j]);
        }
        if (q.empty())
            continue;

        ll t = q.top();
        q.pop();
        ans += t;
    }
    cout << ans << endl;
    return 0;
}