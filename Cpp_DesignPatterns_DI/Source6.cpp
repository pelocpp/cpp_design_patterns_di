#include <iostream>
#include "Hypodermic/Hypodermic.h"

namespace Hypodermic_Test_06 {

    // demonstrating nested resolution

    class IA {
    public:
        virtual void sayHelloFromA() = 0;
    };

    class A : public IA {
    public:
        A() { std::cout << "c'tor A" << std::endl; }

        void sayHelloFromA() override { std::cout << "Say Hello from A" << std::endl; }
    };

    class IB {
    public:
        virtual void sayHelloFromB() = 0;
    };

    class B : public IB
    {
    private:
        std::shared_ptr< IA > m_ia;

    public:
        explicit B(std::shared_ptr<IA> ia) : m_ia(ia) { std::cout << "c'tor B" << std::endl; }

        void sayHelloFromB() override { 
            m_ia->sayHelloFromA();
            std::cout << "Say Hello from B" << std::endl;
        }
    };

    class IC {
    public:
        virtual void sayHelloFromC() = 0;
    };

    class C : public IC
    {
    private:
        std::shared_ptr<IB> m_ib;

    public:
        explicit C(std::shared_ptr<IB> ib) : m_ib(ib) { std::cout <<"c'tor C" << std::endl; }

        void sayHelloFromC() override {
            m_ib->sayHelloFromB();
            std::cout << "Say Hello from C" << std::endl; 
        }
    };
}

void test_hypodermic_06() {

    using namespace Hypodermic_Test_06;

    std::cout << "Test 06:" << std::endl;

    try
    {
        Hypodermic::ContainerBuilder builder;
        builder.registerType<A>().as<IA>();
        builder.registerType<B>().as<IB>();
        builder.registerType<C>().as<IC>();
        std::shared_ptr<Hypodermic::Container> container = builder.build();

        std::shared_ptr<IC> pIC = container->resolve<IC>();
        pIC->sayHelloFromC();
    }
    catch (std::exception ex) {
        std::cout << ex.what() << std::endl;
    }

    std::cout << "Done." << std::endl;
}
