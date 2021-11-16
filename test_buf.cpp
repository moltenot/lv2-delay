/** Creates an instance of a circular buffer for the
 * purposes of testing it
 */
#include "circular_buffer.hpp"

int main(void) {
    circular_buffer cb = circular_buffer();
    cb.dump();
}