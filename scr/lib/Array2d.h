#include <vector>

template<typename T> class Array2D
{
public:
    Array2D(size_t w, size_t h): width(w), data(w*h) {}
    T* operator[](size_t i) {return data.data()+i*height;}
    const T* operator[](size_t i) const {return data.data()+i*height;}
private:
    std::vector<T> data;
    size_t width;
    //height не храним, так как при желании его можно посчитать, поделив data.size() на width
};