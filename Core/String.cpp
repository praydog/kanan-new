#include <cstdarg>

#include <Windows.h>

#include "String.hpp"

using namespace std;

namespace kanan {
    string narrow(const wstring& str) {
        auto length = WideCharToMultiByte(CP_UTF8, 0, str.c_str(), (int)str.length(), nullptr, 0, nullptr, nullptr);
        string narrowStr{};

        narrowStr.resize(length);
        WideCharToMultiByte(CP_UTF8, 0, str.c_str(), (int)str.length(), (LPSTR)narrowStr.c_str(), length, nullptr, nullptr);

        return narrowStr;
    }

    wstring widen(const string& str) {
        auto length = MultiByteToWideChar(CP_UTF8, 0, str.c_str(), (int)str.length(), nullptr, 0);
        wstring wideStr{};

        wideStr.resize(length);
        MultiByteToWideChar(CP_UTF8, 0, str.c_str(), (int)str.length(), (LPWSTR)wideStr.c_str(), length);

        return wideStr;
    }

    string formatString(const char* format, va_list args) {
        va_list argsCopy{};

        va_copy(argsCopy, args);

        auto len = vsnprintf(nullptr, 0, format, argsCopy);

        va_end(argsCopy);

        if (len <= 0) {
            return {};
        }

        string buffer{};

        buffer.resize(len + 1, 0);
        vsnprintf(buffer.data(), buffer.size(), format, args);
        buffer.resize(buffer.size() - 1); // Removes the extra 0 vsnprintf adds.

        return buffer;
    }
}