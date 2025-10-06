#pragma once
#include <string>
namespace cding {
namespace Err {
class TempErr{
public:
    TempErr() { errmsg = "" ; }
    TempErr(std::string t) { errmsg = t ; }
    std::string what() { return errmsg ; }
protected:
    std::string errmsg;
}; // 模板错误
class RuntimeErr: public TempErr { }; // 运行时错误
class User1Err: public TempErr { }; // 用户错误1
class User2Err: public TempErr { }; // 用户错误2
}
}
