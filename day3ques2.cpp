#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

ListNode* reverseList(ListNode* head) {
    ListNode* prev = nullptr;
    ListNode* current = head;

    while (current != nullptr) {
        ListNode* nextNode = current->next; 
        current->next = prev;   
        prev = current;     
        current = nextNode;       
    }

    return prev; 
}

void printList(ListNode* head) {
    while (head != nullptr) {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}
ListNode* createList(int n) {
    if (n == 0) return nullptr;
    int val;
    cout << "Enter the value of node 1: ";
    cin >> val;
    ListNode* head = new ListNode(val);
    ListNode* current = head;
    for (int i = 2; i <= n; ++i) {
        cout << "Enter the value of node " << i << ": ";
        cin >> val;
        current->next = new ListNode(val);
        current = current->next;
    }
    return head;
}

int main() {
    int n;
    cout << "Enter the number of nodes in the linked list: ";
    cin >> n;

    ListNode* head = createList(n);

    cout << "Original Linked List: ";
    printList(head);

    head = reverseList(head);

    cout << "Reversed Linked List: ";
    printList(head);

    return 0;
}
