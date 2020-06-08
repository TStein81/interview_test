#pragma once

#include <string>
#include <vector>
#include <algorithm>

namespace see_crypt_test
{

/*Checks if  every  element in the list is not a starting substring of other
*/
bool name_consistency_check(std::vector<std::string> &names)
{
    //Order the vector of names  by the reverse of the size of the string. That allow us
    //to only check if a name is  prefix  or not of a name  with length
    //at least enough to hold that first name. That save us some compares
    std::sort(begin(names), end(names), [](const std::string& a, const std::string& b)
    {
       return b.size() < a.size();
    });

    for(std::size_t i = 0; i< names.size(); i++)
    {
        const auto& name = names[i]; //this is the name we want to check if is a prefix of some other name
        for(std::size_t j=0; j<i; j++) //we only check strings that are larger or equal in size
        {
            const auto& candidate = names[j];
            if (candidate.find(name) == 0 )
            {
                return false;
            }
        }
    }
    return true;
}

}
