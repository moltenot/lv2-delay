#include <cstdlib>
#include "circular_buffer.hpp"
#include <iostream>

// constructor
circular_buffer::circular_buffer()
{
    // initialize the m_buffer
    for (size_t i = 0; i < BUFFER_SIZE; i++)
    {
        m_buffer[i] = 0.0;
    }

    // set the initial values of the head and tail
    this->head = 0;
    this->tail = 0;
    this->delta = 0;
}

// destructor
circular_buffer::~circular_buffer() {}

// dump the whole of the circular buffer to cout
void circular_buffer::dump()
{
    for (size_t i = 0; i < this->get_size(); i++)
    {
        std::cout << this->m_buffer[i] << "\t";
    }
    std::cout << "\tdelta: " << this->delta ;
    
    std::cout << std::endl;
}

// put the value in the buffer
void circular_buffer::put(float value)
{
    m_buffer[this->head] = value;
    this->head = (this->head + 1) % BUFFER_SIZE;
    delta += 1;
}

// retrieves the tail value and moves the tail pointer
float circular_buffer::pop()
{
    float value = m_buffer[this->tail];
    this->tail = (this->tail + 1) % BUFFER_SIZE;
    delta -= 1;
    return value;
}

int circular_buffer::get_delta()
{
    return this->delta;
}

std::size_t circular_buffer::get_size()
{
    return BUFFER_SIZE;
}