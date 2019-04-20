#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for (ll(i) = (m); (i) < (n); ++(i))
#define REP(i, n) FOR(i, n, 0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll)1e15;

int main()
{
    int N;
    cin >> N;
    string S;
    cin >> S;
    ll b = 0;
    REP(i, N)
    {
        if (S[i] == '#')
            b++;
    }
    ll w = 0;
    ll min = b;
    for (int i = N - 1; i >= 0; --i)
    {
        if (S[i] == '.')
            w++;
        else if (S[i] == '#')
            b--;
        min = std::min(min, w + b);
    }
    cout << min << endl;
    return 0;
}