#include<iostream>

using namespace std;

#pragma pack(1)
struct node
{
	int data;
	struct node * next;
	struct node * prev;
};

typedef struct node NODE;
typedef struct node * PNODE;
typedef struct node ** PPNODE;

class DoublyLL
{
	public:
		PNODE First;
		int count;


		DoublyLL();

		void InsertFirst(int no);
		void InsertLast(int no);
		void InsertAtPos(int no, int ipos);

		void DeleteFirst();
		void DeleteLast();
		void DeleteAtPos(int ipos);

		void Display();
};

DoublyLL :: DoublyLL()
{
	First = NULL;
}

void DoublyLL :: InsertFirst(int no)
{
	PNODE newn = new NODE;

	newn -> next = NULL;
	newn-> data = no;
	newn-> prev = NULL;

	if(First == NULL)
	{
		First = newn;
		count++;
	}
	else
	{
		newn->next = First;
		(First)->prev = newn;
		First = newn;
		count++;
	}
}

void DoublyLL :: InsertLast(int no)
{
	PNODE newn = new NODE;
	PNODE temp = First;

	newn -> prev = NULL;
	newn-> data = no;
	newn -> next = NULL;

	if(First == NULL)
	{
		First = newn;
		count++;
	}
	else
	{
		while(temp->next != NULL)
		{
			temp = temp->next;
		}
		temp->next = newn;
		newn->prev = temp;
		count++;
	}
}



void DoublyLL :: InsertAtPos(int no , int ipos)
{
        if((ipos < 1)|| (ipos > count+1))
        {
                cout<<"Invalid position\n";
                return;
        }
        else if(ipos == 1)
        {
                InsertFirst(no);
        }
        else if (ipos == count+1)
        {
                InsertLast(no);
        }
        else
        {
                PNODE newn = new NODE;
                PNODE temp = First;
                newn->prev = NULL;
                newn-> data = no;
                newn->next =  NULL;

                for(int i = 1;i < ipos-1; i++)
                {
			if (temp == NULL)
            		{
           		        cout << "Unexpected null pointer\n";
                		return;
            		}
                        temp = temp->next;
                }
//		temp->next->prev = newn;

                (newn) ->next = (temp)->next;
		if (temp->next != NULL)
		{
                	(temp)->next->prev = newn;
		}
                (temp)->next = newn;
                (newn)->prev = temp;
                count++;
        }
}

void DoublyLL :: DeleteFirst()
{
	PNODE temp = First;
	if(First == NULL)
	{
		cout<<"linked List is empty Nothing to delete\n";
		return;
	}
	else if (First -> next == NULL)
	{
		delete First;
		First = NULL;
		count--;
	}
	else
	{
		First = First->next;
		delete First->prev;

		First->prev = NULL;
		
		count--;
	}
}

void DoublyLL :: DeleteLast()
{
	PNODE temp = First;

	if(First == NULL)
	{
		return;
	}
	else if(First -> next == NULL)
	{
		delete First;
		First = NULL;
		count--;
	}
	else
	{
		while(temp->next->next != NULL)
		{
			temp = temp->next;
		}
		delete temp -> next;
		temp->next = NULL;
		count--;
	}
}

void DoublyLL :: DeleteAtPos(int ipos)
{
	PNODE temp1 = NULL;
	PNODE temp2 = NULL;
	int iCnt = 0;

	if((ipos < 1)||(ipos > count+1))
	{
		cout<<"Invalid position\n";
		return;
	}
	
	if(ipos == 1)
	{
		DeleteFirst();
	}
	else if(ipos == count)
	{
		DeleteLast();
	}
	else
	{
		temp1 = First;
		for (iCnt = 1 ; iCnt < ipos-1;iCnt++)
		{
			temp1 = temp1 -> next;
		}
		temp2 = temp1->next;

		temp1->next = temp2->next;
		temp2->next->prev = temp1;
		delete temp2;
		count--;
	}
}


void DoublyLL :: Display()
{
	cout<<"Element of linked List are : \n";

	cout<<"NULL<=>";

	while(First != NULL)
	{
		cout<<"|"<<First->data<<"|<=>";
		First = First-> next;
	}
	cout<<"NULL\n";
}






int main()
{
	DoublyLL obj;

	obj.InsertFirst(51);
	obj.InsertFirst(21);
	obj.InsertFirst(11);
//	obj.Display();
//	cout<<"Number of nodes in the linked List : "<<obj.count<<"\n";


	obj.InsertLast(101);
	obj.InsertLast(111);
	obj.InsertLast(121);
//	obj.Display();
    //    cout<<"Number of nodes in the linked List : "<<obj.count<<"\n";

	obj.InsertAtPos(71,4);

	obj.DeleteFirst();

	obj.DeleteLast();

	obj.DeleteAtPos(3);

	obj.Display();

	cout<<"Numebr of nodes in the linked list : "<<obj.count<<"\n";


	return 0;
}
