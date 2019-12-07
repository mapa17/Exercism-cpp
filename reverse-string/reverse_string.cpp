#include "reverse_string.h"
//#include <boost/algorithm/string.hpp>

using namespace std;
//using namespace boost::algorithm;


namespace reverse_string {

    /*
    std::string reverse_string(std::string ostring){
        std::string rstring={};
        for (std::string::reverse_iterator rit=ostring.rbegin(); rit!=ostring.rend(); ++rit)
            rstring += *rit;
        return rstring;
    }
    */
   /*
    string reverse_string(string ostring){
        string rstring = {};
        for(int i = ostring.length(); i>0; i--){
            rstring += ostring[i-1];
        }
        return rstring;
    }
    */
    string reverse_string(string ostring){
        std::reverse(std::begin(ostring), std::end(ostring));
        return ostring;
    }
}  // namespace reverse_string
