#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for (ll(i) = (m); (i) < (n); ++(i))
#define REP(i, n) FOR(i, n, 0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll)1e15;

vector<ll> M = {1, 3, 2, 1, 2, 1, 2, 3, 1};
vector<ll> E = {1, 0, 0, 0, 1, 0, 0, 0, 1};
vector<ll> V = {2, 1, 1};

vector<ll> mul(vector<ll> m, vector<ll> n)
{
    vector<ll> v;
    REP(i, 3)
    {
        REP(j, 3)
        {
            ll s = 0;
            REP(k, 3)
            {
                s += m[i * 3 + k] * n[j + k * 3];
            }
            v.push_back(s % MOD);
        }
    }
    return v;
}

int main()
{
    ll N;
    cin >> N;
    N--;
    REP(i, 61)
    {
        if (((N >> i) & 1) == 1)
        {
            E = mul(M, E);
        }
        M = mul(M, M);
    }

    ll sum = 0;
    REP(i, 3)
    {
        REP(j, 3)
        {
            sum += E[i * 3 + j] * V[j];
        }
    }
    sum = 2 * sum % MOD;
    cout << sum << endl;
    return 0;
}