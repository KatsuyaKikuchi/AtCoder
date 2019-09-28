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
    string S;
    cin >> S;

    vector<ll> v;
    ll n = 1;
    FOR(i, S.length(), 1)
    {
        if (S[i] == S[i - 1])
        {
            v.push_back(n);
            n = 1;
            if (i == S.length() - 1)
            {
                v.push_back(n);
            }
            continue;
        }
        if (S[i] == '#')
            n++;
        if (i == S.length() - 1)
        {
            v.push_back(n);
        }
    }
    if (S.length() == 1)
        v.push_back(1);

    REP(i, v.size())
    {
        cout << v[i] << " ";
    }
    cout << endl;
    return 0;
}