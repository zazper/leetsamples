// myLeetCode.cpp : Defines the entry point for the application.
//

#include "leetSamples.h"
#include <vector>
using namespace std;

/*
Given two sorted arrays nums1 and nums2 of size m and n respectively, return the median of the two sorted arrays.

The overall run time complexity should be O(log (m+n)).

Example 1:

Input: nums1 = [1,3], nums2 = [2]
Output: 2.00000
Explanation: merged array = [1,2,3] and median is 2.

Example 2:

Input: nums1 = [1,2], nums2 = [3,4]
Output: 2.50000
Explanation: merged array = [1,2,3,4] and median is (2 + 3) / 2 = 2.5.



Constraints:

    nums1.length == m
    nums2.length == n
    0 <= m <= 1000
    0 <= n <= 1000
    1 <= m + n <= 2000
    -106 <= nums1[i], nums2[i] <= 10

*/

class MedianTwoSortedArrays {
public:

    /*
    * I assume that by median we are talking mid point for odd or average of midpoints if even
      if sorted, then we know the median for each sorted array
      If have median for m, it is position (m+1)/2 for odd, average m/2 and m/2+1 for even
      If I need to insert 1 element into sorted array, it will take O(log m)
      if I iterate, it will take max O(logm+n) after n inserts that is n * log (m+n)
      If I llookup median of array m in array n, that is log n operation
      if the element is before or after array, then I just count position before or after and get new medida
      Otherwsie, median exists in new sorted array, so I need to splice

      Take smaller array
      low=0, high = m
      calc partition as m/2
      total points is n+m
      - if n+m even, want to have (n+m)/2 on each side of partion
      - if n+m odd, want to have (n+m)/2 on left parition, (n+m)/2 +1 on right

      l is left of paruition, r is right of partion between points
      compare if l1 < r2 and l2 < r1. If so we are done
    */
    double findMedianSortedArrays(std::vector<int>& nums1, std::vector<int>& nums2) {
        unsigned m = (unsigned)nums1.size();
        unsigned n = (unsigned)nums2.size();

        if (m > n)
            return findMedianSortedArrays(nums2, nums1);

        if (m == 0)
            if (n == 0)
                return 0;
            else {
                if (n % 2 == 1) { // odd so return mid
                    return nums2[n / 2];
                }
                else { // even so return return average
                    auto left = nums2[n / 2 - 1];
                    auto right = nums2[n / 2];
                    double avg = 0.5 * (left + right);
                    return avg;
                }
            }

        // if m even n even
        //  p2 = (n+m)/2 - m/2 = n/2 (actual)
        // if m even n odd
        //  p  = (n+m)/2 -> one more element on right in n
        //  p2 = (n+m)/2 - m/2 = n/2 elements on left (this is same as (n-1)/2 since n odd)
        // if m odd n even
        //  p  = (n+m)/2 -> one more element on right in m since m odd
        //  p2 = (n+m)/2 - m/2 = n/2 = n/2 + m/2 - m/2 = n/2 elements on left (this is same as subtracting (m-1)/2 since m odd)
        // if m odd n odd
        //  p  = (n+m)/2 -> total is even, where are two elements? on extra on left, one extra on right
        //  p1 = m/2 (one extra on right in m)
        //  p2 = (n+m)/2 - m/2 = (n-1+m-1+2)/2 - m-1/2 = (n-1+2)/2 = (n+1)/2 elements on left. Partition is a (n+1)/2
        //  have (m/2+1) (n/2+1) on each side

        // partitions
        auto t = n + m;
        auto p1 = (int)m / 2;
        auto p2 = (int)(t / 2);
        p2 -= p1;

        auto mid1 = p1;
        auto mid2 = p2;
        int shift = 0;

        auto l1 = p1 - 1;
        auto r1 = p1;
        auto l2 = p2 - 1;
        auto r2 = p2;

        int vl1, vr1, vl2, vr2;

        unsigned low = 0;
        auto high = m;

        while (low <= high) {

            //assign lefts and rights
            vl1 = (l1 < 0 ? INT_MIN : nums1[l1]);
            vr1 = (r1 == m ? INT_MAX : nums1[r1]);
            vl2 = (l2 < 0 ? INT_MIN : nums2[l2]);
            vr2 = (r2 == n ? INT_MAX : nums2[r2]);

            // check if we have solution
            if (vl1 <= vr2 && vl2 <= vr1) {
                if (t % 2 == 1) { // odd so return mid
                    return std::min(vr1, vr2);
                }
                else { // even so return return average
                    auto left = std::max(vl1, vl2);
                    auto right = std::min(vr1, vr2);
                    double avg = 0.5 * (left + right);
                    return avg;
                }
            }

            if (vl1 > vr2) // Look to left of mid
                high = p1;
            else // vl2 > vr1, Look to the right of mid
                low = p1 + 1;

            p1 = (high + low) / 2;
            shift = mid1 - p1;
            p2 = mid2 + shift;

            l1 = p1 - 1;
            r1 = p1;
            l2 = p2 - 1;
            r2 = p2;
        }
    }
};

int main()
{
    MedianTwoSortedArrays mtsa;

    std::vector<int> left{ 1,3 };
    std::vector<int> right{ 2 };
    double median = mtsa.findMedianSortedArrays(left, right);
    cout << "median:" << median << endl;

    left = { 1,2 };
    right = { 3,4 };
    median = mtsa.findMedianSortedArrays(left, right);
    cout << "median:" << median << endl;

    left =  { 1,2,5,8 };
    right = { 3,4,5,8,9 };
    median = mtsa.findMedianSortedArrays(left, right);
	cout << "median:" << median << endl;

    left = { 1,2,3,8,9 };
    right = { 5,6,7 };
    median = mtsa.findMedianSortedArrays(left, right);
    cout << "median:" << median << endl;


    left = { 1,2,2,3 };
    right = { 5,6,7 };
    median = mtsa.findMedianSortedArrays(left, right);
    cout << "median:" << median << endl;

    left = { };
    right = { 5,6,7 };
    median = mtsa.findMedianSortedArrays(left, right);
    cout << "median:" << median << endl;

    left = { 1,2,2,3 };
    right = { };
    median = mtsa.findMedianSortedArrays(left, right);
    cout << "median:" << median << endl;

    left = { 1, 2, 3, 4, 5 };
    right = { 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17 };
    median = mtsa.findMedianSortedArrays(left, right);
    cout << "median:" << median << endl;

	return 0;
}
