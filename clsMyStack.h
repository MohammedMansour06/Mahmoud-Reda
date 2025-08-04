#pragma once
#include<iostream>
#include"clsDblLinkedList.h"
#include"clsMyQueue.h"
using namespace std;

template<class T>
class clsMyStack : public clsMyQueue<T>
{	 
protected:  
	
public:

	void Push(T Item)
	{
		clsMyQueue<T> ::_MyList.InsertAtBeginning(Item); 
	}
	T Top()
	{
		return clsMyQueue<T>::_MyList.Front(); 
	 }
	T Bottom()
	{
		return clsMyQueue<T> ::_MyList.Back(); 
	}

};

