#ifndef __TEST__ALLOC__
#define __TEST__ALLOC__

#include <new>          // for placement new
#include <cstddef>      // for ptrdiff_t, size_t
#include <cstdlib>      // for exit()
#include <climits>      // for UINT_MAX
#include <iostream>     // for cerr

namespace TEST_ALLOC
{
    template <class T>
    inline T* __allocate(ptrdiff_t size, T*) {
        T* tmp = (T*) (::operator new((size_t)(size * sizeof(T))));
        if(tmp == 0) {
            std:: cout << "out of memory" << std::endl;
            exit(1);
        }
        return tmp;
    }

    template <class T>
    inline void __deallocate(T* buffer) {
        ::operator delete(buffer);
    }

    template <class T1, class T2>
    inline void __construct(T1* p, const T2& value) {
        new (p)T1(value); //placement new. invoke ctor of T1
    }

    template <class T>
    inline void __destroy(T* ptr) {
        ptr->~T();
    }

    template <class T>
    class allocator {
    public:
        typedef T           value_type;
        typedef T*          pointer;
        typedef const T*    const_pointer;
        typedef T&          reference;
        typedef const T&    const_reference;
        typedef size_t      size_type;
        typedef ptrdiff_t   difference_type;

        //rebind allocator of type U
        template <class U>
        struct rebind {
            typedef allocator<U> other;
        };

        pointer allocate(size_type n, const void* hint = 0) {
            return __allocate((difference_type)n, (pointer)0);
        }

        void deallocate(pointer p, size_type n) {
            __deallocate(p);
        }

        void construct(pointer p, const T& value) {
            __construct(p, value);
        }

        void destroy(pointer p) {
            __destroy(p);
        }

        pointer address(reference x) {
            return (pointer)&x;
        }

        const_pointer const_address(const_reference x) {
            return (const_reference)&x;
        }

        size_type max_size() const {
            return size_type(UINT_MAX/sizeof(T));
        }
    };
}

#endif