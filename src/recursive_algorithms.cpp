#include "project/recursive_algorithms.h"

#include <stdexcept>
#include <utility>
#include <vector>

// TODO: Implement factorial recursively.
// Base case: n == 0 or n == 1.
// Recursive case: n * factorial(n - 1).
int factorial(int n) {
    if (n == 0 || n == 1) { return 1; } //early return on base case
    if (n > 0) { //pratically invoked only on 2+, else if negative
        return n * factorial(n-1); 
    } else { throw std::logic_error("negative factorial"); }
}

// TODO: Implement an iterative factorial comparison.
int factorialIterative(int n) {
    if (n >= 0) {
        int product = 1;
        for (int i = 2; i <= n; i++) { //0! and 1! still equal 1, changes start from 2
            product *= i;
        } return product;
    } else { throw std::logic_error("negative factorial"); }
}

// TODO: Implement fibonacci recursively.
// Base case: fib(0) = 0, fib(1) = 1.
// Recursive case: fib(n) = fib(n - 1) + fib(n - 2).
int fibonacci(int n) {
    switch (n) {
        case 0: //base cases
            return 0; break;
        case 1:
            return 1; break;
        case 2:
            return 1; break;
        default:
            if (n > 0) { // equivalent to f(n-2) + f(n-1) [f(n-2) + f(n-3)], 
                return 2 * fibonacci(n - 2) + fibonacci(n - 3); // bigger hops means slower recursion growth, still exponential
            } else { throw std::logic_error("negative fibonacci index"); } //persistent memory required for O(n) recursion
    }
}

// TODO: Implement iterative fibonacci comparison.
int fibonacciIterative(int n) {
    switch (n) {
        case 0: //base cases
            return 0; break;
        case 1:
            return 1; break;
        default:
            if (n > 0) {
                int pprev = 0;
                int prev = 1;
                int next = 1;
                for (int i = 2; i < n; i++) { //starts from 2
                    pprev = prev;
                    prev = next;
                    next = prev + pprev;
                } return next;
            } else { throw std::logic_error("negative fibonacci index"); }
    }
}

// TODO: Implement recursive binary search on a sorted array.
// Base case: target not found or left > right.
// Recursive case: compare middle element and recurse on the appropriate half.
int binarySearch(const std::vector<int>& array, int target, int low, int high) { //additional info needed to preserve index through recursions
    if (array.size() > 0) {
        if (high == -1) {high = static_cast<int>(array.size() - 1);} //initialize again due to default param restrictions (note: int may overflow)
        if (low == high) {
            return (target == array[low]) ? low : -1; //when only 1 value to check
        } else {
            int middle = low + (high - low)/2; //automatically floored due to int
            if (array[middle] > array[middle] + 1) {throw(std::logic_error("not sorted as expected"));}
            if (target > array[middle]) { //high or low
                return binarySearch(array, target, middle + 1, high);
            } else { return binarySearch(array, target, low, middle); }
        }
    } else { return -1; } //null vector error
}

// TODO: Implement iterative binary search comparison.
int binarySearchIterative(const std::vector<int>& array, int target) {
    if (array.size() > 0) {
        std::size_t low = 0; std::size_t high = array.size() - 1; //range bounds
        while (low != high) { //if range is not 1 element
            std::size_t middle = (low + high)/2;
            if (array[middle] > array[middle] + 1) {throw(std::logic_error("not sorted as expected"));}
            if (target > array[middle]) { //high or low
                low = middle + 1;
            } else { high = middle; }
        }
        return (target == array[low]) ? low : -1; //when range is 1 element
    } else { return -1; }
}

// TODO: Implement recursive array sum.
// Base case: empty array.
// Recursive case: first element + arraySum(rest-of-array).
int arraySum(const std::vector<int>& array) {
    if (array.empty()) {
        return 0;
    } else { return array[0] + arraySum(std::vector<int>(array.begin()+1, array.end())); }
}

// TODO: Implement iterative array sum comparison.
int arraySumIterative(const std::vector<int>& array) {
    int sum = 0;
    for (int num : array) {
        sum += num;
    } return sum;
}

// TODO: Implement recursive in-place reversal.
// Base case: size <= 1.
// Recursive case: swap first and last elements, then recurse on the remaining middle.
void reverseArray(std::vector<int>& array, std::size_t i) { // iterator added due to no knowledge in keeping reference subvector
    if (i < (array.size() / 2)) {
        int saved = array.at(i);
        array.at(i) = array.at((array.size() - 1) - i);
        array.at((array.size() - 1) - i) = saved;
        reverseArray(array, ++i);
    }
}

// TODO: Implement iterative reverse comparison.
void reverseArrayIterative(std::vector<int>& array) {
    int save = 0;
    for (std::size_t i = 0; i < (array.size()/2); i++) {
        save = array.at(i);
        array.at(i) = array.at((array.size() - 1) - i);
        array.at((array.size() - 1) - i) = save;
    }
}
