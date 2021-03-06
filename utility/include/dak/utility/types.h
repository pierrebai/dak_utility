#pragma once

#ifndef DAK_UTILITY_TYPES_H
#define DAK_UTILITY_TYPES_H

#include <cstdint>
#include <string>

namespace dak::utility
{
   //////////////////////////////////////////////////////////////////////////
   //
   // Basic types.

   typedef int8_t          int8_t;
   typedef int16_t         int16_t;
   typedef int32_t         int32_t;
   typedef int64_t         int64;
   typedef uint8_t         byte_t;
   typedef uint16_t        uint16_t;
   typedef uint32_t        uint32_t;
   typedef uint64_t        uint64_t;
   typedef std::wstring    text_t;
   typedef const wchar_t*  str_ptr_t;

}


#define USING_DAK_UTILITY_TYPES     \
   using dak::utility::int8_t;      \
   using dak::utility::int16_t;     \
   using dak::utility::int32_t;     \
   using dak::utility::int64;       \
   using dak::utility::byte_t;      \
   using dak::utility::uint16_t;    \
   using dak::utility::uint32_t;    \
   using dak::utility::uint64_t;    \
   using dak::utility::text_t;      \
   using dak::utility::str_ptr_t


#endif /* DAK_UTILITY_TYPES_H */
