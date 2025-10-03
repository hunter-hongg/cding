#include <iostream>
#include <cgstdErr.hpp>
int main() {
    using namespace cding;
    throw Err::RuntimeErr();
    return 0;
}
