#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int a[100023],b[100023],c[100023];
bool cnta[10000023], cntb[10000023], cntc[10000023];
int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int n1,n2,n3;
    cin >> n1 >> n2 >> n3;

    for(int i=0;i<n1;i++)
        cin >> a[i];

    for(int i=0;i<n2;i++)
        cin >> b[i];

    for(int i=0;i<n3;i++)
        cin >> c[i];

    int sum = 0;
    for(int i=n1-1;i>=0;i--){
        sum += a[i];
        cnta[sum] = true;
    }

    sum = 0;
    for(int i=n2-1;i>=0;i--){
        sum += b[i];
        cntb[sum] = true;
    }

    sum = 0;
    for(int i=n3-1;i>=0;i--){
        sum += c[i];
        cntc[sum] = true;
    }
    cnta[0] = cntb[0] = cntc[0] = true;
    for(int i=10000022; i>=0; i--)
        if(cnta[i] and cntb[i] and cntc[i]){
        cout << i << endl;
        break;
    }

    return 0;
}
