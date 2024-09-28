class MyCircularDeque {
private:
    ListNode *head;
    ListNode *tail;
    int size, maxSize;
public:
    MyCircularDeque(int k) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
        this->head= new ListNode();
        this->tail=this->head;
        this->maxSize=k;
        this->size=0;
    }
    
    bool insertFront(int value) {
        if(this->size>=this->maxSize) return false;
        this->size++;
        ListNode *temp = new ListNode(value);if(this->size==1){
            head=temp;
            tail=head;
            return true;
        }
        temp->next = this->head;
        head=temp;
        if(this->size==1) tail=head;
        return true;
    }
    
    bool insertLast(int value) {
        if(this->size>=this->maxSize) return false;
        this->size++;
        ListNode *temp = new ListNode(value);
        if(this->size==1){
            head=temp;
            tail=head;
            return true;
        } 
        this->tail->next=temp;
        tail=temp;
        
        return true;
    }
    
    bool deleteFront() {
        if(!this->size) return false;
        this->size--;
        if(!this->size){
            this->head=nullptr;
            tail=head;
            return true;
        } 
        ListNode *temp= head;
        this->head=this->head->next;
        temp->next=nullptr;
        if(!this->size) tail=head;
        return true;
    }
    
    bool deleteLast() {
        if(!this->size) return false;
        this->size--;
        if(!this->size){
            this->head=nullptr;
            tail=head;
            return true;
        } 
        ListNode *temp= head;
        while(temp){
            if(temp->next==this->tail)
                break;
            temp=temp->next;
        }   
        temp->next=nullptr;
        this->tail=temp;
        return true;
    }
    
    int getFront() {
        if(this->size)
            return this->head->val;
        return -1;
    }
    
    int getRear() {
        if(this->size)
            return this->tail->val;
        return -1;
    }
    
    bool isEmpty() {
        return this->size==0;
    }
    
    bool isFull() {
        return this->size==this->maxSize;
    }
};

/**
 * Your MyCircularDeque object will be instantiated and called as such:
 * MyCircularDeque* obj = new MyCircularDeque(k);
 * bool param_1 = obj->insertFront(value);
 * bool param_2 = obj->insertLast(value);
 * bool param_3 = obj->deleteFront();
 * bool param_4 = obj->deleteLast();
 * int param_5 = obj->getFront();
 * int param_6 = obj->getRear();
 * bool param_7 = obj->isEmpty();
 * bool param_8 = obj->isFull();
 */