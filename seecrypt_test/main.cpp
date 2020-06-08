#include <iostream>
#include <factorial_test.h>
#include <list_of_names_test.h>




int main()
{


    //First we test the factorial
    std::cout<<"Sum of digits:"<<std::endl;
    auto result =  see_crypt_test::sum_of_factorial_digits(2);
    std::cout<<" for N = 2.  Expected: 2.  Computed result:"<<result<<std::endl;
    result =  see_crypt_test::sum_of_factorial_digits(3);
    std::cout<<" for N = 3.  Expected: 6.  Computed result:"<<result<<std::endl;
    result =  see_crypt_test::sum_of_factorial_digits(4);
    std::cout<<" for N = 4.  Expected: 6.  Computed result:"<<result<<std::endl;
    result =  see_crypt_test::sum_of_factorial_digits(5);
    std::cout<<" for N = 5.  Expected: 3.  Computed result:"<<result<<std::endl;


    //Now we test the  list of names

    std::cout<<"Testing the list of names. "<<std::endl;

    {
        std::cout<<"For list ";
        std::vector<std::string> names0 = { "Joana", "Maria", "ana"};
        for(auto a: names0) std::cout<<a<<" ";
        std::cout<<"  expected 1.  Got " << see_crypt_test::name_consistency_check(names0)<<std::endl;
    }

    {
        std::cout<<"For list ";
        std::vector<std::string> names0 = { "ana claudia", "maria", "ana"};
        for(auto a: names0) std::cout<<a<<" ";
        std::cout<<"  expected 0.  Got " << see_crypt_test::name_consistency_check(names0)<<std::endl;
    }

    {
        std::cout<<"For list ";
        std::vector<std::string> names0 = { "lu", "joana", "maria", "ana"};
        for(auto a: names0) std::cout<<a<<" ";
        std::cout<<"  expected 1.  Got " << see_crypt_test::name_consistency_check(names0)<<std::endl;
    }
    return 0;

}
