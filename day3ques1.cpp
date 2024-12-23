#include <iostream>
#include <cmath>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

ListNode* reverseList(ListNode* head) {
    ListNode* prev = nullptr;
    ListNode* curr = head;

    while (curr) {
        ListNode* next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}

long long listToNumber(ListNode* head) {
    long long num = 0;
    while (head) {
        num = num * 10 + head->val;
        head = head->next;
    }
    return num;
}

int main() {
    ListNode* l1 = new ListNode(2, new ListNode(4, new ListNode(3)));
    ListNode* l2 = new ListNode(5, new ListNode(6, new ListNode(4)));
    l1 = reverseList(l1);
    l2 = reverseList(l2);

    long long num1 = listToNumber(l1);
    long long num2 = listToNumber(l2);
    long long sum = num1 + num2;
    cout << "Sum: " << sum << endl;

    return 0;
}
