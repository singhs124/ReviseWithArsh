class Solution {
public:
    ListNode* removeZeroSumSublists(ListNode* head) {
        
        ListNode* root =new ListNode(0);
        root->next = head;
        unordered_map<int,ListNode*> m ; 
        m[0] = root ;
        int sum = 0;
        while(head){
            sum += head->val ;
            if(m.find(sum) != m.end()){
                ListNode* left = m[sum] ;
                ListNode* temp = left ;
                int dsum = sum;
                while(left != head){
                    left = left->next ;
                    dsum += left->val;
                    if(left != head) m.erase(dsum) ;
                }
                temp->next = head->next ;
            }
            else m[sum] = head ;    
            head = head->next ;
        }
        return root->next ;
    }
};
