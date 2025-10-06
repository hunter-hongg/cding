#pragma once
#include "cgstdErr.hpp"

namespace cding {
namespace Result {
class ResultErr: public cding::Err::TempErr {}; // Result相关错误
template<typename T, typename E>
class Result {
public: 
    Result(T val1){ valo = val1 ; state = State::Ok ; }
    Result(E val2){ vale = val2 ; state = State::Err ;  }
    bool is_ok() { return state == State::Ok ; }
    bool is_err() { return (!(is_ok())) ; }
    T unwrap(){
        if ( state == State::Ok ) {
            return valo;
        }
        throw ResultErr("对状态Err的Result调用unwrap");
    }
    T unwrap_or(T val) {
        if ( state == State::Ok ) {
            return valo;
        }
        return val;
    }
    E unwrap_err() {
        if ( state != State::Ok ) {
            return vale;
        }
        throw ResultErr("对状态Ok的Result调用unwrap_err");
    }
    E unwrap_err_or(E val) {
        if ( state != State::Ok ) {
            return vale;
        }
        return val;
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
