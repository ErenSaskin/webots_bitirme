#include "location.hpp"

class LocationLimit
{
private:
    Location *upper_limit, *lower_limit;

public:
    LocationLimit(Location *upper, Location *lower);
    ~LocationLimit();

    bool IsInside(Location loc)
    {
        return true;
    }

    LocationLimit Copy()
    {
        return LocationLimit(upper_limit, lower_limit);
    }
    friend std::ostream &operator<<(std::ostream &os, const LocationLimit &lt);
};

std::ostream &operator<<(std::ostream &os, const LocationLimit &lt)
{
    os << lt.upper_limit;
    return os;
}

LocationLimit::LocationLimit(Location *upper_limit, Location *lower_limit)
{
    this->upper_limit = upper_limit;
    this->lower_limit = lower_limit;
}

LocationLimit::~LocationLimit()
{
    delete upper_limit;
    delete lower_limit;
}