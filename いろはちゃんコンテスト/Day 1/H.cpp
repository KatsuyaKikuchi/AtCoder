#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for (ll(i) = (m); (i) < (n); ++(i))
#define REP(i, n) FOR(i, n, 0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll)1e15;

ll get(ll n)
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
    ll sum = get(N);

    vector<int> a;
    while (sum > 0)
    {
        ll m = std::min(9LL, sum);
        a.push_back(m);
        sum -= m;
    }

    ll s = 0;
    REP(i, a.size())
    {
        s += a[i] * pow(10LL, i);
    }

    if (s == N)
    {
        a.push_back(0);
        FOR(i, a.size(), 1)
        {
            ll n = a.size() - 1 - i;
            if (a[n] == 9 || (a[n+1] != 0)||n==0)
            {
                a[n+1]++;
                a[n]--;
                break;
            }
        }

        REP(i, a.size())
        {
            ll n = a.size() - 1 - i;
            if (a[n] == 0&&n==a.size()-1)
                continue;
            cout << a[n];
        }
        cout << endl;
    }
    else
    {
        cout << s << endl;
    }

    return 0;
}