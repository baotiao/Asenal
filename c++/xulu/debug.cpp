#include <sstream>
#include "debug.h"


using namespace std;


namespace DebugUtil {

ostream& operator<<(ostream& os, const Exception& e)
{
  return os << e.toString();
}


void assertError(const string& file, int line,
                 const string& cond)
{
  ostringstream ss;
  ss << "in " << file << ":" << line << " (" << cond << ")\n";
  throw Exception(ss.str());
}

} // end of namespace DebugUtil
