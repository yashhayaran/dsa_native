#include <iostream>
#include <typeinfo>

namespace Basics
{
    namespace DIAMOND_PROBLEM
    {
        class Base
        {
            protected:
            std::string _currentName;

            public: 
            Base(): _currentName("Base") { }

            public:
            virtual void Name()
            {
                std::cout << "Class: " << this->_currentName << std::endl;
            }
        };

        class Derived_1 : virtual public Base
        {
            protected:
            std::string _currentName;

            public: 
            Derived_1(): _currentName("Derived_1") { }
        };

        class Derived_2 : virtual public Base
        {
            protected:
            std::string _currentName;

            public: 
            Derived_2(): _currentName("Derived_2") { }
        };

        class Current : public Derived_1, Derived_2
        {
            public: 
            Current() {}

            void Print()
            {
                this->Name();
            }
        };
    }

    namespace TYPEID
    {
        /*
        @brief
        Used where the dynamic type of a polymorphic object must be known and for static type identification.

        @note
        If typeid is used on an object under construction or destruction (in a destructor or in a constructor, including constructor's initializer list or default member initializers), then the std::type_info object referred to by this typeid represents the class that is being constructed or destroyed even if it is not the most-derived class.

        When applied to an expression of polymorphic type, evaluation of a typeid expression may involve runtime overhead (a virtual table lookup), otherwise typeid expression is resolved at compile time.

        @link
        https://en.cppreference.com/w/cpp/language/typeid
        */
        struct Base {}; // non-polymorphic
        struct Derived : Base {};
        
        struct Base2 { virtual void foo() {} }; // polymorphic
        struct Derived2 : Base2 {};

        void example()
        {
            // Non-polymorphic lvalue is a static type
            Derived d1;
            Base& b1 = d1;
            std::cout << "reference to non-polymorphic base: " << typeid(b1).name() << '\n';
        
            Derived2 d2;
            Base2& b2 = d2;
            std::cout << "reference to polymorphic base: " << typeid(b2).name() << '\n';
        }
    }

    namespace OOPS_BASICS
    {
        class A
        {
            public: 
            A()
            {
                std::cout << "Calling A()" << std::endl;
            }
            virtual ~A()
            {
                std::cout << "Calling ~A()" << std::endl;
            }
        };

        class B : public A
        {
            public: 
            B()
            {
                std::cout << "Calling B()" << std::endl;
            }
            ~B()
            {
                std::cout << "Calling ~B()" << std::endl;
            }
        };

        class C : virtual public A
        {
            public: 
            C()
            {
                std::cout << "Calling C()" << std::endl;
            }
            ~C()
            {
                std::cout << "Calling ~C()" << std::endl;
            }
        };

        class D : public C, B
        {
            public: 
            D()
            {
                std::cout << "Calling D()" << std::endl;
            }
            ~D()
            {
                std::cout << "Calling ~D()" << std::endl;
            }
        };
        
        class Widget
        {
            protected:
            char* _pCName;
            size_t _nNameLength;
            size_t nWidgetCapacity;

            public: 
            Widget(const size_t capacity) : _pCName(nullptr), _nNameLength(0), nWidgetCapacity(capacity) {}

            Widget(const Widget &obj): _pCName(nullptr), _nNameLength(0)
            {
                std::cout << "Invoking Copy Constructor" << std::endl;
                this->SetName(obj._pCName, obj._nNameLength);
                this->nWidgetCapacity = obj.nWidgetCapacity;
            }

            void ShowCapacity()
            {
                std::cout << "Current Capacity: " << this->nWidgetCapacity << std::endl; 
            }

            void SetName(const char* pName, const size_t& size)
            {
                assert(pName != nullptr);
                assert(size);
                
                try 
                {
                    char* pMem = new char[size];
                    if (pMem != nullptr)
                    {
                        this->_pCName = pMem;
                        this->_nNameLength = size;
                    }
                    else
                    {
                        std::cout << "Couldn't allocate memory for Name";
                        assert(false);
                    }
                }
                catch(std::bad_alloc &e)
                {
                    std::cout << e.what();
                }
            }

            // Getter methods:
            Widget* GetWidget_() const
            {
                return (Widget*)this;
            }

            const Widget* GetWidget()
            {
                return this;
            }

            Widget operator+(const Widget& w2)
            {
                Widget res(this->nWidgetCapacity);

                res.nWidgetCapacity += w2.nWidgetCapacity;

                return res;
            }
        };

        void test()
        {
            Widget w1(10);
            w1.SetName("Yash", sizeof("Yash"));

            Widget w2(w1);
            Widget w3 = w1;

            Widget w4(40);
            w4.ShowCapacity();
            w2.ShowCapacity();
            Widget w5 = w2 + w4;

            w5.ShowCapacity();
        }
    }
}
