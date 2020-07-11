#include <iostream>
#include "Hypodermic/Hypodermic.h"

/*
 * registerType supports 'single instance' and the opposite behaviour
 */

namespace Hypodermic_Test_02 {

    class IMessageSerializer
    {
    public:
        virtual ~IMessageSerializer() = default;
        virtual void serialize(const std::string& message, std::ostream& stream) = 0;
    };

    class LengthPrefixedMessageSerializer : public IMessageSerializer
    {
    public:
        LengthPrefixedMessageSerializer() {
            std::cout << "c'tor LengthPrefixedMessageSerializer" << std::endl;
        }

        ~LengthPrefixedMessageSerializer() {
            std::cout << "d'tor LengthPrefixedMessageSerializer" << std::endl;
        }

        void serialize(const std::string& message, std::ostream& stream) override
        {
            stream << message.size();
            stream << std::string(" - ");
            stream << message;
        }
    };

    class IMessageWriter
    {
    public:
        virtual ~IMessageWriter() = default;
        virtual void write(const std::string& message) = 0;
    };


    class ConsoleMessageWriter : public IMessageWriter
    {
    public:
        explicit ConsoleMessageWriter(std::shared_ptr<IMessageSerializer> serializer)
            : m_serializer(serializer) {
            std::cout << "c'tor ConsoleMessageWriter" << std::endl;
        }

        ~ConsoleMessageWriter() {
            std::cout << "d'tor ConsoleMessageWriter" << std::endl;
        }

        void write(const std::string& message) override
        {
            m_serializer->serialize(message, std::cout);
            std::cout << std::endl;
        }

    private:
        std::shared_ptr< IMessageSerializer > m_serializer;
    };
}

void test_hypodermic_02() {

    using namespace Hypodermic_Test_02;

    std::cout << "Test 02:" << std::endl;

    try
    {
        // Components are registered in a ContainerBuilder
        Hypodermic::ContainerBuilder builder;

        // note feature of 'Shared Instances':
        // builder.registerType<LengthPrefixedMessageSerializer>().as< IMessageSerializer >().singleInstance();  // <== remove line comment
        builder.registerType<LengthPrefixedMessageSerializer>().as< IMessageSerializer >();
        builder.registerType<ConsoleMessageWriter>().as< IMessageWriter >();

        // Actually build the `Container` we have just configured.
        std::shared_ptr<Hypodermic::Container> container = builder.build();

        // Container, give us an instance of `IMessageWriter`.
        std::shared_ptr<IMessageWriter> messageWriter = container->resolve<IMessageWriter>();
        messageWriter->write("ABC");
        messageWriter->write("XYZ");

        // note: a second object implementing 'IMessageWriter' is allocated
        std::shared_ptr<IMessageWriter> messageWriter2 = container->resolve<IMessageWriter>();
        messageWriter2->write("123456789");
    }
    catch (std::exception ex) {
        std::cout << ex.what() << std::endl;
    }

    std::cout << "Done." << std::endl;
}
