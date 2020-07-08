#include <iostream>
#include <memory>
#include "Hypodermic/Hypodermic.h"

// Wiring the internal logging mechanism

// Wenn zweimal dasselbe Inferface registriert wird, dann stört das Hypo nicht ! 

namespace Hypodermic_Test_04 {

    class MyLoggerSink : public Hypodermic::ILoggerSink
    {
    public:
        void append(Hypodermic::LogLevels::LogLevel level, const std::string& message) override {
            std::cout << ">>: " << message << std::endl;
        }
    };

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

    class IMessageSerializer
    {
    public:
        virtual ~IMessageSerializer() = default;
    };

    class ConcreteMessageSerializer : public IMessageSerializer
    {};

    class IMessageWriter
    {
    public:
        virtual ~IMessageWriter() = default;
    };

    class Writer1 : public IMessageWriter
    {
    public:
        explicit Writer1(std::shared_ptr< IMessageSerializer > serializer) {}
    };

    class Writer2 : public IMessageWriter
    {
    public:
        explicit Writer2(std::shared_ptr< IMessageSerializer > serializer) {}
    };
}

void test_hypodermic_04() {

    using namespace Hypodermic_Test_04;

    std::cout << "Test 04:" << std::endl;

    Hypodermic::Logger::configureLogLevel(Hypodermic::LogLevels::Info);
    Hypodermic::Logger::configureSink(std::make_shared<MyLoggerSink>());

    try
    {
        Hypodermic::ContainerBuilder builder;

        builder.registerType<Writer1>().as< IMessageWriter >();
        builder.registerType<Writer1>().as< IMessageWriter >();
      //  builder.registerType<ConsoleMessageWriterNewLine>().as< IMessageWriter >();

        //std::shared_ptr<SomeConfiguration> configuration = std::make_shared<SomeConfiguration>();
        //builder.registerInstance(configuration);

        std::shared_ptr<Hypodermic::Container> container = builder.build();

        //std::shared_ptr<SomeConfiguration> resolvedConfiguration = container->resolve<SomeConfiguration>();
        //assert(resolvedConfiguration == configuration);

        //std::shared_ptr<SomeConfiguration> anotherConfiguration = container->resolve<SomeConfiguration>();
        //assert(resolvedConfiguration == anotherConfiguration);
    }
    catch (std::exception ex) {
        std::cout << ex.what() << std::endl;
    }

    std::cout << "Done." << std::endl;
}
