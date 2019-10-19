#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for (ll(i) = (m); (i) < (n); ++(i))
#define REP(i, n) FOR(i, n, 0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll)1e15;

ll sum(ll n)
{
    ll s = 0;
    while (n > 0)
    {
        s += n % 10;
        n /= 10;
    }
    return s;
}

int main()
{
    ll N;
    cin >> N;
    vector<ll> v;
    REP(i, 200)
    {
        ll n = N - i;
        if (n < 0)
            break;
        if (sum(n) == i)
            v.push_back(n);
    }

    sort(v.begin(), v.end());
    ll m = v.size();
    cout << m << endl;
    REP(i, m)
    {
        cout << v[i] << endl;
    }
    return 0;
}