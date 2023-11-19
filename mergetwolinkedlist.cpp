Node* solve(Node *head1,Node *head2){
        Node* curr1=head1;
        Node *next1=curr1->next;
        Node *curr2=head2;
        Node * next2=curr2->next;
        
        while(curr1!=NULL && next1!=NULL){
            if((curr2->data>=curr1->data) && (curr2->data<=next1))
           { curr1->next=curr2;
            next2=curr2->next;
            curr2->next=next1;
            
            curr1=curr2;
            curr2=curr1;
        }
        else{
            curr1=next1;
            next1=next1->next;
            if(next1==NULL){
                curr1->next=curr2;
                return head1;
            }
            
        }
            
        }
        return head1;
    }
    Node* findIntersection(Node* head1, Node* head2)
    {
        // code goes here.
        if(head1==NULL)
        return head2;
        
        if(head2==NULL)
        return head1;
        
        if(head1->data<=head2->data)
        solve(head1,head2);
        else
        solve(head2,head1);
    }
