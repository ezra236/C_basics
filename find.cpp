#include <iostream>
#include <vector>
using namespace std;

int findMissingNumber(const vector<int>& arr, int n) {
    // Calculate the expected sum of numbers from 1 to n.
    int expectedSum = n * (n + 1) / 2;
    
    // Calculate the sum of the elements in the array.
    int actualSum = 0;
    for (int num : arr) {
        actualSum += num;
    }
    
    // The difference is the missing number.
    return expectedSum - actualSum;
}

int main() {
  
    int n = 5;
    vector<int> arr = {1, 2, 4, 5};
    
    int missing = findMissingNumber(arr, n);
    cout << "The missing number is: " << missing << endl;
    
    return 0;
}
