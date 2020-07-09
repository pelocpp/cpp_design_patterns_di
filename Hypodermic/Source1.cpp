#include <iostream>
#include "Hypodermic/Hypodermic.h"

// if same type is registered twice, the last one wins

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
            : m_serializer(serializer) {}

        void write(const std::string& message) override
        {
            m_serializer->serialize(message, std::cout);
        }

    private:
        std::shared_ptr< IMessageSerializer > m_serializer;
    };

    class ConsoleMessageWriterNewLine : public IMessageWriter
    {
    public:
        explicit ConsoleMessageWriterNewLine(std::shared_ptr<IMessageSerializer> serializer)
            : m_serializer(serializer) {}

        void write(const std::string& message) override
        {
            m_serializer->serialize(message, std::cout);
            std::cout << std::endl;
        }

    private:
        std::shared_ptr< IMessageSerializer > m_serializer;
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
        // I want you to use this implementation.

        // builder.registerType<LengthPrefixedMessageSerializer>();
        builder.registerType<LengthPrefixedMessageSerializer>().as< IMessageSerializer >();
        builder.registerType<ConsoleMessageWriter>().as< IMessageWriter >();
        builder.registerType<ConsoleMessageWriterNewLine>().as< IMessageWriter >();

        builder.validate();

        // Actually build the `Container` we have just configured.
        std::shared_ptr<Hypodermic::Container> container = builder.build();

        // Container, give us an instance of `IMessageWriter`.
        std::shared_ptr<IMessageWriter> messageWriter = container->resolve<IMessageWriter>();

        // Alright then, we can write some message.
        messageWriter->write("Abc");
        messageWriter->write("Defghi");
        messageWriter->write("Ghifsdsfs");
    }
    catch (std::exception ex) {
        std::cout << ex.what() << std::endl;
    }


}
