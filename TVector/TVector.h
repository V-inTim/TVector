#pragma once
#include <cmath>
#include <istream>

template <class T> 

class TVector
{

protected:
	T* data;
	size_t size;
	int startIndex;

public:
	TVector(int startIndex, size_t size = 10);
	TVector(const TVector& v);
	~TVector();
	size_t getSize() const;
	int getStartIndex() const;
	bool operator==(const TVector& v);
	TVector& operator=(const TVector& v);
	T& operator[] (int index);
	TVector operator+(T& el) const;
	TVector operator-(T& el) const;
	TVector operator*(T& el) const;
	T operator*(const TVector& v)const;
	TVector operator+(const TVector& v)const;
	TVector operator-(const TVector& v)const;
	double getLength() const;
	friend std::istream& operator>>(std::istream& is; TVector& v);
	friend std::ostream& operator<<(std::ostream& os; const TVector& v);


};

template<class T>
inline TVector<T>::TVector(int startIndex, size_t size)
{
	if (size == 0) throw "wrong size";
	data = new T[size];
	this->size = size;
	this->startIndex=startIndex;
}

template<class T>
inline TVector<T>::TVector(const TVector& v)
{
	this->size = v.size;
	this->startIndex = v.startIndex;
	this->data = new T[size];
	for (size_t i = 0; i < size; i++) {
		data[i] = v.data[i];
	}
}

template<class T>
inline TVector<T>::~TVector()
{
	delete[]data;
}

template<class T>
inline size_t TVector<T>::getSize() const
{
	return size;
}

template<class T>
inline int TVector<T>::getStartIndex() const
{
	return startIndex;
}

template<class T>
inline bool TVector<T>::operator==(const TVector& v)
{
	
	if (this == &v)
		return true;
	else
		if (size != v.size)
			return false;
		else
		{
			if (startIndex != v.startIndex)
				return false;
			else
			{
				for (size_t i = 0; i < size; i++)
					if (data[i] != v.data[i])
						return false;
				return true;
			}
		}
}

template<class T>
inline TVector<T>& TVector<T>::operator=(const TVector& v)
{
	if (this == &v)
		return *this;
	
	if (size != v.size) {
		T* tmp = data;
		data = new T[v.size];
		if (data = nullptr)
			data = tmp;
	}
	for (size_t i = 0; i < size; i++) {
		data[i] = v.data[i];
	}
	size = v.size;
	startIndex = v.startIndex;
}

template<class T>
inline T& TVector<T>::operator[](int index)
{
	if (index - startIndex < 0 || index - startIndex >= size) {
		throw "wrong index";
	}
	return data[index - startIndex];
}

template<class T>
inline TVector<T> TVector<T>::operator+(T& el) const
{
	TVector v(*this);
	for (sise_t i; i < size; i++) {
		v[i] += el;
	}
	return v;
}

template<class T>
inline TVector<T> TVector<T>::operator-(T& el) const
{
	return (*this) +(-el);
}

template<class T>
inline TVector<T> TVector<T>::operator*(T& el) const
{
	TVector v(*this);
	for (sise_t i; i < size; i++) {
		v[i] *= el;
	}
	return v;
}

template<class T>
inline T TVector<T>::operator*(const TVector& v) const
{
	if (size != v.size) {
		throw "wrong size"
	}
	T f();
	for (size_t i; i < size; i++) {
		f += data[i] * v.data[i];
	}
	return f;
}

template<class T>
inline TVector<T> TVector<T>::operator+(const TVector& v) const
{
	if (size != v.size) {
		throw "wrong size"
	}
	TVector ans(startIndex, size);
	for (size_t i; i < size; i++) {
		ans.data[i] = data[i] +v.data[i];
	}
	return ans;
}

template<class T>
inline TVector<T> TVector<T>::operator-(const TVector& v) const
{
	if (size != v.size) {
		throw "wrong size"
	}
	TVector ans(startIndex, size);
	for (size_t i; i < size; i++) {
		ans.data[i] = data[i] - v.data[i];
	}
	return ans;
}

template<class T>
inline double TVector<T>::getLength() const
{
	double ans = 0;
	for (size_t i; i < size; i++) {
		ans += data[i] * data[i];
	}
	return std::SQRT(ans);
}

