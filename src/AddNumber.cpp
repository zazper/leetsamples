
#include "myLeetCode.h"
#include <iostream>

struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}    
};

std::ostream& operator<<(std::ostream& os, const ListNode& dt)
{
    const ListNode* ln = &dt;
    os << "[";
    while (ln != nullptr) {
        os << ln->val << ' ';
        ln = ln->next;
    }
    os << '\b';
    os << "]";
    return os;
}

class AddNumber {
    ListNode* reverse(ListNode* head) {
        ListNode* curr = head;
        ListNode* prev = nullptr;
        while (curr != nullptr) {
            ListNode* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }

public:
    AddNumber() {};
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        /*
        ListNode* curr = l1;
        ListNode* prev = nullptr;
        while (curr != nullptr) {
            ListNode* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        l1 = prev;
        
        curr = l2;
        prev = nullptr;
        while (curr != nullptr) {
            ListNode* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        l2 = prev;
        */
        ListNode* a = l1;
        ListNode* b = l2;
        ListNode* aprev = nullptr;
        ListNode* bprev = nullptr;

        int overflow = 0;
        while (a != nullptr && b != nullptr) {
            int sum = a->val + b->val + overflow;
            a->val = sum % 10;
            b->val = a->val;
            overflow = sum / 10;
            aprev = a;
            bprev = b;
            a = a->next;
            b = b->next;
        }
        ListNode* sum = nullptr;
        if (a == nullptr && b == nullptr) {
            if (overflow > 0) {
                aprev->next = new ListNode(overflow, nullptr);
            }
            sum = l1;
        }
        else if (a == nullptr) {
            while (b != nullptr) {
                int sum = b->val + overflow;
                b->val = sum % 10;
                overflow = sum / 10;
                bprev = b;
                b = b->next;
            }
            if (overflow > 0) {
                bprev->next = new ListNode(overflow, nullptr);
            }
            sum = l2;
        }
        else if (b == nullptr) {
            while (a != nullptr) {
                int sum = a->val + overflow;
                a->val = sum % 10;
                overflow = sum / 10;
                aprev = a;
                a = a->next;
            }
            if (overflow > 0) {
                aprev->next = new ListNode(overflow, nullptr);
            }
            sum = l1;
        }
        //ListNode* revsum = reverse(sum);
        return sum;
        //return revsum;
    }
};

/*
Input: l1 = [2,4,3], l2 = [5,6,4]
Output: [7,0,8]
Explanation: 342 + 465 = 807.

Example 2:

Input: l1 = [0], l2 = [0]
Output: [0]

Example 3:

Input: l1 = [9,9,9,9,9,9,9], l2 = [9,9,9,9]
Output: [8,9,9,9,0,0,0,1]



Constraints:

    The number of nodes in each linked list is in the range [1, 100].
    0 <= Node.val <= 9
    It is guaranteed that the list represents a number that does not have leading zeros.
*/

int main()
{
    
    ListNode a0(0);
    ListNode b0(0);

	ListNode a1(3);
    ListNode a2(4, &a1);
    ListNode a3(2, &a2);

    ListNode b1(4);
    ListNode b2(6, &b1);
    ListNode b3(5, &b2);

    ListNode a9[7];
    ListNode b9[4];

    int na = sizeof(a9) / sizeof(a9[0]);
    int nb = sizeof(b9) / sizeof(b9[0]);
    
    for (int i = 0; i < na-1; i++) {
        a9[i].val = 9;
        a9[i].next = &a9[i + 1];
    }
    a9[na - 1].val = 9;
    a9[na - 1].next = nullptr;

    for (int i = 0; i < nb - 1; i++) {
        b9[i].val = 9;
        b9[i].next = &b9[i + 1];
    }
    b9[nb - 1].val = 9;
    b9[nb - 1].next = nullptr;

/*
    ListNode a1(1);
    ListNode a2(2, &a1);
    ListNode a3(3, &a2);

    ListNode b1(0);
    ListNode b2(0, &b1);
    ListNode b3(0, &b2);
*/

    AddNumber a;

    // Case 1
    std::cout << a3 << std::endl;
    std::cout << b3 << std::endl;

    auto c = a.addTwoNumbers(&a3, &b3);

    std::cout << *c << std::endl;

    // Case 2
    std::cout << a0 << std::endl;
    std::cout << b0 << std::endl;

    c = a.addTwoNumbers(&a0, &b0);

    std::cout << *c << std::endl;

    ListNode* a9head = &a9[0];
    // Case 3
    std::cout << a9[0] << std::endl;
    std::cout << b9[0] << std::endl;

    c = a.addTwoNumbers(a9, b9);

    std::cout << *c << std::endl;

	return 0;
}