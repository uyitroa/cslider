//
// Created by yuitora . on 31/07/2020.
//

#include "Vector2.h"
#include <cmath>


template<class T>
Vector2<T>::Vector2(T x, T y) {
        this->x = x;
        this->y = y;
}

//template<class T>
//Vector2<T> Vector2<T>::operator+(Vector2<T> &v) {
//    return Vector2<T>(T(this->x + v.x), T(this->y + v.y));
//}

template<class T>
Vector2<T> Vector2<T>::operator+(const Vector2<T> &v) {
    return Vector2<T>(T(this->x + v.x), T(this->y + v.y));
}


//template<class T>
//Vector2<T> Vector2<T>::operator-(Vector2<T> &v) {
//    return Vector2<T>(T(this->x - v.x), T(this->y - v.y));
//}

template<class T>
Vector2<T> Vector2<T>::operator-(const Vector2<T> &v) {
    return Vector2<T>(T(this->x - v.x), T(this->y - v.y));
}

template<class T>
Vector2<T> Vector2<T>::operator*(const int n) {
    return Vector2<T>(T(this->x * n), T(this->y * n));
}

template<class T>
Vector2<T> Vector2<T>::operator*(const float n) {
    return Vector2<T>(T(this->x * n), T(this->y * n));
}

//template<class T>
//Vector2<T> Vector2<T>::operator/(const int n) {
//    return Vector2<T>(T(this->x / n), T(this->y / n));
//}

template<class T>
float Vector2<T>::length() {
    return sqrt(this->length_squared());
}

template<class T>
float Vector2<T>::length_squared() {
    return (pow(this->x, 2) + pow(this->y, 2));
}

template<class T>
Vector2<T>& Vector2<T>::operator=(const Vector2<T> &v) {
    this->x = v.x;
    this->y = v.y;
    return *this;
}

template<class T>
void Vector2<T>::add_to_output(PyObject *output) {
    PyList_Append(output, PyFloat_FromDouble(this->x));
    PyList_Append(output, PyFloat_FromDouble(this->y));
}

template<class T>
Vector2<T> Vector2<T>::operator/(const float n) {
    return Vector2<T>(T(this->x / n), T(this->y / n));
}

//template class Vector2<double>;
//template class Vector2<double>;
template class Vector2<double>;