#ifndef debug_h
#define debug_h

#include <string>
#include <iostream>

namespace DebugUtil {

class Exception {
  protected:
    std::string d_msg;
  public:
    Exception(): d_msg("Unknown exception") { }
    Exception(const std::string& msg): d_msg(msg) { }
    Exception(const char* msg): d_msg(msg) { }
    virtual ~Exception() { }

    void setMessage(const std::string& msg) { d_msg = msg; }
    virtual std::string toString() const { return d_msg; }
    friend std::ostream& operator<<(std::ostream& os, const Exception& e);
};

extern void assertError(const std::string& file, int line,
                        const std::string& cond);

}  // end of namespace DebugUtil

#define Assert(cond) if(!(cond)) \
    DebugUtil::assertError(__FILE__, __LINE__, #cond)

#endif
