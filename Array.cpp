// $Id: Array.cpp 827 2011-02-07 14:20:53Z hillj $

// Honor Pledge:
//
// I pledge that I have neither given nor receieved any help
// on this assignment.

#include "Array.h"
#include <stdexcept>         // for std::out_of_bounds exception

//
// Array
//
template <typename T>
Array <T>::Array (void)
{
    data_ = nullptr;
    cur_size_ = 0;
    max_size_ = 0;
}

//
// Array (size_t)
//
template <typename T>
Array <T>::Array (size_t length)
{
    cur_size_ = 0;
    max_size_ = length;
    char* data_;
    data_ = new char[length];
}

//
// Array (size_t, char)
//
template <typename T>
Array <T>::Array (size_t length, T fill)
{
    cur_size_ = length;
    max_size_ = length;
    char* data_;
    data_ = new char[length];
    for (size_t i = 0; i < length; i++)
    {
        data_[i] = fill;
    }
}

//
// Array (const Array &)
//
template <typename T>
Array <T>::Array (const Array & array)
{
    char* deepCopy = new char;
    *deepCopy = *(data_);
}

//
// ~Array
//
template <typename T>
Array <T>::~Array (void)
{
    delete[] data_; 
}

//
// operator =
//
template <typename T>
const Array <T> & Array <T>::operator = (const Array & rhs)
{
    if (this != &rhs) {
        //changed the iteration length to avoid the runtime error. 
        for (size_t i = 0; i < sizeof(data_); i++)
        {
            data_[i] = rhs[i];
        }
    }

    return *this;
}

//
// operator []
//
template <typename T>
T & Array <T>::operator [] (size_t index)
{
    char returnValue;
    if (index >= 0 && index < sizeof(data_)) {
        returnValue = data_[index];
    }
    else {
        throw std::out_of_range("value is not in the proper range");
    }
    return data_[index];
}

//
// operator [] 
//
template <typename T>
const T & Array <T>::operator [] (size_t index) const
{
    char returnValue;
    if (index >= 0 && index < sizeof(data_)) {
        returnValue = data_[index];
    }
    else {
        throw std::out_of_range("value is not in the proper range");
    }
    return data_[index];
}

//
// get
//
template <typename T>
T Array <T>::get (size_t index) const
{
    char returnValue;
    if (index >= 0 && index < sizeof(data_)) {
        returnValue = data_[index];
    }
    else {
        throw std::out_of_range("value is not in the proper range");
    }
    return data_[returnValue];
    
}

//
// set
//
template <typename T>
void Array <T>::set (size_t index, T value)
{
    if (index >= 0 && index < sizeof(data_)) {
        data_[index] = value;
    }
    else {
        throw std::out_of_range("value is not in the proper range");
    }
}

//
// resize
//
template <typename T>
void Array <T>::resize (size_t new_size)
{
    char *newArr = new char[new_size];
    if (new_size != cur_size_)
    {
        for (size_t i = 0; i < new_size; i++)
        {
            newArr[i] = data_[i];
        }
        *data_ = *newArr;
    }
}

//
// find (char)
//
template  <typename T>
int Array <T>::find (T value) const
{
    for (int i = 0; i < cur_size_; i++)
    {
        if (data_[i] == ch) {
            return i;
        }
    }
    return -1;
}

//
// find (char, size_t) 
//
template <typename T>
int Array <T>::find (T val, size_t start) const
{
    for (size_t i = start; i < cur_size_; i++)
    {
        if (data_[i] == ch) {
            return i;
        }
    }
    return -1;
}

//
// operator ==
//
template <typename T>
bool Array <T>::operator == (const Array & rhs) const
{
    if (this != &rhs) {
        for (size_t i = 0; i < cur_size_; i++)
        {
            if (data_[i] != rhs[i]) {
                return false;
            }
        }
    }
    return true;

}

//
// operator !=
//
template <typename T>
bool Array <T>::operator != (const Array & rhs) const
{
int i = 0;
    do
    {
        i++;
        if (i == max_size_ - 1) {
            return true;
        }

    } while (rhs[i] != data_[i]);
    return false;
}

//
// fill
//
template <typename T>
void Array <T>::fill (T value)
{
    for (size_t i = 0; i < max_size_; i++)
    {
        data_[i] = ch;
    }
}
