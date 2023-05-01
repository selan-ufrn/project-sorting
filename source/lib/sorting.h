/*!
 * Several types of sorting algorithms that work on a data range.
 * @author Somebody
 * @date May 1st, 2023.
 * @file sorting.h
 */

#ifndef SORTING_H
#define SORTING_H

#include <sstream>
using std::ostringstream;
#include <iterator>
using std::next;
using std::ostream_iterator;
#include <functional>
using std::function;
using std::less;
#include <vector>
using std::vector;
#include <array>
using std::array;
#include <algorithm>
using std::copy;
using std::for_each;
using std::max_element;
#include <cmath>
using std::pow;
#include <string>
using std::string;
using std::to_string;

namespace sa { // sa = sorting algorithms
/// Prints out the range to a string and returns it to the client.
template <typename FwrdIt> std::string to_string(FwrdIt first, FwrdIt last) {
  std::ostringstream oss;
  oss << "[ ";
  while (first != last) {
    oss << *first++ << " ";
  }
  oss << "]";
  return oss.str();
}

//{{{ RADIX SORT
/*!
 * This function implements the Radix Sorting Algorithm based on the **less
 * significant digit** (LSD).
 *
 * @note There is no need for a comparison function to be passed as argument.
 *
 * @param first Pointer/iterator to the beginning of the range we wish to sort.
 * @param last Pointer/iterator to the location just past the last valid value
 * of the range we wish to sort.
 * @tparam FwrdIt A forward iterator to the range we need to sort.
 * @tparam Comparator A Comparator type function tha returns true if first
 * argument is less than the second argument.
 */
template <typename DataType, typename Comparator>
void radix(DataType *first, DataType *last, Comparator /*unused*/) {
  // [1] Determine how many digits the largest integer in the incoming range
  // has.
  size_t n_digits{0};
  // [2] Traverse the entire range 'n_digits' times, from the less significant
  // to the most significant (i.e. from left to right).
  for (size_t i{0}; i < n_digits; ++i) {
    // [a]=== Buckets creation.
    // We create the 10 buckets each iteration so that they start empty every
    // time through.

    // [b]=== Range traversal and values distriburion into buckets.
    // For each value of the range we need to examine i-th less significant
    // digit so that we can assign the value to the corresponding bucket.

    // ==============================================================
    // What the for_each above does is:
    // --------------------------------------------------------------
    // Assuming value=123 and that the largest number in the collection has 4
    // digits. 1st pass: 123/1 = 123; 123 % 10 = 3. buckets[3].push_back(123).
    // 2nd pass: 123/10 = 12; 12 % 10 = 2.  buckets[2].push_back(123).
    // 3rd pass: 123/100 = 1; 1 % 10 = 1.   buckets[1].push_back(123).
    // 4th pass: 123/1000 = 0; 0 % 10 = 0.  buckets[0].push_back(123).

    // [c]=== Reverse movement from buckets back into range.
    // At the end of the traversal, we copy all values from the buckets
    // back to the original range. They naturally come in ascending order
    // considering the current i-th digit.
    // Points to the location in memory where the values should be copied to.
    // For each bucket...
    // ... copy the bucket's stored values back into the range, and
    // ...at the same time, update the destination pointer for the next
    // iteration.
  } // for to traverse the digits.
}
//}}} RADIX SORT

//{{{ INSERTION SORT
/// Implementation of the Insertion Sort algorithm.
template <typename DataType, typename Compare>
void insertion(DataType *first, DataType *last, Compare cmp) {
  // TODO
}
//}}} INSERTION SORT

//{{{ SELECTION SORT
template <typename DataType, typename Compare>
void selection(DataType *first, DataType *last, Compare cmp) {
  // TODO
}
//}}} SELECTION SORT

//{{{ BUBBLE SORT
template <typename DataType, typename Compare>
void bubble(DataType *first, DataType *last, Compare cmp) {
  // TODO
}
//}}} BUBBLE SORT

//{{{ SHELL SORT
template <typename DataType, typename Compare>
void shell(DataType *first, DataType *last, Compare cmp) {
  // TODO
}
//}}} SHELL SORT

//{{{ MERGE SORT
template <typename DataType, typename Compare>
void merge(DataType *first, DataType *last, Compare cmp) {
  // TODO
}
//}}} MERGE SORT

//{{{ QUICK SORT
/// Quick sort implementation.
template <typename DataType, typename Compare>
void quick(DataType *first, DataType *last, Compare comp) {
  // TODO
}
//}}} QUICK SORT
};     // namespace sa
#endif // SORTING_H
