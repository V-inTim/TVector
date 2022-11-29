#pragma once
#include "TVector.h"
template <class T>

class TMatrix: public TVector<TVector<T>>
{
public:
	TMatrix(size_t size = t) : TVector<TVector<T>>( size);
	TMatrix(const TMatrix& m);
	TMatrix(const TVector <TVector<T>>& v);
	bool operator==(const TMatrix& m) const;
	bool operator!=(const TMatrix& m) const;
	TMatrix& operator=(const TMatrix& m);
	TMatrix operator+(const TMatrix& m);
	TMatrix operator-(const TMatrix& m);
	TMatrix operator*(const TMatrix& m);
	friend std::ostream& operator<<(std::ostream& os, const TMatrix& m);
};

template<class T>
inline TMatrix<T>::TMatrix(size_t size)
{
	for (size_t i = 0; i < size; i++) {
		data[i]=TVector<T>(i, size_t)
	}
}

template<class T>
inline TMatrix<T>::TMatrix(const TMatrix& m)
{
	TVector<TVector<T>>(m);
}

template<class T>
inline TMatrix<T>::TMatrix(const TVector<TVector<T>>& v)
{
	TVector<TVector<T>>(m);
}

template<class T>
inline bool TMatrix<T>::operator==(const TMatrix& m) const
{
	if (this== &m)
		return true;
	if (size != m.size)
		return false;
	else {
		for (size_t i = 0; i < size; i++)
			if (data[i] != m.data[i])
				return false;
		return true;
	}
}

template<class T>
inline bool TMatrix<T>::operator!=(const TMatrix& m) const
{
	return !(*this == m);
}

template<class T>
inline TMatrix<T>& TMatrix<T>::operator=(const TMatrix& m)
{
	if (this != &m) {
		if (this != m.size) {
			delete[]data;
			data = new TVector<T>[m.size];
			size = m.size;
			for (size_t i = 0; i < size; i++)
				data[i] = m.data[i];
		}

	}
	return *this;
}

template<class T>
inline TMatrix<T> TMatrix<T>::operator+(const TMatrix& m)
{
	return TVector<TVector<T>>::operator+(m);
}

template<class T>
inline TMatrix<T> TMatrix<T>::operator-(const TMatrix& m)
{
	return TVector<TVector<T>>::operator-(m);
}

template<class T>
inline TMatrix<T> TMatrix<T>::operator*(const TMatrix& m)
{
	return TVector<TVector<T>>::operator*(m);
}
