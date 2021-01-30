#include <CppUnitTest.h>

#include <dak/any_op/all.h>
#include <dak/any_op/tests/helpers.h>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace dak::any_op;

namespace dak::any_op::tests
{		
   TEST_CLASS(compare_op_tests)
	{
	public:
      TEST_METHOD(compare_equal_test)
      {
         const std::any e_u;
         const std::any e_t1(text_t(L"text_t"));
         const std::any e_t2(L"strptr");
         const std::any e_c1('c');
         const std::any e_c2(L'w');
         const std::any e_b(true);
         const std::any e_i2((int16_t)2);
         const std::any e_i1((int32_t)1);
         const std::any e_i3((int64_t)3);
         const std::any e_u1((uint16_t)4u);
         const std::any e_u2((uint32_t)5u);
         const std::any e_u3((uint64_t)6u);
         const std::any e_r1(7.0f);
         const std::any e_r2(8.0);

         Assert::AreEqual(compare(std::any(), e_u), comparison_t::equal);
         Assert::AreEqual(compare(text_t(L"text_t"), e_t1), comparison_t::equal);
         Assert::AreEqual(compare(L"strptr", e_t2), comparison_t::equal);
         Assert::AreEqual(compare('c', e_c1), comparison_t::equal);
         Assert::AreEqual(compare(L'w', e_c2), comparison_t::equal);
         Assert::AreEqual(compare(true, e_b), comparison_t::equal);
         Assert::AreEqual(compare((int16_t)2, e_i2), comparison_t::equal);
         Assert::AreEqual(compare((int32_t)1, e_i1), comparison_t::equal);
         Assert::AreEqual(compare((int64_t)3, e_i3), comparison_t::equal);
         Assert::AreEqual(compare((uint16_t)4u, e_u1), comparison_t::equal);
         Assert::AreEqual(compare((uint32_t)5u, e_u2), comparison_t::equal);
         Assert::AreEqual(compare((uint64_t)6u, e_u3), comparison_t::equal);
         Assert::AreEqual(compare(7.0f, e_r1), comparison_t::equal);
         Assert::AreEqual(compare(8.0, e_r2), comparison_t::equal);
      }
   };
}
