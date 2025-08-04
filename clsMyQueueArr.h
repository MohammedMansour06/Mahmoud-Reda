#pragma once

#include<iostream>  
#include"clsDynamicArray.h"

using namespace std;

template<class T > 
class clsMyQueueArr	
{

protected:  
	clsDynamicArray<T> _MyList;  


public  : 
	void Push(T Value)
	{
		_MyList.InsertAtEnd(Value); 
	}

	void Print()
	{
		_MyList.PrintList(); 
	}
	void pop()
	{
		_MyList.DeleteFirstItem(); 
	}

	T Size()
	{
		return _MyList.Size(); 
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

	bool IsEmpty()
	{
		return _MyList.IsEmpty();
	}

	void UpdateItem(T Index, T NewValue)
	{
		_MyList.SetItem(Index, NewValue); 
	}

	bool InsertAfter(T Index, T NewVale)
	{
		return _MyList.InsertAfter(Index, NewVale); 
	}
	void InsertAtFront(T FrontValue)
	{
		_MyList.InsertAtBeiginning(FrontValue);  
	 }

	void InsertAtBack(T BackValue)
	{
		_MyList.InsertAtEnd(BackValue); 
	}

	void Clear()
	{
		_MyList.Clear(); 
	}

};

