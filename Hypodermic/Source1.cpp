#include <iostream>
#include "Hypodermic/Hypodermic.h"

/*
 * If same type is registered twice, the last one wins
 */

namespace Hypodermic_Test_01 {

    class IMessageSerializer
    {
    public:
        virtual ~IMessageSerializer() = default;
        virtual void serialize(const std::string& message, std::ostream& stream) = 0;
    };

    class LengthPrefixedMessageSerializer : public IMessageSerializer
    {
    public:
        virtual void serialize(const std::string& message, std::ostream& stream) override
        {
            stream << message.size();
            stream << std::string(" - ");
            stream << message;
            stream << std::string(" ");
        }
    };

    class IMessageWriter
    {
    public:
        virtual ~IMessageWriter() = default;
        virtual void write(const std::string& message) = 0;
    };

    // First implementation of interface 'IMessageWriter'
    class ConsoleMessageWriter : public IMessageWriter
    {
    public:
        explicit ConsoleMessageWriter(std::shared_ptr<IMessageSerializer> serializer)
            : m_serializer{ serializer } {}

        virtual void write(const std::string& message) override
        {
            m_serializer->serialize(message, std::cout);
        }

    private:
        std::shared_ptr<IMessageSerializer> m_serializer;
    };

    // A second implementation of interface 'IMessageWriter'
    class ConsoleMessageWriterNewLine : public IMessageWriter
    {
    public:
        explicit ConsoleMessageWriterNewLine(std::shared_ptr<IMessageSerializer> serializer)
            : m_serializer(serializer) {}

        virtual void write(const std::string& message) override
        {
            m_serializer->serialize(message, std::cout);
            std::cout << std::endl;
        }

    private:
        std::shared_ptr<IMessageSerializer> m_serializer;
    };
}

void test_hypodermic_01() {

    using namespace Hypodermic_Test_01;

    std::cout << "Test 01:" << std::endl;

    try
    {
        // Components are registered in a ContainerBuilder
        Hypodermic::ContainerBuilder builder;

        // What we say here is: when I need an IMessageSerializer,
        // I want you to use this implementation

        builder.registerType<LengthPrefixedMessageSerializer>().as<IMessageSerializer>();
        builder.registerType<ConsoleMessageWriter>().as<IMessageWriter>();
        builder.registerType<ConsoleMessageWriterNewLine>().as<IMessageWriter>();  // <== put this line into comment

        builder.validate();

        // actually build the `Container` we have just configured
        std::shared_ptr<Hypodermic::Container> container{ 
            builder.build() 
        };

        // Container, give us an instance of `IMessageWriter`
        std::shared_ptr<IMessageWriter> messageWriter{
            container->resolve<IMessageWriter>() 
        };

        messageWriter->write("123");
        messageWriter->write("456");
        messageWriter->write("789");
    }
    catch (std::exception ex) {
        std::cout << ex.what() << std::endl;
    }
}
