#include <cstdlib>
#include "constants.hpp"

class circular_buffer
/**
 * @brief represents a circular buffer for the float data type
 * because I suck at c++ this will be as simple as possible
 */
{
private:
    int head;
    int tail;
    int delta; // how far behind the tail is from the head
    float m_buffer[BUFFER_SIZE];

public:
    circular_buffer(); // size is fixed in constants.hpp
    ~circular_buffer();

    std::size_t get_size(); // get the size of the buffer
    int get_delta();        // get the delta between the head and tail
    void put(float value);  // put a value into the buffer
    float pop();            // get a value from the buffer and remove it
    void dump();            // print the buffer to the console
};