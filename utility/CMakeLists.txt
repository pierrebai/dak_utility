
add_library(utility
   include/dak/utility/all.h
   include/dak/utility/constants.h
   include/dak/utility/containers.h
   include/dak/utility/number.h
   include/dak/utility/progress.h                  src/progress.cpp
   include/dak/utility/stream_progress.h           src/stream_progress.cpp
   include/dak/utility/multi_thread_progress.h     src/multi_thread_progress.cpp
   include/dak/utility/stopwatch.h                 src/stopwatch.cpp
   include/dak/utility/thread_pool.h               src/thread_pool.cpp
   include/dak/utility/threaded_work.h
   include/dak/utility/selection.h
   include/dak/utility/text.h                      src/text.cpp
   include/dak/utility/types.h
   include/dak/utility/undo_stack.h                src/undo_stack.cpp
)

target_include_directories(utility PUBLIC
   include
)

set_property(TARGET utility PROPERTY CXX_STANDARD 20)

