#pragma once
#include<iostream>
#include"queue"
#include"clsDblLinkedList.h"
using namespace std; 


template<class T> 
class clsMyQueue
{

protected:  
	clsDblLinkedList<T> _MyList;
public : 
	void Push(T Item)
	{
		_MyList.InsertAtEnd(Item);
	}

	void Pop()
	{
		_MyList.DeleteFirstNode(); 
	}

	void Print()
	{
		_MyList.PrintList(); 
	}

	int Size()
	{
		return _MyList.Size(); 
	}

	bool IsEmpty()
	{
		return _MyList.IsEmpty();
	}

	T Front()
	{
		return _MyList.GetItem(0); 
	}

	T Back()
	{
		return _MyList.GetItem(Size() - 1); 
	}

	T GetItem(int Index)
	{
		return _MyList.GetItem(Index); 
	}

	void Reverse()
	{
		_MyList.Reverse(); 
	}

	void UpdateItem(int CurrentValue, int NewItemValue)
	{
		_MyList.UpdateItem(CurrentValue, NewItemValue); 
	}

	bool InsertAfter(int Index , T NewNodeValue)
	{
		return _MyList.InsertAfter(Index, NewNodeValue); 
	}

	void InsertAtFront(int Value)
	{
		_MyList.InsertAtBeginning(Value);  
	}

	void InsertAtBack(int Value)
	{
		_MyList.InsertAtEnd(Value); 
	}

	void Clear()
	{
		_MyList.Clear(); 
	}


};

