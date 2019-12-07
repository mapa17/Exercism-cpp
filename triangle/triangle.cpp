#include "triangle.h"
#include <stdexcept>

namespace triangle {
    flavor kind(float a, float b, float c){

        if(a < 0.0 | b < 0.0 | c < 0.0){
            throw std::domain_error("Negative lengths are note allowed");
        }

        float sum = a + b + c;
        if(sum == 0.0){
            throw std::domain_error("No zero length allowed");
        }

        bool ab = a == b;
        bool ac = a == c;
        bool bc = b == c;

        // Are all sides of the same length?
        if(ab & ac & bc){
            return flavor::equilateral;
        }

        // Check if triangle inequality holds
        bool t1 = + a + b - c < 0;
        bool t2 = + a - b + c < 0;
        bool t3 = - a + b + c < 0;

        if(t1 | t2 | t3){
            throw std::domain_error("Broken triangle inequality");
        }

        // Are two of them of the same length?
        if(ab | ac | bc){
            return flavor::isosceles;
        }

        return flavor::scalene;
    }
}  // namespace triangle
