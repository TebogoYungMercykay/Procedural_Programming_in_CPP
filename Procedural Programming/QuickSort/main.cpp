/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/
#include <iostream>
#include <cstdlib>
using namespace std;

// * Init Variables
const int S = 5;
int globalArray[S];

// * Function Declarations/Prototypes
void Swap_Method(int a, int b);
int Create_Partitions(char direction, int lo, int hi);
void my_own_Quicksort_Version(char direction, int lo, int hi);

// * Printing Function
void print_for_testing(){
    for (int i = 0; i < S; i++){
        cout << globalArray[i];
        if(i < (S - 1)){
            cout << ", ";
        }
        else{
            cout << endl;
        }
    }
}

// * Main Function
int main(){
    for (int i = S, j = 0; i > 0; i--, j++){
        globalArray[j] = i;
    }
    print_for_testing();
    // Sort Ascending Order
    my_own_Quicksort_Version('<', 0, S - 1);
    print_for_testing();
    // Sort Descending Order
    my_own_Quicksort_Version('>', 0, S - 1);
    print_for_testing();
    return 0;
}

// * Function Implementation
void my_own_Quicksort_Version(char direction, int lo, int hi){
    if(direction == '<'){
        if(lo < hi){
            int pivot = Create_Partitions(direction, lo, hi);
            my_own_Quicksort_Version(direction, lo, pivot - 1);
            my_own_Quicksort_Version(direction, pivot + 1, hi);
        }
    }
    else if(direction == '>'){
        if(lo < hi){
            int pivot = Create_Partitions(direction, lo, hi);
            my_own_Quicksort_Version(direction, lo, pivot - 1);
            my_own_Quicksort_Version(direction, pivot + 1, hi);
        }
    }
    else{
        cout << " error ";
        exit(2);
    }
}

int Create_Partitions(char direction, int lo, int hi){
    int pivot = lo + rand() % (hi - lo + 1);
    if(direction == '<'){
        Swap_Method(pivot, hi);
        for (int i = lo; i < hi; i++){
            if (globalArray[i] <= globalArray[hi]){
                Swap_Method(i, lo);
                lo++;
            }
        }
    }
    else if(direction == '>'){
        Swap_Method(pivot, hi);
        for (int i = lo; i < hi; i++){
            if (globalArray[i] >= globalArray[hi]){
                Swap_Method(i, lo);
                lo++;
            }
        }
    }
    Swap_Method(lo, hi);
    return lo;
}

void Swap_Method(int a, int b){
    int tmp = globalArray[a];
    globalArray[a] = globalArray[b];
    globalArray[b] = tmp;
}