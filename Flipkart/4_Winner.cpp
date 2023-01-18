//Using Linked List
class Node{
    public: 
    int data ;
    Node* next ;
    Node(int val){
        data = val;
        next = NULL ;
    }
};

class Solution {
public:
    int findTheWinner(int n, int k) {
        if(k==1) return n ;
        Node* head = new Node(1) ;
        Node* root = head ;
        for(int i = 2 ; i <= n ; i++){
            Node* t = new Node(i) ;
            root->next = t ;
            root = t ;
        } 
        root->next = head ;

        Node* temp = head ;
        while(temp->data != temp->next->data){
            for(int i = 0; i<k-2 ; i++){
                temp = temp->next ;
            }
            temp->next = temp->next->next;
            temp = temp->next ;
        }

        return temp->data ;
    }
};


//Optimized
class Solution {
public:

    int fun(int n , int k){
        if(n==1) return 0;
        return ((fun(n-1,k)+k)%n) ;
    }

    int findTheWinner(int n, int k) {
        if(k==1) return n ;
        return fun(n,k)+1 ;
    }
};
