#include <bits/stdc++.h> 
/****************************************************************
    Following is the class structure of the Node class:
    class Node
    {
    public:
        int data;
        Node *next;
        Node(int data)
        {
            this->data = data;
            this->next = NULL;
        }
    };
*****************************************************************/

Node *removeDuplicates(Node *head)
{ // if your head is null 
   if(head == NULL)
        return NULL;

    Node*curr = head;
    while(curr != NULL){
        Node*temp = curr;
        while(temp->next != NULL){
            if(curr->data == temp->next->data){
                Node*duplicate = temp->next;
                temp->next = temp ->next->next;
                delete duplicate;
            }
            else{ // if current node is not equal to temp 
           temp = temp->next;

            }

        }
        curr = curr->next;
    }
    return head;
}
