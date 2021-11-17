#include "dsp-utils/functions.hpp"
#include "circular_buffer.hpp"
#include "constants.hpp"

#include <lv2plugin.hpp>
#include <iostream>


static const float max_delay_seconds = 2.0;

class delay : public LV2::Plugin<delay>
{
private:
    double sample_rate;
    circular_buffer cb;

public:
    delay(double sample_rate) : LV2::Plugin<delay>(4)
    { // since there are 4 ports
        this->sample_rate = sample_rate;
        this->cb = circular_buffer(); // consulte the constants file for how long this is
        std::cout << "\nsample rate is: " << sample_rate << std::endl;
    };

    void run(uint32_t sample_count)
    {
        std::cout << "called run" << std::endl;
        for (size_t i = 0; i < sample_count; i++)
        {
            float echo;
            float &delay = *p(DELAY_PORT_INDEX); // the delay we want in seconds
            float &wet = *p(WET_PORT_INDEX); 
            
            // set the echo to 0 if we need to wait longer, or pop off the circular
            // buffer if we are ready to go
            if (this->cb.get_delta() >= delay*this->sample_rate) 
            {
                echo = this->cb.pop();
            } else {
                echo = 0.0;
            }
            // std::cout << "echo = " << echo << std::endl;

            // append the input to the circular buffer
            this->cb.put(p(INPUT_PORT_INDEX)[i]); 

            p(OUTPUT_PORT_INDEX)[i] = p(INPUT_PORT_INDEX)[i] + wet*echo;
        }
    }
};
unsigned _ = delay::register_class("https://github.com/moltenot/lv2-delay");