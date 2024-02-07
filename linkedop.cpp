ListNode* removeMiddleNode(ListNode* head) {
    if (head == nullptr || head->next == nullptr) {
        return nullptr;
    }

    ListNode* slow = head;
    ListNode* fast = head;
    ListNode* prev = nullptr;

    while (fast != nullptr && fast->next != nullptr) {
        prev = slow;
        slow = slow->next;
        fast = fast->next->next;
    }

    prev->next = slow->next;
    delete slow;
    return head;
}
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

    ListNode* slow = head;
    ListNode* fast = head;

    while (fast->next != nullptr && fast->next->next != nullptr) {
        slow = slow->next;
        fast = fast->next->next;
    }

    ListNode* secondHalf = reverseList(slow->next);
    slow->next = nullptr;

    ListNode* first = head;
    while (secondHalf != nullptr) {
        ListNode* temp = first->next;
        first->next = secondHalf;
        secondHalf = secondHalf->next;
        first->next->next = temp;
        first = temp;
    }
}
bool isPalindrome(ListNode* head) {
    if (head == nullptr || head->next == nullptr) {
        return true;
    }

    ListNode* slow = head;
    ListNode* fast = head;
    ListNode* prev = nullptr;

    while (fast != nullptr && fast->next != nullptr) {
        prev = slow;
        slow = slow->next;
        fast = fast->next->next;
    }

    ListNode* secondHalf = slow;
    if (fast != nullptr) { // If the list has odd nodes, move to next
        secondHalf = slow->next;
    }

    prev->next = nullptr;
    ListNode* secondHalfReversed = reverseList(secondHalf);

    while (head != nullptr && secondHalfReversed != nullptr) {
        if (head->val != secondHalfReversed->val) {
            return false;
        }
        head = head->next;
        secondHalfReversed = secondHalfReversed->next;
    }

    return true;
}


