#include <iostream>
using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

ListNode* reverseLinkedList(ListNode* head) {
    // Base case: if the list is empty or has only one node
    if (head == nullptr || head->next == nullptr) {
        return head;
    }

    // Reverse the rest of the list after the current node
    ListNode* reversedList = reverseLinkedList(head->next);

    // Reverse pointers
    head->next->next = head;
    head->next = nullptr;

    return reversedList;
}

void printList(ListNode* head) {
    while (head != nullptr) {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    // Creating a sample linked list: 1 -> 2 -> 3 -> 4 -> 5
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);

    cout << "Original List: ";
    printList(head);

    // Reverse the linked list
    head = reverseLinkedList(head);

    cout << "Reversed List: ";
    printList(head);

    return 0;
}

