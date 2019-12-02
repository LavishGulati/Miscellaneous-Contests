#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef unordered_map<int, int> umapii;
typedef unordered_map<int, bool> umapib;
typedef unordered_map<string, int> umapsi;
typedef unordered_map<string, string> umapss;
typedef map<string, int> mapsi;
typedef map<pair<int, int>, int> mappiii;
typedef map<int, int> mapii;
typedef map<int, bool> mapib;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;
typedef unordered_set<int> useti;
typedef set<int> seti;

#define uset unordered_set
#define it iterator
#define mp make_pair
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define allp(x) (x)->begin(), (x)->end()
#define f first
#define s second
#define MOD 1000000007
#define PI acos(-1)

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    ll t, n, l;
    cin >> t;
    for(ll c = 0; c < t; c++){
        cin >> l >> n;
        n++;
        ll input[n-1];
        for(ll i = 0; i < n-1; i++){
            cin >> input[i];
        }

        set<ll> helper;
        helper.insert(input[0]/__gcd(input[0], input[1]));
        for(ll i = 1; i < n-1; i++){
            helper.insert(__gcd(input[i-1], input[i]));
        }
        helper.insert(input[n-2]/__gcd(input[n-3], input[n-2]));

        map<ll, ll> m;
        int id = 0;
        for(auto i = helper.begin(); i != helper.end(); i++){
            m[*i] = id;
            id++;
        }

        string output = "";
        // for(int i = 0; i < n; i++){
        //     output[i] = '*';
        // }

        output += m[input[0]/__gcd(input[0], input[1])]+'A';
        for(ll i = 1; i < n-1; i++){
            output += m[__gcd(input[i-1], input[i])]+'A';
            // cout << output[i];
        }
        output += m[input[n-2]/__gcd(input[n-3], input[n-2])]+'A';

        // cout << endl;
        // cout << output << endl;
        cout << "Case #" << c+1 << ": " << output << endl;
    }
}
