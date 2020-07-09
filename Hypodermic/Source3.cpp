#include <iostream>
#include "Hypodermic/Hypodermic.h"

// registerInstance normally yields 'single instance' behaviour

using namespace Hypodermic;

namespace Hypodermic_Test_03 {

    class SomeConfiguration 
    {
    public:
        SomeConfiguration() {
            std::cout << "c'tor SomeConfiguration" << std::endl;
        }

        ~SomeConfiguration() {
            std::cout << "d'tor SomeConfiguration" << std::endl;
        }
    };
}

void test_hypodermic_03() {

    using namespace Hypodermic_Test_03;

    std::cout << "Test 03:" << std::endl;

    try
    {
        ContainerBuilder builder;

        std::shared_ptr<SomeConfiguration> configuration = std::make_shared<SomeConfiguration>();
        builder.registerInstance(configuration);

        std::shared_ptr<Container> container = builder.build();

        std::shared_ptr<SomeConfiguration> resolvedConfiguration = container->resolve<SomeConfiguration>();
        assert(resolvedConfiguration == configuration);

        std::shared_ptr<SomeConfiguration> anotherConfiguration = container->resolve<SomeConfiguration>();
        assert(resolvedConfiguration == anotherConfiguration);
    }
    catch (std::exception ex) {
        std::cout << ex.what() << std::endl;
    }

    std::cout << "Done." << std::endl;
}
