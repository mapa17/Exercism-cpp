#include "gigasecond.h"
#include "boost/date_time/posix_time/posix_time.hpp"

using namespace std;
using namespace boost;
using namespace boost::posix_time;

namespace gigasecond{
    const time_duration future = seconds(JUMP);

    ptime advance(ptime origin){
        //return ptime(origin.date(), future);
        
        ptime target(origin.date());
        return target + future;
    }
}