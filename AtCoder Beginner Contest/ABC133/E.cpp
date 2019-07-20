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
    vector<ll> n;
};

Vertex V[100005];
bool U[100005];

int main()
{
    ll N, K;
    cin >> N >> K;
    REP(i, N - 1)
    {
        ll a, b;
        cin >> a >> b;
        a--;
        b--;
        V[a].n.push_back(b);
        V[b].n.push_back(a);
    }

    memset(U, 0, sizeof(U));
    queue<ll> q;
    q.push(0);
    U[0] = true;

    ll ans = K;
    while (!q.empty())
    {
        ll t = q.front();
        q.pop();
        ll mul = K - 2;
        if (t == 0)
            mul++;
        REP(i, V[t].n.size())
        {
            ll n = V[t].n[i];
            if (U[n])
                continue;
            ans = (ans * std::max(0LL, mul--)) % MOD;
            U[n] = true;
            q.push(n);
        }
    }

    cout << ans << endl;
    return 0;
}