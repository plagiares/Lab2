#include "dynamicArray.h"
#include <iostream>
#include <algorithm>

DynamicArray::DynamicArray()
{
	tabElements = new int[capacite];
	for (int i = 0; i < capacite; i++)
	{
		tabElements[i] = 0;
	}
}

DynamicArray::DynamicArray(int _capacite)
{
	if (_capacite == 0) throw std::invalid_argument("La dimension du tableau ne peux pas etre vide");
	capacite = _capacite;
	tabElements = new int[capacite];
	for (int i = 0; i < capacite; i++)
	{
		tabElements[i] = 0;
	}
}

DynamicArray::DynamicArray(const DynamicArray& _source)
:capacite(_source.capacite), tabElements(new int[_source.capacite])
{
	for (unsigned int i = 0; i < capacite; i++)
	{
		tabElements[i] = _source.tabElements[i];
	}

}

DynamicArray& DynamicArray::operator=(const DynamicArray& _source)
{
	if (&_source != this)
	{
		delete[] tabElements;
		capacite = _source.capacite;
		tabElements = new int[capacite];
		for (unsigned int i = 0; i < capacite; i++)
		{
			tabElements[i] = _source.tabElements[i];
		}
	}
	return *this;
}

bool DynamicArray::operator==(const DynamicArray& _rhs) const
{
	bool verificateur = true;
	if (&_rhs != this)
	{
		if (capacite != _rhs.capacite)
		{
			verificateur = false;
		}
		
		for (unsigned int i = 0; i < capacite; i++)
		{
			if (tabElements[i] != _rhs.tabElements[i])
			{
				verificateur = false;
			}
		}
	}
	return verificateur;
}

DynamicArray& DynamicArray::operator+=(const DynamicArray& _rhs)
{
	if (&_rhs != this)
	{
			int * temporaryElements = new int[_rhs.capacite + capacite];
			for (unsigned int i = 0; i < capacite; i++)
			{
				temporaryElements[i] = tabElements[i];
			}
			for (unsigned int i = 0; i < _rhs.capacite; i++)
			{
				temporaryElements[i+capacite] = _rhs.tabElements[i];
			}
			capacite = (_rhs.capacite + capacite);
			delete[] tabElements;
			tabElements = temporaryElements;

		}
		return *this;
	}


DynamicArray::~DynamicArray()
{
	delete[] tabElements;
}

const unsigned DynamicArray::getCapacite()
{
	return capacite;
}

const int DynamicArray::getElement(const unsigned _index)
{
	if (_index > capacite) throw std::out_of_range("Le pile est vide");
	return tabElements[_index];
}

void DynamicArray::setElement(unsigned _index, int _valeur)
{
	if (capacite < _index)
	{
	// j'avais pas fait un plus 1
	setCapacite(_index + 1);
	}
	tabElements[_index] = _valeur;
}

void DynamicArray::setCapacite(const unsigned int _nouvelle_capacite)
{
	if (_nouvelle_capacite < 1 ) throw std::invalid_argument("Le pile est vide");

	int * temporaryElements= new int[_nouvelle_capacite];

	for (int i = 0; i < _nouvelle_capacite; i++)
	{
			temporaryElements[i] = 0;
	}

	for (unsigned int i = 0; i < std::min(capacite, _nouvelle_capacite); ++i)
	{
		temporaryElements[i] = tabElements[i];
		std::cout << temporaryElements[i] << std::endl;
	}
	
	capacite = _nouvelle_capacite;
	delete[] tabElements;
	tabElements = temporaryElements;
	
	//Affecter la nouvelle capacité.
	//Libère l’ancienne mémoire(delete) et la remplacer par la nouvelle.
}