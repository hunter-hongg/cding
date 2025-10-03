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
};
class RuntimeErr: public TempErr { };
class User1Err: public TempErr { };
class User2Err: public TempErr { };
}
}
