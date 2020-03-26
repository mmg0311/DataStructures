#include <bits/stdc++.h>
using namespace std;

struct node
{
   int data;
   struct node *next;
};

//create new node
struct node *newNode(int data)
{
   struct node *temp = new (struct node);
   temp->data = data;
   temp->next = NULL;
   return temp;
}

//insert node at the head
struct node *insertAtHead(node *head, int data)
{
   struct node *temp = newNode(data);
   temp->next = head;
   head = temp;
   return head;
}

//insert the node at tail
struct node *insertAtTail(node *head, int data)
{
   struct node *temp = newNode(data);
   struct node *t = head;
   while (t->next != NULL)
   {
      t = t->next;
   }
   t->next = temp;
   return head;
}

//print the element of the linked list
void printList(struct node *head)
{
   struct node *temp = head;
   while (temp != NULL)
   {
      cout << temp->data << " ";
      temp = temp->next;
   }
   cout << endl;
}

//insert a node at specific position from head in list
struct node *insertAtPosition(node *head, int data, int pos)
{
   struct node *p = newNode(data);
   struct node *temp = head;
   pos--;
   while (temp != NULL && pos > 0)
   {
      temp = temp->next;
      pos--;
   }
   p->next = temp->next;
   temp->next = p;
   return head;
}

//delete a node
struct node *deleteNode(node *head, int pos)
{
   struct node *temp = head;
   struct node *temp2, *p;
   if (pos == 0)
   {
      head = head->next;
      delete (temp);
      return head;
   }
   while (temp != NULL && pos > 1)
   {
      pos--;
      temp = temp->next;
   }
   temp2 = temp->next;
   p = temp2;
   temp2 = temp2->next;
   temp->next = temp2;
   delete (p);
   return head;
}

//print reverse
void printReverse(struct node *head)
{
   stack<int> s;
   struct node *temp = head;
   while (temp != NULL)
   {
      s.push(temp->data);
      temp = temp->next;
   }
   while (!s.empty())
   {
      cout << s.top() << " ";
      s.pop();
   }
}

//reverse the linked list
struct node *reverseList(struct node *head)
{
   stack<struct node *> s;
   struct node *temp = head;
   while (temp != NULL)
   {
      s.push(temp);
      temp = temp->next;
   }
   head = s.top();
   s.pop();
   temp = head;
   while (!s.empty())
   {
      temp->next = s.top();
      s.pop();
      temp = temp->next;
   }
   temp->next = NULL;
   return head;
}

//compare two linked list
//return 0 if both are equal
//return 1 if both are not equal
int compare(struct node *head1, struct node *head2)
{
   struct node *t1 = head1;
   struct node *t2 = head2;
   while (t1 != NULL && t2 != NULL)
   {
      if (t1->data == t2->data)
      {
         t1 = t1->next;
         t2 = t2->next;
      }
      else
      {
         break;
      }
   }
   if (t1 == NULL && t2 == NULL)
   {
      return 1;
   }
   return 0;
}

//merge two sorted linked list
struct node *mergeLists(node *head1, node *head2)
{
   struct node *result = NULL;
   if (head1 == NULL)
   {
      return head2;
   }
   if (head2 == NULL)
   {
      return head1;
   }
   if (head1->data <= head2->data)
   {
      result = head1;
      result->next = mergeLists(head1->next, head2);
   }
   else
   {
      result = head2;
      result->next = mergeLists(head1, head2->next);
   }
   return result;
}

//delete duplicate value nodes from the sorted list
struct node *deleteDuplicate(struct node *head)
{
   struct node *curr = head;
   struct node *next = head->next;
   struct node *copy = NULL;
   while (curr->next != NULL && next != NULL)
   {
      if (curr->data == next->data)
      {
         copy = next;
         next = next->next;
         curr->next = next;
         delete (copy);
      }
      else
      {
         curr = curr->next;
         next = curr->next;
      }
   }
   return head;
}

//get node from tail of the list i.e pos == 0 means tail node
//pos == 1 means second last node ....
int getNodeFromTail(struct node *head, int pos)
{
   struct node *h = head;
   struct node *h2 = head;
   pos++;
   while (pos--)
   {
      h2 = h2->next;
   }
   while (h2 != NULL)
   {
      h = h->next;
      h2 = h2->next;
   }
   return h->data;
}

bool hasCycle(struct node *head)
{
   struct node *curr = head, *next = head;
   while (curr != NULL && next != NULL && next->next != NULL)
   {
      curr = curr->next;
      next = next->next->next;
      if (curr->data == next->data)
      {
         return true;
      }
   }
   return false;
}

//find merge node in the lists
int findMergeNode(struct node *head1, struct node *head2)
{
   unordered_map<struct node *, int> m;
   struct node *h = head1;
   while (h != NULL)
   {
      m[h] = 1;
      h = h->next;
   }
   h = head2;
   while (h != NULL)
   {
      if (m[h] == 1)
      {
         return h->data;
      }
      h = h->next;
   }
   return -1;
}

int main()
{
   struct node *head = NULL;
}