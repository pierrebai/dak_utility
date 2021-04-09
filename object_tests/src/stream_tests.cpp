#include "CppUnitTest.h"

#include "dak/object/stream.h"
#include "dak/object/transaction.h"
#include "dak/object/tests/helpers.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace std;

namespace dak::object::tests
{		
   TEST_CLASS(stream_tests)
   {
      public:

      TEST_METHOD(stream_base)
      {
         wstringstream ss;

         ss.clear();
         ss.str(L"");
         ss << namer_t(voc::get_root()) << voc::rock;
         Assert::AreEqual(text_t(L"rock"), ss.str());

         ss.clear();
         ss.str(L"");
         dict_t d1;
         ss << namer_t(voc::get_root()) << d1;
         Assert::AreEqual(text_t(L"{\n}"), ss.str());

         ss.clear();
         ss.str(L"");
         dict_t d2;
         d2[voc::rock] = 3;
         ss << namer_t(voc::get_root()) << d2;
         Assert::AreEqual(text_t(L"{\nrock : 3 ,\n}"), ss.str());

         ss.clear();
         ss.str(L"");
         array_t a1;
         ss << namer_t(voc::get_root()) << a1;
         Assert::AreEqual(text_t(L"[\n]"), ss.str());

         ss.clear();
         ss.str(L"");
         array_t a2;
         a2.grow() = 3;
         a2.grow() = 5;
         a2.grow() = 7;
         ss << namer_t(voc::get_root()) << a2;
         Assert::AreEqual(text_t(L"[\n3 ,\n5 ,\n7 ,\n]"), ss.str());

         ss.clear();
         ss.str(L"");
         auto o1 = object_t::make();
         auto o2 = object_t::make();
         {
            commited_transactions_t undo_redo;
            transaction_t tr1;

            auto mo1 = o1->modify(tr1);
            mo1->get(voc::child) = o2;

            auto mo2 = o2->modify(tr1);
            array_t& a3 = mo2->get(voc::after);

            a3[0] = true;
            a3[1] = o1;
            a3[2] = ref_t<const object_t>();

            tr1.commit(undo_redo);
         }
         ss << namer_t(voc::get_root()) << o1;
         Assert::AreEqual(text_t(L"ref 1 {\nchild : ref 2 {\nafter : [\n1 ,\nref -1 ,\nref 0 ,\n] ,\n} ,\n}"), ss.str());
      }
   };
}