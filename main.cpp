
#include <iostream>
#include "nCr.h"
#include "kth.h"
#include <time.h>

using namespace std;

void kth2(int m, int n, unsigned long long k) {

    //
    //   You will replace the following routine 
    //   with your solution ..........
    //

    unsigned long long i, ones, accum;
    i = 0;
    while (k > 0) {
        accum = i;
        ones = 0;
        while (accum > 0) {
            ones += accum % 2;
            accum /= 2;
        }
        if (ones == n) k--;
        i++;
    }
    i--;
    k = (unsigned long long)1 << (m + n - 1);
    while (k > 0) {
        if ((k & i) > 0) cout << '1';
        else cout << '0';
        k /= 2;
    }
} // kth

void testchoose(int n) {
    int i, j;
    for (i = 0; i < n; i++) {
        for (j = 0; j <= i; j++) {
            cout << nCr(i, j) << ' ';
        }
        cout << endl;
    }
} // testchoose



int main() {
    int m, n;
    int r1 = 0;
    int r2 = 0;
    int r3 = 0;
    unsigned long long k;
    unsigned long long space;


    // testchoose(10);


    // Input routine: m, n, k
    cout << "How many 0s? ";
    cin >> m;
    cout << "How many 1s? ";
    cin >> n;

    space = nCr(m + n, n);

    cout << "Which binary string (1-" << space << ")? ";
    cin >> k;

    

 
    cout << endl;
    if ((k < 1) || (k > space)) { cout << "Error: " << k << " is not in the range [1," << space << "]" << endl << endl; return 1; }
    //cout << "Binary string #" << k << " is: "; kth2(m, n, k); cout << endl;
    cout << "Binary string #" << k << " is: "; kth(m, n, k); cout << endl;

    srand(time(0));
    
    //for (int i = 0; i < 10; i++) {
    //    
    //    space = nCr(m + n, n);
    //    r1 = rand() % space + 1;
    //    r2 = rand() % 15 + 1;
    //    r3 = rand() % 15 + 1;
    //    cout << "ones: " << r2 << " zeros: " << r3 << " k: " << r1 << endl;

    //    cout << "Binary string #" << k << " is: "; kth2(r3, r2, r1); cout << endl;

    //    cout << "Binary string #" << k << " is: "; kth(r3, r2, r1); cout << endl;

    //}
    return 0;
}
