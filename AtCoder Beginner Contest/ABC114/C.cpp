#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for (ll(i) = (m); (i) < (n); ++(i))
#define REP(i, n) FOR(i, n, 0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll)1e15;

vector<ll> S;
int x[3] = {3, 5, 7};

bool check(ll n)
{
    REP(i, 3)
    {
        ll t = n;
        while (t > 0)
        {
            int k = t % 10;
            if (k == x[i])
                break;
            t /= 10;
            if (t == 0)
                return false;
        }
    }
    return true;
}

void create(ll n, int m)
{
    if (m == 0)
    {
        if (check(n))
            S.push_back(n);
        return;
    }
    n *= 10;
    REP(i, 3)
    {
        create(n + x[i], m - 1);
    }
    return;
}

int main()
{
    ll N;
    cin >> N;
    FOR(i, 10, 3)
    {
        create(0, i);
    }

    int ans = 0;
    REP(i, S.size())
    {
        if (N >= S[i])
        {
            ans = i + 1;
        }
    }
    cout << ans << endl;
    return 0;
}