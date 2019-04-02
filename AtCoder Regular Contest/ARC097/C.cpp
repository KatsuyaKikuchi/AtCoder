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
    ll K;
    cin >> K;
    vector<string> v;
    REP(i, S.length())
    {
        string s = "";
        REP(j, K)
        {
            if (j + i >= S.length())
                break;
            s.push_back(S[j + i]);
            v.push_back(s);
        }
    }
    sort(v.begin(), v.end());
    v.erase(unique(v.begin(), v.end()), v.end());
    cout << v[K - 1] << endl;
    return 0;
}