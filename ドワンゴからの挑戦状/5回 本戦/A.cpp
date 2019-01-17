#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for (ll(i) = (m); (i) < (n); ++(i))
#define REP(i, n) FOR(i, n, 0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll)1e15;

bool W[100005];

pll E[100005];
pll P[100005];

int main()
{
    ll N, M, K;
    cin >> N >> M >> K;
    string S;
    cin >> S;
    REP(i, M)
    {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        if (K % 2 == 1)
        {
            if (S[a] == 'B')
                W[b] = true;
            if (S[b] == 'B')
                W[a] = true;
        }
        else
        {
            E[i].first = a;
            E[i].second = b;
            P[a].first++;
            P[b].first++;
            if (S[a] == 'B')
                P[b].second++;
            if (S[b] == 'B')
                P[a].second++;
        }
    }
    if (K % 2 == 0)
    {
        REP(i, M)
        {
            int a = E[i].first, b = E[i].second;
            if (P[a].first == P[a].second)
                W[b] = true;
            if (P[b].first == P[b].second)
                W[a] = true;
        }
    }

    REP(i, N)
    {
        if (W[i])
            cout << "First" << endl;
        else
            cout << "Second" << endl;
    }
    return 0;
}