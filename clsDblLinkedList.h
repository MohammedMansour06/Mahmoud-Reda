#pragma once
#include<iostream>
using namespace std; 



template<class T> 
class clsDblLinkedList
{

protected : 
	int _Size = 0; 
public  : 


	class Node
	{
	public  :
		T value;  
		Node* next; 
		Node* prev; 
	};

	Node* head = NULL;  

	void PrintList()
	{
		Node* Current = head; 

		while (Current != NULL)
		{
			cout << Current->value << "  "; 
			Current = Current->next; 
		}
		cout << "\n"; 
		delete Current; 
	}

	void InsertAtBeginning(T Value)
	{
		Node* newNode = new Node(); 
		newNode->value = Value;  
		newNode->next = head; 
		newNode->prev = NULL;  

		if (head != NULL)
		{
			head->prev = newNode;  
		}
		head = newNode;  
		_Size++;
	}

		Node* Find(T Value)
		{
			Node* Current = head;
			while (Current != NULL) {

				if (Current->value == Value)
					return Current;

				Current = Current->next;
			}

			return NULL;
		}

	void InsertAfter(Node* Current, T Value)
	{
		Node* newNode = new Node();

		newNode->value = Value;
		newNode->next = Current->next;
		newNode->prev = Current;

		if (Current->next != NULL)
		{
			Current->next->prev = newNode;
		}
		Current->next = newNode;
		_Size++;
	}

	 void InsertAtEnd(T Value)
	{
		Node* newNode = new Node();
		newNode->value = Value; 
		newNode->next = NULL; 
		if (head == NULL)
		{
			newNode->prev = NULL; 
			head = newNode; 
		}
		else
		{
			Node* Current = head; 
			while (Current->next != NULL)
			{
				Current = Current->next; 
			}
			Current->next = newNode; 
			newNode->prev = Current;
			_Size++;
		}

	}

	void DeleteNode(Node*& NodeToDelete)
	{
		if (head == NULL || NodeToDelete == NULL)
		{
			return;
		}
		if (head == NodeToDelete)
		{
			head = NodeToDelete->next; 
		}
		if (NodeToDelete->next != NULL)
		{
			NodeToDelete->next->prev = NodeToDelete->prev; 
		}
		if (NodeToDelete->prev != NULL)
		{
			NodeToDelete->prev->next = NodeToDelete->next; 
		}
		delete NodeToDelete;
		_Size--;
	}

	void DeleteFirstNode()
	{

		/*
			1-Store a reference to the head node in a temporary variable.
			2-Update the head pointer to point to the next node in the list.
			3-Set the previous pointer of the new head to NULL.
			4-Delete the temporary reference to the old head node.
		*/

		if (head == NULL) {
			return;
		}
		Node* temp = head;
		head = head->next;
		if (head != NULL) {
			head->prev = NULL;
		}
		delete temp;
		_Size--;

	}

	void DeleteLastNode() {

		/*
			1-Traverse the list to find the last node.
			2-Set the next pointer of the second-to-last node to NULL.
			3-Delete the last node.
		*/

		if (head == NULL) {
			return;
		}

		if (head->next == NULL) {
			delete head;
			head = NULL;
			return;
		}

		Node* current = head;
		// we need to find the node before last node.
		while (current->next->next != NULL)
		{
			current = current->next;
		}

		Node* temp = current->next;
		current->next = NULL;
		delete temp;
		_Size--;
	}

	int Size()
	{
		return _Size; 
	}

	bool IsEmpty()
	{
		// Big O = O(1) ; 
		return (_Size == 0 ? true : false);

		// Another Method : 
		// return (head ==NULL); 
	}

	void Clear()
	{
		while (_Size > 0)
		{
			DeleteFirstNode();
		}
	}

	void Reverse()
	{
		
		Node* Current = head; 
		Node* temp = NULL; 
		while (Current != NULL)
		{
			temp = Current->prev; 
			Current->prev = Current->next; 
			Current->next = temp;
			Current = Current->prev;
		}
		
		if (temp != NULL)
		{
			head = temp->prev; 
		}
	}

	Node* GetNode(int Index)
	{
		int Counter = 0; 

		if (Index > _Size - 1 || Index < 0)
			return NULL; 
		
		Node* Current = head; 
		while (Current != NULL && (Current->next != NULL))
		{
			if (Counter == Index)
				break; 

			Current = Current->next;
			Counter++;
		}
		return Current; 
		 
	}

	int GetItem(int Index)
	{
		Node* ItemNode = GetNode(Index);  
		
		if (ItemNode == NULL)
			return NULL;
		else
			return ItemNode->value; 

	}

	bool UpdateItem(int Index, T NewValue)
	{
		Node* ItemNode = GetNode(Index); 

		if (ItemNode != NULL)
		{
			ItemNode->value = NewValue;
			return true;
		}
		else
			return false; 
		
	}

	bool InsertAfter(int Index, T NewNodeValue)
	{
		Node* ItemNode = GetNode(Index); 
		if (ItemNode != NULL)
		{
			InsertAfter(ItemNode, NewNodeValue);
			return true;
		}
		else
			return false; 
; 
		
	}

};

