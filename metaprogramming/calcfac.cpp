#include <iostream>
template<unsigned int n>
struct factorial
{
enum
{
        value = n * factorial<n - 1>::value
    };
};
template<>
struct factorial<0>
{
    enum { value = 1 };
};
int main() {
    std::cout << factorial<7>::value << std::endl;
// prints "5040"
}

// factorial is a struct, but in template metaprogramming it is treated as a template metafunction. 
// By convention, template metafunctions are evaluated by checking a particular member, either ::type for metafunctions that result in types, 
// or ::value for metafunctions that generate values.
// In the above code, we evaluate the factorial metafunction by instantiating the template with the parameters we want to pass, 
// and using ::value to get the result of the evaluation.
