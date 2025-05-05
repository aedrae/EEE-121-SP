#include <iostream>
#include <utility>
#include <cstdlib>
#include <ctime>
#include <vector>
using namespace std;

float mean1d(vector<float>&vec){
    float sum = 0;
    for (float num : vec){
        sum += num;
    }

    float mean1d = (sum) / vec.size();
    return mean1d;
}

float median1d(vector<float>&vec){ //must be used with sorted list
    int length = vec.size();
    if (length % 2 == 0){
        return ((vec[vec.size()/2]+vec[(vec.size()/2)-1])/2);

    }
    else{
        int middle = (vec.size()/2);
        return vec[middle];
        
    }
}

vector<float> mode1d(vector<float>& vec) //this function returns a vector containing the modes

{
    vector<float> modes;
    int maxCount = 0;

    for (int i = 0; i < vec.size(); i++) {
        int count = 0;

        for (int j = 0; j < vec.size(); j++) {
            if (vec[j] == vec[i]) {
                count++;
            }
        }

        if (count > maxCount) {
            maxCount = count;
            modes.clear();         // found a new max, reset modes
            modes.push_back(vec[i]);
        } else if (count == maxCount) {
            bool alreadyAdded = false;
            for (float m : modes) {
                if (m == vec[i]) {
                    alreadyAdded = true;
                    break;
                }
            }
            if (!alreadyAdded) {
                modes.push_back(vec[i]);
            }
        }
    }

    if (maxCount == 1) {
        return {}; // no mode
    }

    return modes;
}

int main() {
    vector<float> nums = {1, 2, 2, 3, 3, 4};
    vector<float> result = mode1d(nums);

    if (result.empty()) {
        cout << "no mode" << endl;
    } else {
        cout << "mode(s): ";
        for (float val : result) {
            cout << val << " ";
        }
        cout << endl;
    }

    return 0;
}


//  1, 2, 3, 4, 5, 6, 7, 8, 9
//  0, 1, 2, 3, 4, 5, 6, 7, 8


