#ifndef DYNAMICARRAY_H_
#define DYNAMICARRAY_H_


class DynamicArray
{

public:
	DynamicArray();
	DynamicArray(const int _capacite);
	DynamicArray(const DynamicArray & _source);
	~DynamicArray();
	const unsigned int getCapacite();
	const int getElement(const unsigned int _index);
	void setElement(const unsigned int _index, const int _valeur);
	void setCapacite(const unsigned int _nouvelle_capacite);
private:
	unsigned int capacite = 100;
	int * tabElements;
};


#endif //DYNAMICARRAY_H_