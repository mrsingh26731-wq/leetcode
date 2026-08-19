class Solution {
public:
    bool isPalindrome(ListNode* head) {

        stack<int> st;

        ListNode* temp = head;

        // Push all elements into stack
        while (temp != nullptr) {
            st.push(temp->val);
            temp = temp->next;
        }

        // Compare
        temp = head;

        while (temp != nullptr) {

            if (temp->val != st.top()) {
                return false;
            }

            st.pop();
            temp = temp->next;
        }

        return true;
    }
};