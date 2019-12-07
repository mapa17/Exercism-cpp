#include "hamming.h"

using namespace std;

namespace hamming {
    int compute(string A, string B){
        int lA, lB;
        lA = A.length();
        lB = B.length();

        if(lA != lB){
            throw std::domain_error("Unequal length!");
        }

        int nErrors = 0;
        for(int i=0; i<lA; i++){
            if(A[i]!=B[i])
                nErrors++;
        }
        return nErrors;
    } 
}  // namespace hamming
