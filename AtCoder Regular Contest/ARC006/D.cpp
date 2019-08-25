#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for (ll(i) = (m); (i) < (n); ++(i))
#define REP(i, n) FOR(i, n, 0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll)1e15;

string S[1005];
bool U[1005][1005];

int x[4] = {1, 0, -1, 0};
int y[4] = {0, 1, 0, -1};

ll gcd(ll a, ll b)
{
    if (a < b)
        swap(a, b);
    ll c = a % b;
    if (c == 0)
        return b;
    return gcd(b, c);
}
int main()
{
    ll H, W;
    cin >> H >> W;
    REP(i, H)
    {
        cin >> S[i];
    }
    memset(U, 0, sizeof(U));
    ll a = 0, b = 0, c = 0;
    REP(i, H)
    {
        REP(j, W)
        {
            if (U[i][j])
                continue;
            queue<pll> q;
            char f = S[i][j];
            q.push(pll(i, j));
            ll n = 0;
            while (!q.empty())
            {
                pll t = q.front();
                q.pop();
                if (U[t.first][t.second])
                    continue;
                U[t.first][t.second] = true;
                n++;
                REP(k, 4)
                {
                    ll nx = t.first + x[k];
                    ll ny = t.second + y[k];
                    if (nx < 0 || nx >= H || ny < 0 || ny >= W)
                        continue;
                    if (U[nx][ny] || S[nx][ny] != f)
                        continue;
                    q.push(pll(nx, ny));
                }
            }
            if (f == '.')
                continue;

            ll h = 0, w = 0;
            while (i + h < H && S[i][j] == S[i + h][j])
                h++;
            while (j + w < W && S[i][j] == S[i][j + w])
                w++;

            ll g = gcd(h, w);
            n /= (g * g);

            if (n == 9)
                a++;
            else if (n == 14)
                b++;
            else if (n == 3)
                c++;
        }
    }

    cout << a << " " << b << " " << c / 3 << endl;
    return 0;
}