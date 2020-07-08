#include <iostream>
#include <memory>
#include "Hypodermic/Hypodermic.h"

// NOCHMaL: Wenn zweimal dasselbe Inferface registriert wird, dann kann man das beeinflussen ... mit useIfNone

namespace Hypodermic_Test_05 {

    class MyLoggerSink : public Hypodermic::ILoggerSink
    {
    public:
        void append(Hypodermic::LogLevels::LogLevel level, const std::string& message) override {
            std::cout << ">>: " << message << std::endl;
        }
    };

    class IMessageSerializer
    {
    public:
        virtual ~IMessageSerializer() = default;
        virtual void write() = 0;
    };

    class ConcreteMessageSerializer : public IMessageSerializer
    {
    public:
        void write() override
        {
            std::cout << "it's concrete" << std::endl;
        }
    };

    class NoopMessageSerializer : public IMessageSerializer
    {
    public:
        void write() override
        {
            std::cout << "it's a noop" << std::endl;
        }
    };
}

void test_hypodermic_05() {

    using namespace Hypodermic_Test_05;

    std::cout << "Test 05:" << std::endl;

    Hypodermic::Logger::configureLogLevel(Hypodermic::LogLevels::Info);
    Hypodermic::Logger::configureSink(std::make_shared<MyLoggerSink>());

    try
    {
        Hypodermic::ContainerBuilder builder;

        builder.registerType<ConcreteMessageSerializer>().as< IMessageSerializer >();
        builder.registerType<NoopMessageSerializer>().as< IMessageSerializer >().useIfNone();

        std::shared_ptr<Hypodermic::Container> container = builder.build();

        std::shared_ptr<IMessageSerializer> serializer = container->resolve<IMessageSerializer>();
        serializer->write();
    }
    catch (std::exception ex) {
        std::cout << ex.what() << std::endl;
    }

    std::cout << "Done." << std::endl;
}
