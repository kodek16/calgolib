#ifndef _EXTLIB_IO_H
#define _EXTLIB_IO_H

namespace ext {

template <typename First, typename... Rest>
void read(First& first, Rest&... rest);

//template <typename First, typename... Rest>
//void write(First first, Rest rest);

//Rest
template <>
void read<int> (int& x);

};

#endif