#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for (ll(i) = (m); (i) < (n); ++(i))
#define REP(i, n) FOR(i, n, 0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll)1e15;

ll N, K;
ll A[200005];
vector<ll> B[200005];
bool U[200005];

vector<ll> solve(ll n)
{
    stack<ll> s;
    memset(U, 0, sizeof(U));
    FOR(i, N, n)
    {
        ll m = A[i];
        if (!U[m])
        {
            s.push(m);
            U[m] = true;
            continue;
        }

        while (!s.empty())
        {
            ll t = s.top();
            s.pop();
            U[t] = false;
            if (t == m)
                break;
        }
    }

    vector<ll> v;
    while (!s.empty())
    {
        ll t = s.top();
        s.pop();
        v.push_back(t);
    }
    return v;
}

int main()
{
    cin >> N >> K;
    REP(i, N)
    {
        cin >> A[i];
        B[A[i]].push_back(i);
    }

    ll loop = 1;
    ll index = 0;
    while (true)
    {
        ll t = A[index];
        ll i = lower_bound(B[t].begin(), B[t].end(), index) - B[t].begin();
        i = (i + 1) % B[t].size();
        ll nxt = (B[t][i] + 1) % N;

        if (index >= nxt - 1)
        {
            if (nxt != 0 || index == N - 1)
                loop++;
        }
        //cout << index << "->" << nxt << " " << loop << endl;
        index = nxt;
        if (index == 0)
            break;
    }

    ll n = K % loop;
    index = 0;
    loop = 1;
    while (true)
    {
        if (loop >= n)
            break;
        ll t = A[index];
        ll i = lower_bound(B[t].begin(), B[t].end(), index) - B[t].begin();
        i = (i + 1) % B[t].size();
        ll nxt = (B[t][i] + 1) % N;

        if (index >= nxt - 1)
            loop++;
        index = nxt;
    }

    auto v = solve(index);

    if (n > 0)
    {
        REP(i, v.size())
        {
            cout << v[v.size() - 1 - i] << " ";
        }
    }
    cout << endl;
    return 0;
}