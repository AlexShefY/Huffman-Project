#include "exceptions.hpp"
#include "help_functions.hpp"
#include <algorithm>

namespace io_helpers {
    std::vector<bool> read_bytes(std::istream &stream, size_t &calc_size) {
        int size;
        stream.read(reinterpret_cast<char *>(&size), sizeof(size));
        if (stream.fail()) {
            throw Exceptions::MyException("Failed to read bytes");
        }
        uint8_t byte;
        int iter = (size + 7) / 8;
        std::vector<bool> ans;
        for (int j = 0; j < iter; j++) {
            stream.read(reinterpret_cast<char *>(&byte), sizeof(byte));
            if (stream.fail()) {
                throw Exceptions::MyException("Failed to read bytes");
            }
            calc_size += sizeof(byte);
            std::vector<int> vec(8);
            int val = static_cast<int>(byte);
            for (size_t i = 0; i < 8; i++) {
                vec[i] = val % 2;
                val /= 2;
            }
            reverse(vec.begin(), vec.end());
            size_t i = 0;
            while (size > 0 && i < vec.size()) {
                ans.push_back(vec[i]);
                size--;
                i++;
            }
        }
        return ans;
    }

    void write_bytes(std::ostream &stream, std::vector<bool> bytes, size_t &calc_size) {
        int sz = bytes.size();
        while (bytes.size() % 8 != 0) {
            bytes.push_back(0);
        }
        stream.write(reinterpret_cast<const char *>(&sz), sizeof(sz));
        if (stream.fail()) {
            throw Exceptions::MyException("Failed to write bytes");
        }
        for (size_t i = 0; i < bytes.size(); i += 8) {
            uint8_t a = 0;
            for (int j = 0; j < 8; j++) {
                a = a * 2 + bytes[i + j];
            }
            stream.write(reinterpret_cast<const char *>(&a), sizeof(a));
            if (stream.fail()) {
                throw Exceptions::MyException("Failed to write bytes");
            }
            calc_size += sizeof(a);
        }
    }
}