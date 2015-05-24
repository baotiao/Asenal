#include <slice.h>

namespace ld {
    bool Slice::starts_with(const Slice& rhs) const
    {
        return (size_ >= rhs.size_) && (memcmp(data_, rhs.data(), rhs.size_) == 0);
    }



}
