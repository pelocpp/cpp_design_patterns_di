#include <iostream>
#include <memory>
#include "Hypodermic/Hypodermic.h"

namespace Hypodermic_Test_00 {

    /*
     * Testing Hypodermic
     */

     // we provide an abstraction for the serializer since we only
     // need to know that we want to serialize a message in a stream
    class IMessageSerializer
    {
    public:
        virtual ~IMessageSerializer() = default;
        virtual void serialize(const std::string& message, std::ostream& stream) = 0;
    };

    // we implement a basic serializer which will write the length of
    // the message before writing the message itself
    class LengthPrefixedMessageSerializer : public IMessageSerializer
    {
    public:
        void serialize(const std::string& message, std::ostream& stream) override
        {
            stream << message.size();
            stream << message;
        }
    };

    // the abstraction of a writer tells us that we can pass this
    // object a message and it will do the job of writing it somewhere
    class IMessageWriter
    {
    public:
        virtual ~IMessageWriter() = default;
        virtual void write(const std::string& message) = 0;
    };

    // we implement a writer that will be responsible for serializing
    // the messages in the console
    // Note the constructor: You can see it is injected a serializer :-)
    class ConsoleMessageWriter : public IMessageWriter
    {
    public:
        explicit ConsoleMessageWriter(std::shared_ptr<IMessageSerializer> serializer)
            : m_serializer(serializer)
        {
        }

        void write(const std::string& message) override
        {
            m_serializer->serialize(message, std::cout);  // <== console output
        }

    private:
        std::shared_ptr<IMessageSerializer> m_serializer;
    };


    class Application
    {
    public:
        Application()
        {
            // components are registered in a ContainerBuilder
            Hypodermic::ContainerBuilder builder;

            // what we say here is:
            // when I need an IMessageSerializer,
            // I want you to use this implementation (class LengthPrefixedMessageSerializer)
            builder
                .registerType<LengthPrefixedMessageSerializer>()
                .as<IMessageSerializer>();

            // what we say here is:
            // when I need an IMessageWriter,
            // I want you to use this implementation (class ConsoleMessageWriter)
            builder
                .registerType<ConsoleMessageWriter>()
                .as<IMessageWriter>();

            // actually build the 'Container' we have just configured
            m_container = builder.build();
        }

        // run our test example
        void run();

    private:
        std::shared_ptr<Hypodermic::Container> m_container;
    };

    void Application::run()
    {
        // container, give us an instance of `IMessageWriter`
        std::shared_ptr<IMessageWriter> messageWriter = 
            m_container->resolve<IMessageWriter>();

        // allright, we now can write some message
        messageWriter->write("The app is running");
    }
}

void test_hypodermic_00() {

    using namespace Hypodermic_Test_00;

    Application app;
    app.run();
}
