#ifndef IO_HPP
#define IO_HPP

/**
 * This file provides effective Input/Output facilities.
 */

namespace algo {

/*
 *The following definitions are for read() function, which takes a number of arguments (from 1 to 10)
 *with "pointer to a primitive" type, and reads data from stdIn.
 */

#define read_template(...) template<__VA_ARGS__> void read
#define tn typename

read_template(tn A)(A a);
read_template(tn A, tn B)(A a, B b)
{ read(a), read(b); }
read_template(tn A, tn B, tn C)(A a, B b, C c)
{ read(a), read(b), read(c); }
read_template(tn A, tn B, tn C, tn D)(A a, B b, C c, D d)
{ read(a), read(b), read(c), read(d); }
read_template(tn A, tn B, tn C, tn D, tn E)(A a, B b, C c, D d, E e)
{ read(a), read(b), read(c), read(d), read(e); }
read_template(tn A, tn B, tn C, tn D, tn E, tn F)(A a, B b, C c, D d, E e, F f)
{ read(a), read(b), read(c), read(d), read(e), read(f); }
read_template(tn A, tn B, tn C, tn D, tn E, tn F, tn G)(A a, B b, C c, D d, E e, F f, G g)
{ read(a), read(b), read(c), read(d), read(e), read(f), read(g); }
read_template(tn A, tn B, tn C, tn D, tn E, tn F, tn G, tn H)(A a, B b, C c, D d, E e, F f, G g, H h)
{ read(a), read(b), read(c), read(d), read(e), read(f), read(g), read(h); }
read_template(tn A, tn B, tn C, tn D, tn E, tn F, tn G, tn H, tn I)(A a, B b, C c, D d, E e, F f, G g, H h, I i)
{ read(a), read(b), read(c), read(d), read(e), read(f), read(g), read(h), read(i); }
read_template(tn A, tn B, tn C, tn D, tn E, tn F, tn G, tn H, tn I, tn J)(A a, B b, C c, D d, E e, F f, G g, H h, I i, J j)
{ read(a), read(b), read(c), read(d), read(e), read(f), read(g), read(h), read(i), read(j); }

#undef read_template
#undef tn

}

#endif // IO_HPP
