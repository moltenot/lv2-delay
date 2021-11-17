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
}

// destructor
circular_buffer::~circular_buffer() {}

std::size_t circular_buffer::size() const
{
    return BUFFER_SIZE;
}

// dump the whole of the circular buffer to cout
void circular_buffer::dump()
{
    circular_buffer *cb = this;
    for (size_t i = 0; i < cb->size(); i++)
    {
        std::cout << cb->m_buffer[i] << "\t";
    }
    std::cout << std::endl;
}

// put the value in the buffer
void circular_buffer::put(float value)
{
    m_buffer[this->head] = value;
    this->head = (this->head + 1) % BUFFER_SIZE;
}

// retrieves the tail value and moves the tail pointer
float circular_buffer::pop()
{
    float value = m_buffer[this->tail];
    this->tail = (this->tail + 1) % BUFFER_SIZE;
    return value;
}