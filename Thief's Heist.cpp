#include <iostream>
#include <iomanip>
#include <cmath>
#include <algorithm>

using namespace std;

long long items[10000001];
long long price[10000001];

int main(){

    long long n;
    cin >> n;

    for (int i = 1; i <= n; i++) cin >> items[i];

    if(n>=1)price[1] = items[1]; /// i=1
    if (n>=2) price[2] = max(price[2 - 1], items[2]); /// i=2
    if(n>=3) price[3] = max(price[3 - 2], max(price[3 - 1], items[3])); ///i=3
    if (n > 3) {
        for (int i = 4; i <= n; i++) price[i] = max(price[i - 3] + items[i], max(price[i - 2], price[i - 1]));
    }

    if (n == 1) cout << 0;
    else cout << price[n];

    return 0;
}