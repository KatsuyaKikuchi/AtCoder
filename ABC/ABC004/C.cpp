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
    ll N;
    cin >> N;
    vector<string> v;
    v.push_back("123456");
    REP(i, N)
    {
        string s = v[i];
        swap(s[i % 5], s[i % 5 + 1]);
        if (s == v[0])
            break;
        v.push_back(s);
    }

    cout << v[N % v.size()] << endl;
    return 0;
}