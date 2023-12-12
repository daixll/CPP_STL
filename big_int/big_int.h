#pragma once
#include <string>

namespace jiao{

class big_int{

public:
    big_int():
        _num_str("0"), _num_ll(0){};
    big_int(const big_int& val):
        _num_str(val._num_str), _num_ll(val._num_ll){};
    big_int(const long long int& val):
        _num_str(std::to_string(val)), _num_ll(val){};
    big_int(const std::string& val):
        _num_str(val), _num_ll(std::stoll(val)){};
    big_int(const char* val):
        _num_str(val), _num_ll(std::stoll(val)){};

    const big_int     big() const { return *this;   };
    const long long   ll()  const { return _num_ll; };
    const std::string str() const { return _num_str;};

private:
    std::string     _num_str;
    long long int   _num_ll;
};




}
