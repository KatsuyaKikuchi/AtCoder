#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for (ll(i) = (m); (i) < (n); ++(i))
#define REP(i, n) FOR(i, n, 0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll)1e15;

string S[410];
//! すでに通ったますか？
bool M[405][405];

int x[4] = {1, 0, -1, 0};
int y[4] = {0, 1, 0, -1};

int main()
{
    int H, W;
    cin >> H >> W;
    REP(i, H)
    {
        cin >> S[i];
    }

    ll sum = 0;
    REP(h, H)
    {
        REP(w, W)
        {
            if (M[h][w])
                continue;

            M[h][w] = true;
            ll wn = 0, bn = 0;
            queue<pll> q;
            q.push(pll(h, w));
            while (!q.empty())
            {
                pll t = q.front();
                q.pop();
                if (S[t.first][t.second] == '.')
                    wn++;
                else
                    bn++;

                REP(i, 4)
                {
                    int nh = t.first + x[i], nw = t.second + y[i];
                    if (nh < 0 || nh >= H || nw < 0 || nw >= W)
                        continue;
                    if (M[nh][nw])
                        continue;
                    if (S[t.first][t.second] == S[nh][nw])
                        continue;
                    q.push(pll(nh, nw));
                    M[nh][nw] = true;
                }
            }

            sum += wn * bn;
        }
    }
    cout << sum << endl;
    return 0;
}