//Взято от сюда https://ru.stackoverflow.com/questions/57957/%D0%94%D0%B2%D1%83%D0%BC%D0%B5%D1%80%D0%BD%D1%8B%D0%B9-vector
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
