#ifndef VECTOR_H
#define VECTOR_H
#include <stdlib.h>
#include <iostream>
/*
	Written in 2019
	Vector implementation
	In the comments an alternative iterator implementation
*/
class VectorException : public std::exception
{
private:
	std::string m_error;
public:
	VectorException(std::string error) : m_error(error) {}
	virtual const char* what() const noexcept { return m_error.c_str(); }
};

template <class T>
class vector
{
protected:
	unsigned int my_size;
	unsigned int my_capacity;
	T* data;
public:
	// typedef T * iterator;
	T & front();
	T & back();
	void push_back(const T & value);
	void pop_back();

	void reserve(unsigned int capacity);
	void resize(unsigned int size);
	T at(int in);
	unsigned int capacity() const;
	unsigned int size() const;
	bool empty() const;     //
							// iterator begin();  
							// iterator end();
	T & operator[](unsigned int index);
	vector<T> & operator=(const vector<T> &);
	void clear();
	vector();
	vector(unsigned int size, const T &t);
	vector(const vector<T> & Right);
	~vector();
	void shrink_to_fit();
	void insert(T* pos, T value);
	void insert(T *pos, unsigned count, T value);
	void erase(T *pos);
	int find(T *pos);
	void show();
	class iterator
	{
	public:
		iterator() { iter = NULL; }
		iterator(T* pos) { iter = pos; }
		~iterator() {}
		T& operator*() { return *iter; }
		T* operator=(T* v) {
			iter = v;
			return iter;
		}
		T* operator ++(int) { return ++iter; }
		T* operator+(int num) { return iter + num; }

		T* operator --(int) {
			iter--;
			return iter;
		}
		bool operator ==(iterator iter2) { return iter == iter2.iter; }

		bool operator !=(iterator iter2) { return iter != iter2.iter; }
	private:
		T * iter;
	};
	friend class iterator;

	iterator begin() {
		if (size() != 0)
			return data;
		else return end();
	}

	iterator rbegin() {
		if (size() != 0)
			return data + (my_size - 1);
		else
			return rend();
	}


	iterator end() {
		return data + my_size;
	}

	iterator rend() {
		return (data - 1);
	}
private:
	void insert(unsigned int i, T value);
};


template<class T>
vector<T>::vector()
{
	my_capacity = 0;
	my_size = 0;
	data = nullptr;
}

template<class T>
vector<T>::vector(const vector<T> & v)
{
	my_size = v.my_size;
	my_capacity = v.my_capacity;
	data = (T*)calloc(my_capacity, sizeof(T));
	memcpy(data, v.data, my_size * sizeof(T));
}


template<class T>
vector<T>::vector(unsigned int size, const T & initial)
{
	my_size = size;
	my_capacity = my_size;
	data = (T*)calloc(my_capacity, sizeof(T));
	for (unsigned int i = 0; i < size; i++)
		data[i] = initial;
}

template<class T>
vector<T> & vector<T>::operator= (const vector<T> & v)
{
	my_size = v.my_size;
	my_capacity = v.my_capacity;
	data = (T*)calloc(my_capacity, sizeof(T));
	memcpy(data, v.data, my_size * sizeof(T));

	return *this;
}
/*
template<class T>
typename vector<T>::iterator vector<T>::begin()
{
return data;
}

template<class T>
typename vector<T>::iterator vector<T>::end()
{
return data + size();
}*/

template<class T>
T& vector<T>::front()
{
	return data[0];
}

template<class T>
T& vector<T>::back()
{
	return data[my_size - 1];
}

template<class T>
void vector<T>::push_back(const T & v)
{
	if (my_size >= my_capacity) {
		reserve(my_capacity + 2);
	}
	data[my_size++] = v;
}

template<class T>
void vector<T>::pop_back()
{
	if(my_size) my_size--;
}

template<class T>
void vector<T>::reserve(unsigned int capacity)
{
	if (data == nullptr){
		my_size = 0;
		my_capacity = 0;
	}
	T * Newdata = (T*)calloc(my_capacity, sizeof(T));
	unsigned int l_size = my_capacity < my_size ? my_capacity : my_size;
	memcpy(Newdata, data, l_size * sizeof(T));
	my_capacity = capacity;
	my_size = l_size;
	data = (T*)calloc(my_capacity, sizeof(T));
	memcpy(data, Newdata, my_size * sizeof(T));
}

template<class T>
unsigned int vector<T>::size()const//
{
	return my_size;
}

template<class T>
void vector<T>::resize(unsigned int size)
{
	reserve(my_size);
	my_size = size;
}

template<class T>
T& vector<T>::operator[](unsigned int index)
{
	return data[index];
}

template<class T>
unsigned int vector<T>::capacity()const
{
	return my_capacity;
}

template<class T>
vector<T>::~vector()
{
	free(data);
}
template <class T>
void vector<T>::clear()
{
	my_capacity = 0;
	my_size = 0;
	data = nullptr;
}
template<class T>
bool vector<T>::empty()const
{
	return !data;
}

template<class T>
void vector<T>::insert(T*pos, T value)
{
	int i = find(pos);
	if (0 <= i && i <= size())
		insert(i, value);
}

template<class T>
void vector<T>::insert(T*pos, unsigned int count, T value)
{
	int i = find(pos);
	if (0 <= i && i <= size())
		for (int j = 0; j < count; j++)
			insert(i, value);

}
template<class T>
void vector<T>::insert(unsigned int i, T value) {
	if (my_size >= my_capacity) {
		reserve(my_capacity + 2);
	}
	for (int j = my_size; j > i; j--)
		data[j] = data[j - 1];
	data[i] = value;
	my_size++;
}

template<class T>
void vector<T>::erase(T*pos)
{
	int i = find(pos);
	if (0 <= i<size()) {
		for (; i<my_size - 2; i++)
			data[i] = data[i + 1];
		my_size--;
	}
}

template<class T>
int vector<T>::find(T*pos) {
	int i = 0;
	for (; data + i != pos && i<size(); i++);
	return i;
}

template<class T>
void vector<T>::shrink_to_fit() {
	if (my_capacity>my_size)
		reserve(my_size);

}

template<class T>
void vector<T>::show() {
	for (unsigned int i = 0; i<my_size; i++) {
		std::cout << data[i] << " ";
	}
	std::cout << std::endl;
}

template<class T>
T  vector<T>::at(int pos) {
	if (!(0 <= pos && pos< size()))
		throw VectorException("out of range");
	else return *data + pos;
}

#endif // VECTOR_H
