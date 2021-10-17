// $Id: Stack.cpp 827 2011-02-07 14:20:53Z hillj $

// Honor Pledge:
//
// I pledge that I have neither given nor received any help
// on this assignment.

//
// Stack
//
template <typename T>
Stack <T>::Stack (void)
{
    // COMMENT It appears as if you were using an raw C++ array to
    // implement you stack, but failed to declare the member variables
    // in the header file. You are to use your array class from assignment
    // one to realize the stack.
    
    data_ = nullptr;
    cur_size_ = 0;
    max_size_ = 0;
    track = 0;
}

//
// Stack
//
template <typename T>
Stack <T>::Stack (const Stack & stack)
{
    char* deepCopy = new char;
    *deepCopy = *(data_);
}

//
// ~Stack
//
template <typename T>
Stack <T>::~Stack (void)
{
    delete data_; 
}

//
// push
//
template <typename T>
void Stack <T>::push (T element)
{
    
    data_[track] = element;
    track++;

    
}

//
// pop
//
template <typename T>
void Stack <T>::pop (void)
{
    if(data_ == NULL) {
        throw std::out_of_range("No value to be popped");
    } else {
        data_[track] = NULL;
        track--;
    }
    
}

//
// operator =
//
template <typename T>
const Stack <T> & Stack <T>::operator = (const Stack & rhs)
{
    if (this != &rhs) {
        // COMMENT It would be easier if you just use the assignment operator
        // on the array to copy things from rhs.
        
        //changed the iteration length to avoid the runtime error. 
        for (size_t i = 0; i < sizeof(data_); i++)
        {
            data_[i] = rhs[i];
        }
    }

    return *this;
}

//
// clear
//
template <typename T>
void Stack <T>::clear (void)
{
    // COMMENT Just reset the variables instead popping each element, which
    // is expensive.

    for (size_t i = 0; i < track; i++)
    {
        data_[i] = NULL;
    }
}
