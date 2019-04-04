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

    vector<pair<char, int>> v;
    REP(i, S.length())
    {
        char c = S[i];
        if (v.size() == 0 || v[v.size() - 1].first != c)
            v.push_back(pair<char, int>(c, 1));
        else
            v[v.size() - 1].second++;
    }
    REP(i, v.size())
    {
        cout << v[i].first << v[i].second;
    }
    cout << endl;
    return 0;
}