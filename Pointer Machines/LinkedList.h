#include "Node.h"

template <class K, class D>
class LinkedList
{
private:
	Node<K,D>* raiz;

public:
	LinkedList();
	~LinkedList();

	bool Insert(K p_key, D p_dato);
	bool Remove(K p_key);
	void Show();
	Node<K,D>* GetRaiz();
};

template <class K, class D>
LinkedList<K,D>::LinkedList()
{
	raiz = nullptr;
}

template <class K, class D>
LinkedList<K,D>::~LinkedList()
{
}

template <class K, class D>
bool LinkedList<K,D>::Insert(K p_key, D p_dato)
{
	if (raiz == nullptr)
	{
		raiz = new Node<K,D>(p_key, p_dato);
		return true;
	}
	else
	{
		Node<K,D>* actual = raiz;
	
		while (actual!=nullptr)
		{
			if (actual->GetSiguiente()==nullptr)
			{
				Node<K,D>* Nuevo= new Node<K,D>(p_key, p_dato);
				actual->SetSiguiente(Nuevo);
				Nuevo->siguiente = nullptr;
				return true;
			}
			else
			{
				actual=actual->GetSiguiente();
			}
		}
		
	
		return true;
	}	
}

template <class K, class D>
void LinkedList<K,D>::Show()
{
	Node<K,D>* actual = raiz;
	while(actual!=nullptr)
	{
		cout << actual->GetKey()<<"->";
		actual = actual->GetSiguiente();
	}
}

template <class K, class D>
bool LinkedList<K,D>::Remove(K p_key)
{
	if (raiz!= nullptr)
	{
		Node<K,D>* Actual = raiz;

		if (raiz->GetKey() == p_key)
		{
			raiz = Actual->siguiente;
			delete Actual;
			return true;
		}

		else if (raiz->siguiente == nullptr)
		{
			raiz = nullptr;
			return true;

		}
		
		else 
		{ 

		Node<K,D>* Temp = Actual;
		while (Actual->GetKey() != p_key)
		{
			Temp = Actual;			
			Actual = Actual->siguiente;		
			
	    }
		Temp->siguiente = Actual->siguiente;
		delete Actual;
		return true;
		}
	}
	else
	{
		return false;
	}
	return false;
}

template <class K, class D>
Node<K,D>*  LinkedList<K,D>::GetRaiz()
{
	return raiz;
}
