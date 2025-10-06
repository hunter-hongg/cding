#pragma once 
#include <string>
#include "cgstdErr.hpp" // 提供Err模板

namespace cding {
namespace Option {
class OptionErr: public cding::Err::TempErr {}; // Option相关的Err
template <typename T>
class Option {
protected: 
    enum class State {
        Some,
        None,
    } state ; // Option目前的状态
    T val; // Option真正的值
public: 
    Option() { state = State::None ; } // Option为空
    Option(T value) { state = State::Some ; val = value ; } // Option为非空
    bool is_some() { return ( state == State::Some ) ; } // Option是否非空
    bool is_none() { return ( state == State::None ) ; } // Option是否为空
    T unwrap() {
        if ( is_some() ) { return val; }
        throw OptionErr();
    } // 拆开Option,空则报错
    T unwrap_or(T default_) {
        if ( is_some() ) { return val; }
        return default_;
    } // 拆开Option,空则使用默认值
};
}
}
