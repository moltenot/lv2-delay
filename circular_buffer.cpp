#include <cstdlib>
#include <circular_buffer.hpp>
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
circular_buffer::~circular_buffer()
{
    delete[] m_buffer;
}

std::size_t circular_buffer::size() const
{
    return BUFFER_SIZE;
}

void dump(circular_buffer *cb)
{
    for (size_t i = 0; i < cb->size(); i++)
    {
        std::cout << cb->m_buffer[i] << std::endl;
    }
}