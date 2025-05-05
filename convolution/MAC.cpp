/*
things to implement:

include x list and h list
figure out how to do the 3 steps:
1. flip h -- DONE
2. position
3. MAC (multiply and accumulate)
4. shift

*/

#include <iostream> // for cout and cin
#include <vector>
using namespace std;

int main() {

    // vector<float> x = {1, 2, 3};
    // vector<float> h = {3, 2, 1};
    // vector<float> h_flip;

    //code below flips h
    // cout << h.size() << " index" << endl << h[2] << " element at index 2" << endl;

    // for (int i = 1; i <= 3; i++){
    //     h_flip.push_back(h[h.size() - i]); // flips h



    // }

//     for (float num : h) {
//         cout << num << " ";
//     }
//         cout << endl;
//     for (float num : h_flip) {
//         cout << num << " ";
//     }

// linear convolution

// for (int i = 0; i < (h.size()-1); i++)
// {
// // multiply

// // accumulate
// // collect/sum
// }

// AI solution

    vector<int> x = {1, 2, 1};
    vector<int> h = {3, 2, 1}; // same as h'
    vector<int> y(x.size() + h.size() - 1, 0); // output size is 5

    for (int i = 0; i < y.size(); i++) {
        for (int j = 0; j < h.size(); j++) {
            if (i - j >= 0 && i - j < x.size()) { //checks if index i - j is a valid index into vector x
                y[i] += x[i - j] * h[j]; // At output position i, add the product of each filter value h[j] and the aligned input value x[i - j], if it's within bounds.
            }
        }
    }

    for (int num : y){
        cout << num << " ";
    }

// cross correlation

}

