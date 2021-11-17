/** Creates an instance of a circular buffer for the
 * purposes of testing it
 */
#include "circular_buffer.hpp"
#include <iostream>

int main(void) {
    circular_buffer cb = circular_buffer();
    cb.dump();
    cb.put(2.1);
    cb.dump();
    cb.put(3.2);
    cb.dump();
    cb.put(4.3);
    cb.dump();
    cb.put(5.5);
    cb.dump();
    cb.put(4.7);
    cb.dump();
    cb.put(8.7);
    cb.dump();

    std::cout << "cb.pop() = " << cb.pop() << std::endl;
    std::cout << "cb.pop() = " << cb.pop() << std::endl;
    std::cout << "cb.pop() = " << cb.pop() << std::endl;
    std::cout << "cb.pop() = " << cb.pop() << std::endl;
    std::cout << "cb.pop() = " << cb.pop() << std::endl;
    std::cout << "cb.pop() = " << cb.pop() << std::endl;
    
    
}