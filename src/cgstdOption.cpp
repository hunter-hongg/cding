#include <cgstdOption.hpp>

int main() {
    auto t = cding::Option::Option(3);
    t = cding::Option::Option<int>();
    t.unwrap_or(0);
    return 0;
}
