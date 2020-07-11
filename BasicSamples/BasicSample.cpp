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

// constructor injection

class CustomerBusinessLogic3
{
private:
    ICustomerDataAccess* m_custDataAccess;

public:
    CustomerBusinessLogic3(ICustomerDataAccess* custDataAccess)
    {
        m_custDataAccess = custDataAccess;
    }

    std::string ProcessCustomerData(int id)
    {
        return m_custDataAccess->GetCustomerName(id);
    }
};

class CustomerService
{
private:
    CustomerBusinessLogic3* m_customerBL;

public:
    CustomerService()
    {
        ICustomerDataAccess* iaccess = new CustomerDataAccess();
        m_customerBL = new CustomerBusinessLogic3(iaccess);
    }

    std::string GetCustomerName(int id) {
        return m_customerBL->ProcessCustomerData(id);
    }
};

// ==========================================================

// property injection

class CustomerBusinessLogic4
{
private:
    ICustomerDataAccess* m_custDataAccess;

public:
    CustomerBusinessLogic4() = default;

    void setDataAccess(ICustomerDataAccess* custDataAccess)
    {
        m_custDataAccess = custDataAccess;
    }

    std::string ProcessCustomerData(int id)
    {
        return m_custDataAccess->GetCustomerName(id);
    }
};

class CustomerService4
{
private:
    CustomerBusinessLogic4* m_customerBL;

public:
    CustomerService4()
    {
        m_customerBL = new CustomerBusinessLogic4();

        ICustomerDataAccess* iaccess = new CustomerDataAccess();
        m_customerBL->setDataAccess(iaccess);
    }

    std::string GetCustomerName(int id) {
        return m_customerBL->ProcessCustomerData(id);
    }
};

// ==========================================================

// method / interface injection

class IDataAccessDependency
{
public:
    virtual void SetDependency(ICustomerDataAccess*) = 0; 
};

class CustomerBusinessLogic5 : public IDataAccessDependency
{
private:
    ICustomerDataAccess* m_custDataAccess;

public:
    CustomerBusinessLogic5() = default;

    void SetDependency(ICustomerDataAccess* custDataAccess) override
    {
        m_custDataAccess = custDataAccess;
    }

    std::string ProcessCustomerData(int id)
    {
        return m_custDataAccess->GetCustomerName(id);
    }
};

class CustomerService5
{
private:
    CustomerBusinessLogic5* m_customerBL;

public:
    CustomerService5()
    {
        m_customerBL = new CustomerBusinessLogic5();

        ICustomerDataAccess* iaccess = new CustomerDataAccess();
        ((IDataAccessDependency*) m_customerBL)->SetDependency(iaccess);

        // can be written shorter:
        m_customerBL->SetDependency(iaccess);
    }

    std::string GetCustomerName(int id) {
        return m_customerBL->ProcessCustomerData(id);
    }
};

// ==========================================================

