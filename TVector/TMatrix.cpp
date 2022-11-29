#include "TMatrix.h"
template<class T>
std::ostream& operator<<(std::ostream& os, const TMatrix<T>& m)
{
    for (size_t i=0;i<m.size;i++)
        out << m.data[i] << std::endl;
    return out;

}
