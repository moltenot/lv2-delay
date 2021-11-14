#include "dsp-utils/functions.hpp"
#include <lv2plugin.hpp>
#include <iostream>

#define DELAY_PORT_INDEX 0
#define INPUT_PORT_INDEX 1
#define OUTPUT_PORT_INDEX 2

class delay : public LV2::Plugin<delay>
{
private:
    double sample_rate;

public:
    delay(double sample_rate) : LV2::Plugin<delay>(3)
    { // since there are 3 ports
        this->sample_rate = sample_rate;
        std::cout << "\nsample rate is: " << sample_rate << std::endl;
    };

    void run(uint32_t sample_count)
    {
        std::cout << "called run" << std::endl;
        for (size_t i = 0; i < sample_count; i++)
        {
            p(OUTPUT_PORT_INDEX)[i] = p(INPUT_PORT_INDEX)[i];
        }
    }
};
unsigned _ = delay::register_class("https://github.com/moltenot/lv2-delay");