#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for (ll(i) = (m); (i) < (n); ++(i))
#define REP(i, n) FOR(i, n, 0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll)1e15;

string S[15];

int main()
{
    ll x, y;
    string s;
    cin >> x >> y >> s;
    REP(i, 9)
    {
        cin >> S[i];
    }

    pll v(0, 0);
    REP(i, s.length())
    {
        if (s[i] == 'R')
            v.second++;
        if (s[i] == 'L')
            v.second--;
        if (s[i] == 'U')
            v.first--;
        if (s[i] == 'D')
            v.first++;
    }

    string a = "";
    x--;
    y--;
    REP(i, 4)
    {
        a.push_back(S[y][x]);
        y += v.first;
        x += v.second;
        if (y < 0 || y >= 9)
        {
            v.first *= -1;
            y += 2 * v.first;
        }
        if (x < 0 || x >= 9)
        {
            v.second *= -1;
            x += 2 * v.second;
        }
    }
    cout << a << endl;
    return 0;
}