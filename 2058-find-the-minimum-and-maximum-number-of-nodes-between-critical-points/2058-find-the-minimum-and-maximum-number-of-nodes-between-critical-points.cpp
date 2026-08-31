class Solution {
public:
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        int idx = 1;
        int firstidx = -1;
        int lastidx = -1;
        ListNode* a = head;
        ListNode* b = head->next;
        ListNode* c = head->next->next;
        if(head->next->next==NULL) return{-1,-1};
        int mind = INT_MAX;
        int f = -1;
        int s = -1;
        while(c){
            if(b->val > a->val && b->val>c->val || b->val < a->val && b->val<c->val ){
                if(firstidx==-1) firstidx = idx;
                else lastidx = idx;
                f = s;
                s = idx;
                if(f!=-1){
                    int d = s-f;
                    mind = min(mind,d);
                }
            }
            a=a->next;
            b = b->next;
            c = c->next;
            idx++;
        }
        if(lastidx==-1) return{-1,-1};
        int maxd = lastidx - firstidx;
        
        return {mind,maxd};
    }
};