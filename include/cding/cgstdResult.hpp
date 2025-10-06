#pragma once
#include "cgstdErr.hpp"

namespace cding {
namespace Result {
class ResultErr: public TempErr {}; // Result相关错误
template<typename T, typename E>
class Result {
public: 
    Result(T val1){ valo = val1 ; state = State::Ok ; }
    Result(E val2){ vale = val2 ; state = State::Err ;  }
    T unwrap(){
        if ( state == State::Ok ) {
            return valo;
        }
        throw ResultErr("对状态Err的Result调用unwrap");
    }
private: 
    enum class State {
        Ok, 
        Err, 
    } state;
    T valo;
    E vale;
};
}
}
