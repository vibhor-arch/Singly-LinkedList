#include<iostream>
using namespace std;
#include "Node.cpp"


class Pair
{
public:
    Node* head;
    Node* tail;
};


Node* takeInput()
{
    int data;
    cout << "Enter data::" << endl;
    cin >> data;
    Node* head = NULL;
    Node* tail = NULL;
    while(data != -1)
    {
        Node *newNode = new Node(data);
        if(head == NULL)
        {
            head = newNode;
            tail =newNode;
        }
        else
        {
            tail->next=newNode;
            tail=newNode;
        }
        cout << "Enter data::" << endl;
        cin >> data;

    }
    return head;
}

Node* insertAtPosition(int position,int value,Node* head)
{
    Node* newNode = new Node(value);
    if(position == 0)
    {
        newNode->next=head;
        head = newNode;
    }
    Node* temp=head;
    while(position != 1 && temp!= NULL)
    {
        temp=temp->next;
        --position;
    }
    if(temp != NULL && temp->next != NULL)
    {
        Node* temp2=temp->next;
        temp->next = newNode;
        newNode->next =temp2;
    }
    else if(temp!= NULL && temp->next == NULL)
    {
        temp->next=newNode;
    }
    return head;
}
Node* deleteAtPosition(int p,Node* head)
{
    Node* temp = head;
    if(p == 0)
        head = temp->next;
    while(p > 1 && temp != NULL)
    {
        temp=temp->next;
        --p;
    }
    if(temp != NULL)
        temp->next = temp->next->next;
    return head;
}

void printLinkedList(Node* temp)
{
    while(temp != NULL)
    {
        cout << temp->data << " ";
        temp=temp->next;
    }
}

Pair reverseLinkedListBetter(Node* head)
{
    if(head == NULL || head->next == NULL)
    {
        Pair ans;
        ans.head = head;
        ans.tail=head;
        return ans;
    }
    Pair smallAns = reverseLinkedListBetter(head->next);
    smallAns.tail->next = head;
    head->next =NULL;
    Pair ans;
    ans.head = smallAns.head;
    ans.tail = head;
    return ans;
}


Node* reverseLinkedList(Node* head)
{
    return reverseLinkedListBetter(head).head;
}
Node* reverseLinkedList2(Node* head)
{
    if(head == NULL || head->next == NULL)
        return head;
    Node* smallAns = reverseLinkedList2(head->next);
    Node* tail = head->next;
    tail->next =head;
    head->next = NULL;
    return smallAns;

}

int main()
{
   /* Node n1(10);
    Node* head = &n1;
    Node n2(20);
    n1.next=&n2;
    Node n3(30);
    n2.next=&n3;
    Node n4(40);
    n3.next=&n4;
    Node n5(50);
    n4.next=&n5;*/
    Node* head = takeInput();
    printLinkedList(head);
    //int p,d;
    cout << endl;
    /*cout << "Insert Position" << endl;
    cin >> p;
    cout  << "Insert data" << endl;
    cin >> d;
    head = insertAtPosition(p,d,head);
    printLinkedList(head);
    *///cout << "Delete Position" << endl;
    /*cin >> p;
    head = deleteAtPosition(p,head);
    printLinkedList(head);*/
    /*head = reverseLinkedList(head);
    printLinkedList(head);*/
    head = reverseLinkedList2(head);
    printLinkedList(head);
}
