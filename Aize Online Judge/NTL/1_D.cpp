#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for (ll(i) = (m); (i) < (n); ++(i))
#define REP(i, n) FOR(i, n, 0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll)1e15;

bool U[100005];
ll N;

ll dfs(ll n, vector<ll> v, vector<ll> u, int l = 0)
{
    if (u.size() == n)
    {
        ll m = 1;
        REP(i, n)
        {
            m *= u[i];
        }
        return N / m;
    }

    ll sum = 0;
    FOR(i, v.size(), l)
    {
        u.push_back(v[i]);
        sum += dfs(n, v, u, i + 1);
        u.pop_back();
    }
    return sum;
}

int main()
{
    cin >> N;
    ll n = N;

    vector<ll> prime;
    memset(U, 0, sizeof(U));
    FOR(i, 100000, 2)
    {
        if (U[i])
            continue;
        prime.push_back(i);
        for (int j = i; j < 100000; j += i)
            U[j] = true;
    }

    vector<ll> p;
    REP(i, prime.size())
    {
        if (n % prime[i] != 0)
            continue;
        while (n % prime[i] == 0)
            n /= prime[i];
        p.push_back(prime[i]);
    }
    if (n > 1)
        p.push_back(n);

    ll sum = 0;

    FOR(i, p.size() + 1, 1)
    {
        vector<ll> v;
        ll s = dfs(i, p, v);
        if (i % 2 == 1)
            sum += s;
        else
            sum -= s;
    }

    cout << N - sum << endl;

    return 0;
}