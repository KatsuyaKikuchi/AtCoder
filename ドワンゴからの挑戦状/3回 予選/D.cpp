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
bool U[100005];

int main()
{
    int N, M;
    cin >> N >> M;
    M = std::min(N, M);
    priority_queue<pll, vector<pll>, function<bool(pll, pll)>> q([](pll a, pll b) { return a.first < b.first; });
    ll sum = 0;
    REP(i, N)
    {
        cin >> A[i].first >> A[i].second;
        sum += A[i].second;
        q.push(pll(A[i].first - A[i].second, i));
    }

    memset(U, 0, sizeof(U));
    ll s = 0;
    REP(i, M - 1)
    {
        pll t = q.top();
        q.pop();
        s += t.first;
        U[t.second] = true;
    }

    ll max = 0;
    for (int i = N - 1; i >= 0; --i)
    {
        if (U[i])
        {
            s -= A[i].first - A[i].second;
            while (!q.empty())
            {
                pll t = q.top();
                q.pop();
                if (t.second >= i)
                    continue;
                s += t.first;
                U[t.second] = true;
                break;
            }
        }
        max = std::max(max, sum + s + A[i].first - A[i].second);
        sum -= A[i].second;
    }
    cout << max << endl;
    return 0;
}