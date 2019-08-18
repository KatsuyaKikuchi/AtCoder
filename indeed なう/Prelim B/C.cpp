#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for (ll(i) = (m); (i) < (n); ++(i))
#define REP(i, n) FOR(i, n, 0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll)1e15;

struct Vertex
{
    vector<int> node;
};
Vertex V[100005];
bool U[100005];

int main()
{
    ll N;
    cin >> N;
    REP(i, N - 1)
    {
        ll a, b;
        cin >> a >> b;
        a--;
        b--;
        V[a].node.push_back(b);
        V[b].node.push_back(a);
    }
    memset(U, 0, sizeof(U));
    priority_queue<ll, vector<ll>, function<bool(ll, ll)>> q([](ll a, ll b) { return a > b; });
    q.push(0);
    vector<ll> ans;
    while (!q.empty())
    {
        ll t = q.top();
        q.pop();
        if (U[t])
            continue;
        U[t] = true;
        ans.push_back(t + 1);
        REP(i, V[t].node.size())
        {
            ll n = V[t].node[i];
            if (U[n])
                continue;
            q.push(n);
        }
    }

    REP(i, N)
    {
        cout << ans[i];
        if (i < N - 1)
            cout << " ";
    }
    cout << endl;
    return 0;
}