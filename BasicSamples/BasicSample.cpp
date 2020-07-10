#include <iostream>
#include <string>

// Control Over the Dependent Object Creation

class B {
public:
    B() = default;

    void someMethod() {
        //doing something..
    }
};

#if 0
class A
{
private:
    B* m_b;

public:
    A()
    {
        m_b = new B();
    }

    void Task1() {
        // do something here ...
        m_b->someMethod();
        // do something here ...
    }
};
#endif

// Alternativ: IoC Principle

class Factory
{
public:
    static B* GetObjectOfB()
    {
        return new B();
    }
}; 

class A
{
private:
    B* m_b;

public:
    A()
    {
        m_b = Factory::GetObjectOfB();
    }

    void Task1() {
        // do something here ...
        m_b->someMethod();
        // do something here ...
    }
};

// ==========================================================

class DataAccess
{
public:
    DataAccess() = default;

    std::string GetCustomerName(int id) {
        return "John Miller"; // get it from DB in real app
    }
};


#if 0
class CustomerBusinessLogic
{
private:
    DataAccess* m_dataAccess;

public:
    CustomerBusinessLogic()
    {
        m_dataAccess = new DataAccess();
    }

    std::string GetCustomerName(int id)
    {
        return m_dataAccess->GetCustomerName(id);
    }
};
#endif

// ==========================================================

class DataAccessFactory
{
public:
    static DataAccess* GetDataAccessObj()
    {
        return new DataAccess();
    }
};

class CustomerBusinessLogic
{
private:
    DataAccess* m_dataAccess;

public:
    CustomerBusinessLogic()
    {
        m_dataAccess = new DataAccess();
    }

    std::string GetCustomerName(int id)
    {
        DataAccess* dataAccess = DataAccessFactory::GetDataAccessObj();
        return dataAccess->GetCustomerName(id);
    }
};

// ==========================================================

class ICustomerDataAccess
{
public:
    virtual std::string GetCustomerName(int id) = 0;
};

class CustomerDataAccess : public ICustomerDataAccess
{
public:
    CustomerDataAccess() = default;

    std::string GetCustomerName(int id) {
        return "Dummy Customer Name"; // get it from DB in real app
    }
};


class DataAccessFactory2
{
public:
    static ICustomerDataAccess* GetCustomerDataAccessObj()
    {
        return new CustomerDataAccess();
    }
};

class CustomerBusinessLogic2
{
private:
    ICustomerDataAccess* m_custDataAccess;

public:
    CustomerBusinessLogic2()
    {
        m_custDataAccess = DataAccessFactory2::GetCustomerDataAccessObj();
    }

    std::string GetCustomerName(int id)
    {
        return m_custDataAccess->GetCustomerName(id);
    }
};

// ==========================================================
