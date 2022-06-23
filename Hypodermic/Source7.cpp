#include <iostream>
#include "Hypodermic/Hypodermic.h"

/*
 * Demonstration einer Factory für Klassen / Methode registerInstanceFactory
 */

namespace Hypodermic_Test_07 {

    class SomeConfiguration
    {
    public:
        SomeConfiguration() {
            std::cout << "c'tor SomeConfiguration" << std::endl;
        }

        ~SomeConfiguration() {
            std::cout << "d'tor SomeConfiguration" << std::endl;
        }

        void print() {
            std::cout << "I'm a configuration" << std::endl;
        }
    };
}

void test_hypodermic_07() {

    using namespace Hypodermic_Test_07;

    std::cout << "Test 07:" << std::endl;

    try
    {
        Hypodermic::ContainerBuilder builder;

        builder.registerInstanceFactory([](Hypodermic::ComponentContext& context) {
            return std::make_shared< SomeConfiguration>();
        });

        std::shared_ptr<Hypodermic::Container> container{ 
            builder.build() 
        };

        std::shared_ptr<SomeConfiguration> pConf{
            container->resolve<SomeConfiguration>() 
        };
        pConf->print();
    }
    catch (std::exception ex) {
        std::cout << ex.what() << std::endl;
    }

    std::cout << "Done." << std::endl;
}
