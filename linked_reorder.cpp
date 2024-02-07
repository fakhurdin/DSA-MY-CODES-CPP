#include <iostream>
using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

ListNode* reverseList(ListNode* head) {
    ListNode* prev = nullptr;
    ListNode* curr = head;
    ListNode* next = nullptr;

    while (curr != nullptr) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }

    return prev;
}

void reorderList(ListNode* head) {
    if (head == nullptr || head->next == nullptr) {
        return;
    }

    // Step 1: Find the middle of the linked list
    ListNode* slow = head;
    ListNode* fast = head;

    while (fast->next != nullptr && fast->next->next != nullptr) {
        slow = slow->next;
        fast = fast->next->next;
    }

    // Step 2: Reverse the second half of the list
    ListNode* secondHalf = reverseList(slow->next);
    slow->next = nullptr;

    // Step 3: Merge the two halves, alternating nodes
    ListNode* first = head;
    while (secondHalf != nullptr) {
        ListNode* temp = first->next;
        first->next = secondHalf;
        secondHalf = secondHalf->next;
        first->next->next = temp;
        first = temp;
    }
}

void printList(ListNode* head) {
    while (head != nullptr) {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    int N;
    cin >> N;

    ListNode* head = nullptr;
    ListNode* tail = nullptr;

    for (int i = 0; i < N; ++i) {
        int val;
        cin >> val;

        if (head == nullptr) {
            head = new ListNode(val);
            tail = head;
        } else {
            tail->next = new ListNode(val);
            tail = tail->next;
        }
    }

    reorderList(head);
    printList(head);

    return 0;
}

