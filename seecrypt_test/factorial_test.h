#pragma once
#include <vector>
#include <numeric>
#include <algorithm>
#include <sstream>
#include <iostream>

namespace see_crypt_test
{

/*This is a VERY simplified implementation fo a big number class using base 10.
 *
 * The digits are stored in a LITTLE ENDIAN style ( least significative  digit at the start of
 * the  vector)
 * It is a parametrized template because while in theory  the char type is big enough
 * to be used  as representation for a base 10 digit, theproposed problem might demand
 * multimplication for number of a larger base (i.e int for example). Using  char as the
 * type parameter results ina smaller memory footprint, but increase the instruction count
 * of the resulting function (due to the necessity of a few extra instructions to correctly
 * cast  the  operands of a multiplication (depending obviously on the platform).

 *For a AMD-64 machine the instruction count  difference is 316 instructions for int and 400 for char

*/
template<typename TypeDigit>
struct Base10Number{

    std::vector<TypeDigit> digit_string;

public:



    void set_digit_value(std::size_t digit_index, TypeDigit digit_value)
    {
        if(digit_index+1 > digit_string.size())
        {
            digit_string.resize(digit_index+1);
        }
        digit_string[digit_index] = digit_value;
    }

    int sum_of_digits()const
    {
        return std::accumulate(begin(digit_string), end(digit_string),0);
    }

    template<typename TypeFactor>
    Base10Number& operator*=(const TypeFactor& factor)
    {
        ///We do want to limit our loop to the original number of digits in the big number
        //so that carry overs do not get multiplied
        auto size_before_operation = digit_string.size();
        auto current_carry =0;

        for(std::size_t index =0; index < size_before_operation; index++)
        {
            auto digit_mult_res = digit_string[index] * factor + current_carry;
            //we now need to update the  carry that will be used in the next digit
            current_carry = digit_mult_res / 10;  //explicit integer division
            digit_string[index] = digit_mult_res %10; //we can only store at the digit position a value from 0 to 9
        }
        //after this point we may have a surplus carry that may increase the number of digits
        // if we knew how many digits to add we could  make a direct resize to the correct size. Finding that humber
        // of digits requires although quite a few cycles.

        while( current_carry !=0)
        {

            digit_string.push_back(current_carry % 10);
            current_carry  = current_carry /10;
        }


        return *this;
    }

};//class

//Computer the factorial of a potentially big number and return the sum of its digits.
// It computes the factorial backwards
// starting with  1 and increasing the number representation as needed
int sum_of_factorial_digits(const int integer)
{

    Base10Number<int> number;
    number.set_digit_value(0,1); // we  compute the factorial backwards from 1
    for(auto i = 2; i<= integer; i++)
    {
        number*=i;
    }
    return number.sum_of_digits();

}

}//namespace
