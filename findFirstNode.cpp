//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node* next;
    
    Node(int val)
    {
        data = val;
        next = NULL;
    }
};

void loopHere(Node* head, Node* tail, int position)
{
    if(position==0) return;
    
    Node* walk = head;
    for(int i=1; i<position; i++)
        walk = walk->next;
    tail->next = walk;
}


// } Driver Code Ends
//User function Template for C++

/*struct Node
{
    int data;
    struct Node *next;
    Node(int x) {
        data = x;
        next = NULL;
    }

*/
class Solution
{
    public:
     //Function to find first node if the linked list has a loop.
    Node* detectLoop(Node* head){
     if (head == NULL || head->next == NULL) {
        return NULL; // No loop can exist in a list with 0 or 1 node
    }

    Node* slow = head;
    Node* fast = head;

    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast) {
            return slow; // There is a loop; return the intersecting node
        }
    }

    return NULL; // No loop found

    }
    Node* getStartingNode(Node *head){
    Node* intersect = detectLoop(head);

    if (intersect == nullptr) {
        return nullptr; // No loop, so no starting node
    }

    Node* slow = head;
    while (slow != intersect) {
        slow = slow->next;
        intersect = intersect->next;
    }

    return slow; // Return the starting node of the loop
}
    int findFirstNode(Node* head)
    {
        // your code here
    Node* startingNode = getStartingNode(head);

    if (startingNode == nullptr) {
        return -1; // No loop found
    }

    Node* temp = head;
    while (temp->next != startingNode) {
        temp = temp->next;
    }
    temp->next = nullptr; // Break the loop

    return startingNode->data;    
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n, num;
        cin>>n;
        
        Node *head, *tail;
        cin>> num;
        head = tail = new Node(num);
        
        for(int i=0 ; i<n-1 ; i++)
        {
            cin>> num;
            tail->next = new Node(num);
            tail = tail->next;
        }
        
        int pos;
        cin>> pos;
        loopHere(head,tail,pos);
        
        Solution ob;
        int ans = ob.findFirstNode(head);
        cout<<ans<<"\n";
    }
	return 0;
}
// } Driver Code Ends
