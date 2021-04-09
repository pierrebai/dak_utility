#pragma once

#ifndef DAK_OBJECT_REF_COUNTED_H
#define DAK_OBJECT_REF_COUNTED_H

#include <dak/utility/types.h>

#include <compare>

namespace dak::object
{
   struct ref_base_t;
   struct element_t;

   //////////////////////////////////////////////////////////////////////////
   //
   // Reference-counted objects. Support reference counting, but can also
   // be declared on the stack or embedded in another object.
   //
   // Sub-classes of ref_counted_t *must* inherit from it privately to support the
   // restriction on reference-counting vs. stack or embedded instances.

   struct ref_counted_t
   {
      constexpr std::strong_ordering operator<=>(const ref_counted_t&) const noexcept { return std::strong_ordering::equal; }
      constexpr bool operator==(const ref_counted_t&) const noexcept { return true; }

   protected:
      ref_counted_t() = default;
      ref_counted_t(const ref_counted_t &);
      ref_counted_t& operator =(const ref_counted_t &);
      virtual ~ref_counted_t() = default;

   private:
      void addref() const;
      void unref() const;

      mutable int64_t my_refcount = 0;

      friend struct ref_base_t;
      friend struct element_t;
   };
}

#endif /* DAK_OBJECT_REF_COUNTED_H */