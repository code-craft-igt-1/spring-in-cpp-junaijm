#include "stats.h"

namespace Statistics
{
    Stats ComputeStatistics(const std::vector<double>& readings) 
    {
        Stats stats;
        if(readings.empty())
        {
            stats.average = std::numeric_limits<double>::quiet_NaN();
            stats.max = std::numeric_limits<double>::quiet_NaN();
            stats.min = std::numeric_limits<double>::quiet_NaN();
        }
        else
        {
            stats.average = 0;
            stats.max = readings[0];
            stats.min = readings[0];
            for(auto reading : readings)
            {
                stats.average += reading;
                if(reading > stats.max)
                {
                    stats.max = reading;
                }
                if(reading < stats.min)
                {
                    stats.min = reading;
                }
            }
            stats.average /= readings.size();
        }
        return stats;
    }
}
