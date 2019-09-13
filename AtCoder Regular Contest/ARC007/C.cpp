#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for (ll(i) = (m); (i) < (n); ++(i))
#define REP(i, n) FOR(i, n, 0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll)1e15;

string S;
ll N;
vector<ll> mi;

//! n個使って埋められるか？
ll solve(vector<string> v, vector<ll> os, ll index)
{
    FOR(i, N, index)
    {
        ll m = 0;
        REP(j, v.size())
        {
            if (v[j][(i + os[j] + N) % N] == 'x')
                m++;
        }
        if (m != v.size())
            continue;

        ll min = INF;
        v.push_back(S);
        REP(j, mi.size())
        {
            os.push_back(mi[j] - i);
            min = std::min(min, solve(v, os, i));
            os.pop_back();
        }
        return min;
    }
    return v.size();
}

int main()
{
    cin >> S;
    N = S.length();
    ll m = 0;
    REP(i, N)
    {
        if (S[i] == 'o')
        {
            m++;
            mi.push_back(i);
        }
    }

    vector<string> v;
    v.push_back(S);
    vector<ll> os;
    os.push_back(0);
    cout << solve(v, os, 0) << endl;
    return 0;
}