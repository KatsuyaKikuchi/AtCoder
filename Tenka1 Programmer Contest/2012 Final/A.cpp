#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for (ll(i) = (m); (i) < (n); ++(i))
#define REP(i, n) FOR(i, n, 0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll)1e15;

vector<ll> fib;

int main()
{
    ll N;
    cin >> N;
    fib.push_back(1);
    fib.push_back(2);
    while (N > fib[fib.size() - 1])
    {
        ll s = fib.size();
        fib.push_back(fib[s - 1] + fib[s - 2]);
    }
    ll sum = 0;
    ll li = fib.size() - 1;
    while (N > 0)
    {
        if (N < fib[li])
        {
            li--;
        }
        else
        {
            N -= fib[li];
            sum++;
        }
    }
    cout << sum << endl;
    return 0;
}