First  considerations for the factorial problem:

The obvious primary problem is the fact that factorial numers  may  grow to be too large to be held 
into  standard  integers that can be held into  signle identifiers.  To solve that the classic approach is to implement a big number library. The approach to  deliver this test is to implement a very simplified  big number class that supprots only multiplication by integers.  The class will hold each digit in a position  within a vector that can  be dinamically grown as it  may be needed.
The vector starts with a single digit (in the case of the test 1, since we will compute the factorial  from 1 upwards), and  when more significative digits are added the vector is expanded. The result is a representation that is akin to  little endian memory layout.

Regarding  optimizations,  besides the  classic C++ practices (avoid copies, etc..)  we   can decide to represent the digits  by  any native integer type that can hold up to value 9. That is sovled making the  class a template of the desired type. If one uses  char as the base type the result will be  a smaller memory footprint. On other hand he operation of multiplying a char  by an integer  requires  a few extra instructions in a modern  AMD64 architecture (when compared to a standard integer vs integer multiplication), since the architecture supplies only  multiplications of factors of same type. The result is a tradeoff of code size vs memory footprint. Even with a more instructions, the smaller base type is expected to  result in a better performance due to memory coherence and reduced number of  vector resize operations. The option for selecting the type was kept just for the sake of completeness.

The class was tested against the same examples given in the test description, plus a few larger values. 


Considerations for the   validation of  list names:

This problem  is in theory a simple search for a prefix strign for every pair of strings in a set. That can be optimized  by the initial observation that a string A of  size As can  only be  substring of a string B of size Bs if  Bs >= As. To optimize the search  and minimize the number of strings we compare we  start  by reordering (sort) the  list of strings by the inverse order imposed by the size of the name. That means we  get  a list with longer strings at the start.  

The algorithm compares each string withthe strings previously in the list, since only those may be big enoguh to  satisfy the condition.  From there it is simply the case of  checking if the find method of a string into another results in the position zero (indicating a prefix).

Again the function was tested against simple examples, including situations not originally presented in the examples of the test description (when a name is a no prefix substring of another).


All tests are performed in the main.cpp at the main function.