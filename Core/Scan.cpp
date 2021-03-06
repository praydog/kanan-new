#include "Pattern.hpp"
#include "String.hpp"
#include "Module.hpp"
#include "Scan.hpp"

using namespace std;

namespace kanan {
    optional<uintptr_t> scan(const string& module, const string& pattern) {
        return scan(GetModuleHandle(widen(module).c_str()), pattern);
    }

    optional<uintptr_t> scan(HMODULE module, const string& pattern) {
        return scan((uintptr_t)module, getModuleSize(module).value_or(0), pattern);
    }

    optional<uintptr_t> scan(uintptr_t start, size_t length, const string& pattern) {
        if (start == 0 || length == 0) {
            return {};
        }

        Pattern p{ pattern };

        return p.find(start, length);
    }
}
