
#include <iostream>
#include "nCr.h"
#include "kth.h"
#include <math.h> 
using namespace std;

void kth(int m, int n, unsigned long long k) {
    //NOTE: when i say n in/of pascals triangle, i do not mean the variable "n" aka #of ones

    int start = 1;                                     //this is the starting lowerbound. Always start at 1      
    int endN = m + n - 1;                              //this is the ending series number in pascals triangle where row = # of 1's so if i have 4 1's  
    int midN = 0;                                      //initialization used for mid (used for binary search purposes)
    int seq = n;                                       //this is a copy of the number of ones we have so we can change it later.
    if (k == 1) {                                      
        cout << string(m, '0') << string(n, '1');      //case if k=1. if k=1, we already know that all zeros will be on left and all ones on right     
        return;
    }
    while (k > 1) {                                    //while loop for binary search to find upper & lower bounds.
        midN = start + (endN - start) / 2;             //initialization of mid based on endN and start (the n in pascals triangle) so we can start in the middle n
        if (nCr(midN + seq - 1, seq) < k) {            //first check. the nCr we run can tell us what lower bound the leading 1
            start = midN + 1;                          //if its true we know that midN is on the lower bound, but since we want to end up with upper we add one
        }
        else if (nCr(midN + seq - 1, seq) >= k) {      //this is checking the upperbound (if its not the lowerbound) and repeats for endN
            endN = midN - 1;
        }
        
        //most important part--------------------------------------
        if (((nCr(midN + seq, seq) >= k) && (nCr(midN + seq - 1, seq) < k))) { //first thing check if k is inbetween bounds. so nCr(midN + seq, seq) >= k > nCr(midN + seq - 1, seq)
            seq--;                                                             //now that we know where k is, we can decrese the number 
                                                                               //of ones we have since we can cout a one                                      
            start = 1;                                                         //reset the lowerbound since changed in bin search
            endN = midN + seq - 1;                                             //reset the upperbound since changed in bin search
            cout << string(abs(midN - m), '0') << '1';                         //now, we can release the number of zeros. we know this since
                                                                               //the # of zeros on the left side decreases every n in pascals triangle for the (# of ones + 1) row
                                                                               //then, we already know that after all those zeros, a one comes after.
            if ((n - 1) == 0) {                                                //since we just release a 1, check if it was the last one
                cout << string((m- abs(midN - m)), '0');                       //if it was, release all the zeros we have left
                k = 0;                                                         //to terminate the while loop
            }
            else {
                kth((m - abs(midN - m)), seq, (k - nCr(midN + seq, seq + 1)));  //we can pass through our new values since our upper and and lower bounds focused on 1 of the pascals
            }

            return;
        }
    }
    cout << endl;
}

