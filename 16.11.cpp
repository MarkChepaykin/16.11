#include <iostream>
#include <string>
#include <stdexcept>

int main() {
    auto is_num = [](const std::string& str) -> bool {
        try {
            size_t pos;
            std::stod(str, &pos);
            return pos == str.length();
        }
        catch (std::invalid_argument const& e) {
            return false;
        }
        catch (std::out_of_range const& e) {
            return false;
        }
    };

    // Примеры использования
    std::cout << std::boolalpha;
    std::cout << "123: " << is_num("123") << std::endl;
    std::cout << "12.3: " << is_num("12.3") << std::endl;
    std::cout << "abc: " << is_num("abc") << std::endl;
    std::cout << "12.3abc: " << is_num("12.3abc") << std::endl;

    return 0;
}
