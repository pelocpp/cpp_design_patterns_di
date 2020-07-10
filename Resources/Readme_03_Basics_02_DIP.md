# Grundlagen

#### Dependency Inversion Principle

Das *Dependency Inversion Principle* ist eines der objektorientierten **SOLID**-Prinzipien,
die von *Robert Martin* (auch unter dem Begriff "Onkel Bob" gekannt) erfunden wurden.

*Definition*:

  1. Das *Dependency Inversion Principle* sagt aus, dass High-Level-Module nicht von Low-Level-Modulen abhängen sollten.
    Beide Ebenen (Klassen, Module) sollten mittels Schnittstellen abstrahiert werden.
  2. Schnittstellen sollten nicht von Details, sondern die Details sollten von den Schnittstellen abhängen.

###### Ein Beispiel

Wir fahren mit dem Beispiel aus dem letzten Abschnitt fort:

```cpp
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

class DataAccessFactory
{
public:
    static DataAccess* GetDataAccessObj()
    {
        return new DataAccess();
    }
};

class DataAccess
{
public:
    DataAccess() = default;

    std::string GetCustomerName(int id) {
        return "John Miller"; // get from the database in real application
    }
};
```

Im obigen Beispiel haben wir das *Factory*-Entwurfsmuster implementiert,
um das *Inversion of Control*-Prinzip anzuwenden.
Die `CustomerBusinessLogic`-Klasse verwendet jedoch nach wie vor die konkrete `DataAccess`-Klasse.
Daher ist sie immer noch eng gekoppelt, obwohl wir die abhängige Objekterstellung
in die `DataAccessFactory`-Klasse invertiert haben.

Wenden wir jetzt das *Dependency Inversion* Prinzip für die Klassen `CustomerBusinessLogic` und
`DataAccess` an, um eine lose Kopplung zu erzielen:

Gemäß Definition sollte ein High-Level-Modul nicht von Low-Level-Modulen abhängen.
Beide sollte von Abstraktionen abhängen.
Damit müssen wir zunächst klären, welches von beiden Modulen die Rolle des High-Level-Moduls (Klasse)
und welches das Low-Level-Modul (Klasse) ist.
Ein High-Level-Modul ist ein Modul, das von anderen Modulen abhängt.
In unserem Beispiel hängt `CustomerBusinessLogic` von der `DataAccess`-Klasse ab,
sodass `CustomerBusinessLogic` ein Modul auf höherer Ebene und `DataAccess` ein Modul
auf niedriger Ebene ist.
Nach der ersten DIP-Regel sollte `CustomerBusinessLogic` also nicht von der konkreten
`DataAccess`-Klasse abhängen, sondern beide Klassen sollten von einer Abstraktion abhängen.

###### Was ist eine Abstraktion?

Abstraktion und Kapselung sind wichtige Prinzipien der objektorientierten Programmierung.
Es gibt viele verschiedene Definitionen von verschiedenen Personen, aber lassen Sie uns die Abstraktion anhand des obigen Beispiels verstehen

Abstraktion bedeutet ganz einfach formuliert, das etwas nicht konkret ist.
In Bezug auf die Programmierung sind die oben benutzten Klassen `CustomerBusinessLogic` und `DataAccess` konkrete Klassen,
wir können Objekte von ihnen erstellen.
Abstraktion in der Programmierung bedeutet, eine Schnittstelle oder eine abstrakte Klasse zu erstellen,
die nicht konkret ist. Dies bedeutet, dass wir kein Objekt von einer Schnittstelle
oder einer abstrakten Klasse erstellen können.
Gemäß *Dependency Inversion Principle* sollte die Klasse `CustomerBusinessLogic` (High-Level-Modul)
nicht von der konkreten `DataAccess`-Klasse (Low-Level-Modul) abhängen.
Beide Klassen sollten von Abstraktionen abhängen,
das heußt, beide Klassen sollten von einer Schnittstelle oder einer abstrakten Klasse abhängig sein.

Wie könnten entsprechende Schnittstellen (abstrakte Klassen) definiert sein?
Wie wir bereits wissen, verwendet `CustomerBusinessLogic` die `GetCustomerName`-Methode
der `DataAccess`-Klasse. Es könnten weitaus mehr ähnliche, kundenbezogene Methoden sein,
die über die `DataAccess`-Klasse erreichbar sein sollten.
Deklarieren wir folglich eine Methode `GetCustomerName` in einer Schnittstelle wie folgt:

```cpp
class ICustomerDataAccess
{
public:
    virtual std::string GetCustomerName(int id) = 0;
};
```

Nun benötigen wir eine Klasse, die den Kontrakt mit der Schnittstelle `ICustomerDataAccess` eingeht,
also eine Implementierung aller Methoden dieser Schnittstelle bereitstellt.
Wir erledigen dies in einer neuen Klasse namens `CustomerDataAccess`:

```cpp
class CustomerDataAccess : public ICustomerDataAccess
{
public:
    CustomerDataAccess() = default;

    std::string GetCustomerName(int id) {
        return "Dummy Customer Name"; // get it from DB in real app
    }
};
```

Jetzt müssen wir die `Factory`-Klasse ändern, die nun den Schnittstellentyp `ICustomerDataAccess`
anstelle des konkreten Klassentyps (in unserem Beispiel: `DataAccess`) zurückgibt, wie nachstehend gezeigt.

```cpp
class DataAccessFactory
{
public:
    static ICustomerDataAccess* GetCustomerDataAccessObj()
    {
        return new CustomerDataAccess();
    }
};
```

Jetzt müssen wir noch die `CustomerBusinessLogic`-Klasse ändern,
die nun den Schnittstellentyp `ICustomerDataAccess` anstelle des konkreten `DataAccess`-Klassentyps verwendet:

```cpp
class CustomerBusinessLogic
{
private:
    ICustomerDataAccess* m_custDataAccess;

public:
    CustomerBusinessLogic()
    {
        m_custDataAccess = DataAccessFactory::GetCustomerDataAccessObj();
    }

    std::string GetCustomerName(int id)
    {
        return m_custDataAccess->GetCustomerName(id);
    }
};
```

*Zusammenfassung*:

Wir haben das *Dependency Inversion Principle* an einem Beispiel betrachtet,
bei dem ein High-Level-Modul (`CustomerBusinessLogic`) und ein Low-Level-Modul (`CustomerDataAccess`)
von einer Abstraktion (`ICustomerDataAccess`) abhängig sind.

Auch die Abstraktion (`ICustomerDataAccess`) hängt nicht von Details ab (`CustomerDataAccess`),
aber die Details hängen von der Abstraktion ab.

---

[Zurück](../Readme.md)

---
