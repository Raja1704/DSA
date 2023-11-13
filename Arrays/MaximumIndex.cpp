/*
Problem Statement:

Given an array A[] of N positive integers. 
The task is to find the maximum of j - i subjected to the constraint of
 A[i] < A[j] and i < j.

*/

#include<bits/stdc++.h>

class Solution{
    public:
        int MaximumIndex(std::vector<int> Array, int SizeOfArray){
            int MaximumIndex = -1 ;
            std::vector<int> LMIN(SizeOfArray), RMAX(SizeOfArray);

            LMIN[0] = Array[0];
            for(int i = 1 ; i < SizeOfArray ; i += 1){
                LMIN[i] = std::min(Array[i], LMIN[i-1]) ;
            }

            RMAX[SizeOfArray-1] = Array[SizeOfArray-1];
            for(int i = SizeOfArray-2 ; i >= 0 ; i -= 1){
                RMAX[i] = std::max(Array[i], RMAX[i+1]) ;
            }

            int i = 0, j = 0 ;
            while(i < SizeOfArray && j < SizeOfArray){
                if(LMIN[i] <= RMAX[j]){
                    MaximumIndex = std::max(MaximumIndex, j-i) ;
                    j += 1 ;
                }
                else{
                    i += 1 ;
                }
            }

            return MaximumIndex ;
        }

};

int main(){
    int TestCases ;
    std::cin >> TestCases;

    while(TestCases--){
        int SizeOfArray;
        std::cin >> SizeOfArray;
        std::vector<int> Array(SizeOfArray) ;

        for(int i = 0 ; i < SizeOfArray ; i += 1){
            std::cin >> Array[i] ;
        }

        Solution Object ;

        std::cout << Object.MaximumIndex(Array, SizeOfArray) << std::endl ;
    }

    return 0 ;
}