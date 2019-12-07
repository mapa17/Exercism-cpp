#include <stdexcept>
#include "say.h"
#include <boost/algorithm/string.hpp>
#include <boost/format.hpp>
#include <iostream>
#include <algorithm>

using namespace std;
using namespace boost;

namespace say {

    std::map<unsigned long long int, std::string> num999 = 
        {
        {1, "one"},
        {2, "two"},
        {3, "three"},
        {4, "four"},
        {5, "five"},
        {6, "six"},
        {7, "seven"},
        {8, "eight"},
        {9, "nine"},
        {10, "ten"},
        {11, "eleven"},
        {12, "twelve"},
        {13, "thirdteen"},
        {14, "fourteen"},
        {15, "fifteen"},
        {16, "sixteen"},
        {17, "seventeen"},
        {18, "eighteen"},
        {19, "nineteen"},
        {20, "twenty"},
        {30, "thirty"},
        {40, "forty"},
        {50, "fifty"},
        {60, "sixty"},
        {70, "seventy"},
        {80, "eighty"},
        {90, "ninety"},
        };

    string in_english_999(int num){
        if(num > 999)
            throw domain_error("");
        if(num == 0)
            return "zero";

        string result = "";
        auto it = num999.find(num);
        if(it == num999.end()){
            int h = int(num/100);
            int d = int((num%100)/10)*10;
            int s = num % 10;

            string hs = "";
            if(num >= 100){
                hs = num999[h] + " hundred";
            }
            string ds = num999[d];
            string ss = num999[s];

            result += hs;
            result += " " + ds;
            if(ss != ""){
                result += "-" + ss;
            }

            algorithm::trim(result);
            //cout << format("num: %d,  h=%d d=%d s=%d -> %s\n") % num % h % d % s % result;
        } else {
            result = it->second;
        }
        return result;
    }

    string in_english(unsigned long long num){
        if(num >= 1e+12){
            throw domain_error("");
        }
        int rest;
        int thousand;
        int million;
        int billion;
        unsigned long long r;
        
        billion = int(num / 1e9);
        r = num % int(1e9);
        million = int(r / 1e6);
        r = r % int(1e6);
        thousand = r / int(1e3);
        rest = num%1000;
        //cout << format("snum: %d, r %d, t %d, m %d, b %d\n") % num % rest % thousand % million % billion;

        string result = "";
        if(billion > 0){
            result += in_english_999(billion) + " billion";
        }
        if(million > 0){
            result += " " + in_english_999(million) + " million";
        }
         if(thousand > 0){
            result += " " +in_english_999(thousand) + " thousand";
        }
        if((result == "") or (rest > 0))
           result += " " + in_english_999(rest);

        algorithm::trim(result); 
        return result;
    }
}