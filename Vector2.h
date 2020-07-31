//
// Created by yuitora . on 31/07/2020.
//

#ifndef BEZIER_VECTOR_H
#define BEZIER_VECTOR_H
#define list_pos std::vector<std::vector<double> >

#include <iostream>
#include <vector>

template <class T>
class Vector2 {
public:
    T x, y;

    Vector2() {};
    Vector2(T x, T y);

//    Vector2<T> operator+(Vector2<T> &v);
    Vector2<T> operator+(const Vector2<T> &v);
//    Vector2<T> operator-(Vector2<T> &v);
    Vector2<T> operator-(const Vector2<T> &v);
    Vector2<T> operator*(const int n);
    Vector2<T> operator*(const float n);
    Vector2<T> operator/(const float n);
    void add_to_output(list_pos &output);
    Vector2<T>& operator=(const Vector2<T> &v);
    float length();
    float length_squared();
};


#endif //BEZIER_VECTOR_H
