#include <string>
#include <cstdint>
#include <stdexcept>

namespace std {

int8_t stoi8(const std::string& str) {
    int res{std::stoi(str)};

    if (res < INT8_MIN) {
        throw std::out_of_range("underflow");
    } else if (res > INT8_MAX) {
        throw std::out_of_range("overflow");
    }

    return int8_t(res);
}

int16_t stoi16(const std::string& str) {
    int res{std::stoi(str)};

    if (res < INT16_MIN) {
        throw std::out_of_range("underflow");
    } else if (res > INT16_MAX) {
        throw std::out_of_range("overflow");
    }

    return int16_t(res);

}

int32_t stoi32(const std::string& str) {
    return int32_t(std::stoi(str));
}

};
