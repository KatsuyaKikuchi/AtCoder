#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for (ll(i) = (m); (i) < (n); ++(i))
#define REP(i, n) FOR(i, n, 0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll)1e15;

char D[10][2] = {{'z', 'r'}, {'b', 'c'}, {'d', 'w'}, {'t', 'j'}, {'f', 'q'}, {'l', 'v'}, {'s', 'x'}, {'p', 'm'}, {'h', 'k'}, {'n', 'g'}};

string get(string s)
{
    string t = "";
    REP(i, s.length())
    {
        char c = tolower(s[i]);
        REP(a, 10)
        {
            REP(b, 2)
            {
                if (D[a][b] == c)
                    t.push_back(a + '0');
            }
        }
    }
    return t;
}

int main()
{
    ll N;
    cin >> N;
    vector<string> v;
    REP(i, N)
    {
        string s;
        cin >> s;
        string t = get(s);
        if (t.size() > 0)
            v.push_back(t);
    }

    REP(i, v.size())
    {
        cout << v[i];
        if (i < v.size() - 1)
            cout << " ";
    }
    cout << endl;
    return 0;
}