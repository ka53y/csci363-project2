// $Id: Array.cpp 827 2011-02-07 14:20:53Z hillj $

// Honor Pledge:
//
// I pledge that I have neither given nor receieved any help
// on this assignment.

#include <stdexcept>         // for std::out_of_bounds exception

//
// Queue
//
class Queue {
    size_t cur_size_, max_size_, track;
    char * data_;
    public:
        //constructor
        Queue (void);
        //copy constructor
        Queue (const Queue & arr);
        //destructor
        ~Queue (void);
        //adds the element to the end of the list;
        void Queue::enqueue(char T);
        //removes the element at the front of the list.If there are not elements in the queue, this method throws empty_exception, similar to the stack;
        void Queue::dequeue();
        //test if the queue is empty. If the queue is empty, then this method returns true. Otherwise, this method returns false;
        bool Queue::is_empty();
        //returns the number of elements in the queue
        size_t Queue::size();
        //removes all the elements in the queue.
        void Queue::clear();



};
Queue::Queue (void)
{
    data_ = nullptr;
    cur_size_ = 0;
    track = 0;
    max_size_ = 0;
    //declares the variables with a new size_t implemented called track
    //to help keep track of where we are in queue like a manual increment
}
Queue::Queue (const Queue & array)
{
    char* deepCopy = new char;
    *deepCopy = *(data_);
    //deep copy still not really sure what this is for 
}

Queue::~Queue (void)
{
    delete[] data_; 
    //destructor
}

void Queue::enqueue(char T){
    data_[track] = T;
    track++;
    //assigns the value to the proper place then increments
}

void Queue::dequeue() {
    if(data_ == NULL) {
        throw std::out_of_range("No value to be dequeued");
    } else {
        for (size_t i = 0; i < cur_size_-1; i++)
        {
            data_[i] = data_[i+1];
        }
        data_[cur_size_ - 1] = NULL;
    }
    //checks if the data is empty and returns exception if it is
    //if not then increments through array and shifts all values to the left 1
    //then deletes the last value in the array as it is a duplicate
    
}

bool Queue::is_empty() {
    if(data_ == NULL){
        return true;
    } else{
        return false;
    }
    //returns true if the data_ is empty and false if not
}

size_t Queue::size() {
    return track;
    //because we created a value to increment manually we can just return that increment value 
}

void Queue::clear() {
    if(data_ == NULL) {
        throw std::out_of_range("No value to be dequeued");
    } else {
        for (size_t i = 0; i < track; i++)
        {
            data_[i] = NULL;
        }
    }
    //checks if the data is empty if yes then throws exception
    //if not then increment through the values and set to null
}

