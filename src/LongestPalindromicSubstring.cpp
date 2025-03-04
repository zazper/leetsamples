// myLeetCode.cpp : Defines the entry point for the application.
//

#include "leetSamples.h"

/*
* 
* Given a string s, return the longest

in s.

 

Example 1:

Input: s = "babad"
Output: "bab"
Explanation: "aba" is also a valid answer.

Example 2:

Input: s = "cbbd"
Output: "bb"

 

Constraints:

    1 <= s.length <= 1000
    s consist of only digits and English letters.

*/

class LongestPalindromicSubstring {
public:

    struct palindrome {
        int _centerleft;
        int _centerright;
        int _left;
        int _right;

        palindrome() {
            _centerleft = _centerright = _left = _right = 0;
        }

        palindrome(int centerleft, int centerright, int left, int right) :
            _centerleft(centerleft),
            _centerright(centerright),
            _left(left),
            _right(right)
        {}

        int size() {
            return _right - _left;
        }

        int left() {
            return _left;
        }

        int right() {
            return _right;
        }
    };

    std::string longestPalindrome(std::string s) {
        palindrome best, current;

        int size = s.size();
        int n = size - 1;
        if (size < 2) { // If string empty or one string return that
            return s;
        }
        else if (size == 2) {
            if (s[0] == s[1])
                return s;
            else
                return s.substr(0, 1);
        }

        // Assume size > 2
        int mid = size / 2;

        int leftptr = mid - 1; // This outer loop
        int rightptr = mid + 1;  // This outer loop

        int left, right;  // This inner loop

        int centerleft;
        int centerright;

        // check middle first 
        {
            centerleft = mid;
            centerright = mid;

            while (centerleft > 0 && s[centerleft - 1] == s[centerleft]) {
                centerleft--;
            }
            left = centerleft;

            while (centerright < n && s[centerright + 1] == s[centerright]) {
                centerright++;
            }
            right = centerright;

            while (left > 0 && right < n && s[left - 1] == s[right + 1]) {
                left--;
                right++;
            }
            if ((right - left) > best.size())
                best = palindrome(centerleft, centerright, left, right);

            leftptr = centerleft - 1;
            rightptr = centerright + 1;
        }

        while (leftptr > 0 || rightptr < size) {

            if (leftptr > 0) {
                centerleft = centerright = leftptr;

                while (centerleft > 0 && s[centerleft - 1] == s[centerleft]) {
                    centerleft--;
                }
                left = centerleft;
                right = centerright;

                while (left > 0 && right < n && s[left - 1] == s[right + 1]) {
                    left--;
                    right++;
                }
                if ((right - left) > best.size())
                    best = palindrome(centerleft, centerright, left, right);

                leftptr = centerleft - 1;

            }

            if (rightptr < size) {

                centerleft = centerright = rightptr;

                while (centerright < n && s[centerright + 1] == s[centerright]) {
                    centerright++;
                }
                left = centerleft;
                right = centerright;

                while (left > 0 && right < n && s[left - 1] == s[right + 1]) {
                    left--;
                    right++;
                }
                if ((right - left) > best.size())
                    best = palindrome(centerleft, centerright, left, right);

                rightptr = centerright + 1;
            }
        }

        std::string longest = s.substr(best.left(), best.right() - best.left() + 1);
        return longest;
    }
};

int main()
{
    LongestPalindromicSubstring lps;

    std::string s("");
    std::string l = lps.longestPalindrome(s);
    std::cout << "s:" << s << std::endl;
    std::cout << "l:" << l << std::endl;

    s = "a";
    l = lps.longestPalindrome(s);
    std::cout << "s:" << s << std::endl;
    std::cout << "l:" << l << std::endl;

    s = "ab";
    l = lps.longestPalindrome(s);
    std::cout << "s:" << s << std::endl;
    std::cout << "l:" << l << std::endl;

    s = "aba";
    l = lps.longestPalindrome(s);
    std::cout << "s:" << s << std::endl;
    std::cout << "l:" << l << std::endl;

    s = "ababaaabbbb";
    l = lps.longestPalindrome(s);
    std::cout << "s:" << s << std::endl;
    std::cout << "l:" << l << std::endl;

    s = "babad";
    l = lps.longestPalindrome(s);
    std::cout << "s:" << s << std::endl;
    std::cout << "l:" << l << std::endl;

    s = "cbbd";
    l = lps.longestPalindrome(s);
    std::cout << "s:" << s << std::endl;
    std::cout << "l:" << l << std::endl;

    s = "aaaaaaaaaab";
    l = lps.longestPalindrome(s);
    std::cout << "s:" << s << std::endl;
    std::cout << "l:" << l << std::endl;

    s = "baaaaaaaaaa";
    l = lps.longestPalindrome(s);
    std::cout << "s:" << s << std::endl;
    std::cout << "l:" << l << std::endl;

    s = "aaaaaaaaaaab";
    l = lps.longestPalindrome(s);
    std::cout << "s:" << s << std::endl;
    std::cout << "l:" << l << std::endl;

    s = "baaaaaaaaaaa";
    l = lps.longestPalindrome(s);
    std::cout << "s:" << s << std::endl;
    std::cout << "l:" << l << std::endl;

    s = "adam";
    l = lps.longestPalindrome(s);
    std::cout << "s:" << s << std::endl;
    std::cout << "l:" << l << std::endl;

    s = "aaabaaaa";
    l = lps.longestPalindrome(s);
    std::cout << "s:" << s << std::endl;
    std::cout << "l:" << l << std::endl;

    return 0;
}
