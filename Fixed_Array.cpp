// $Id: Fixed_Array.cpp 827 2011-02-07 14:20:53Z hillj $

// Honor Pledge:
//
// I pledge that I have neither given nor received any help
// on this assignment.

//
// Fixed_Array
//
template <typename T, size_t N>
Fixed_Array <T, N>::Fixed_Array (void)
{
    data_ = nullptr;
    cur_size_ = 0;
    max_size_ = 0;
}

//
// Fixed_Array
//
template <typename T, size_t N>
Fixed_Array <T, N>::Fixed_Array (const Fixed_Array <T, N> & arr)
{
	
}

//
// Fixed_Array
//
template <typename T, size_t N>
template <size_t M>
Fixed_Array <T, N>::Fixed_Array (const Fixed_Array <T, M> & arr)
{
	char* deepCopy = new char;
    *deepCopy = *(data_);
}

//
// Fixed_Array
//
template <typename T, size_t N>
Fixed_Array <T, N>::Fixed_Array (T fill)
{
    for (size_t i = 0; i < cur_size_; i++)
    {
        data_[i] = fill;
    }
    
    
}

//
// ~Fixed_Array
//
template <typename T, size_t N>
Fixed_Array <T, N>::~Fixed_Array (void)
{
    delete data_;
}

//
// operator =
//
template <typename T, size_t N>
const Fixed_Array <T, N> & Fixed_Array <T, N>::operator = (const Fixed_Array <T, N> & rhs)
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
// operator =
//
template <typename T, size_t N>
template <size_t M>
const Fixed_Array <T, N> & Fixed_Array <T, N>::operator = (const Fixed_Array <T, M> & rhs)
{

}
