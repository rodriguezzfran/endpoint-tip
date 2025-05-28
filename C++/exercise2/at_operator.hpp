#ifndef DECLARE_AT_HPP
#define DECLARE_AT_HPP

#include <cstdint>

/**
 * @brief Macro to declare a reference to a variable at a specific address.
 *
 * This macro allows you to create a reference to a variable located at a specific memory address.
 * volatile type& name: is a reference to a variable of type 'type' that is located at the specified
 * address. reinterpret_cast<volatile type*>(reinterpret_cast<std::uintptr_t>(address)): is used to
 * convert the address to a pointer of type 'volatile type*', and then dereference it to get a
 * reference.
 */
#define declare_at(type, name, address)                      \
    volatile type& name = *reinterpret_cast<volatile type*>( \
        reinterpret_cast<std::uintptr_t>(address))
#endif