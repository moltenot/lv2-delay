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