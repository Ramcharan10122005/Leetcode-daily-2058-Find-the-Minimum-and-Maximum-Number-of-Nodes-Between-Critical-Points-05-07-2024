int* nodesBetweenCriticalPoints(struct ListNode* head, int* r) {
    *r = 2;
    int* ans = (int*)malloc(2 * sizeof(int));    
    struct ListNode* prev = head;
    struct ListNode* curr = head->next;
    if (!curr || !curr->next) {
        ans[0] = -1;
        ans[1] = -1;
        return ans;
    }
    
    struct ListNode* succ = curr->next;
    int cf = 0, cl = 0, prevcrit = -1, currcrit = 0;
    int count = 1;
    int min = INT_MAX;
    int critcount = 0;
    
    while (succ != NULL) {
        if ((curr->val > prev->val && curr->val > succ->val) || (curr->val < prev->val && curr->val < succ->val)) {
            if (cf == 0) {
                cf = count;
            }
            cl = count;
            critcount++;
            
            if (prevcrit != -1) {
                min = fmin(min, count - prevcrit);
            }
            prevcrit = count;
        }
        prev = curr;
        curr = succ;
        succ = succ->next;
        count++;
    }
    
    if (critcount < 2) {
        ans[0] = -1;
        ans[1] = -1;
    } else {
        ans[0] = min;
        ans[1] = cl - cf;
    }
    
    return ans;
}
