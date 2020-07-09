# Grundlagen

#### HIER GEHTS WEITER

Das hei�t:https://sourcemaking.com/


###### Beispiel: Kontrolle �ber die Erstellung abh�ngiger Objekte


<img src="dp_di_02_n_tier_architecture.svg" width="600">

Abbildung 1: *n*-Tier-Software-Architektur.


Im obigen Beispiel ruft Klasse `A` `b.SomeMethod()` auf, um den Aufruf der Methode `Task1` auszuf�hren. 
Klasse`A` kann ihre Aufgabe nicht ohne Klasse `B` ausf�hren. Man kann also sagen,
dass "Klasse A von Klasse B abh�ngig ist" oder "Klasse B stelle eine Abh�ngigkeit von Klasse A dar".


```cpp
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

class Factory
{
public:
    static B* GetObjectOfB()
    {
        return new B();
    }
}; 
```

Wie Sie oben sehen k�nnen, verwendet Klasse `A` die `Factory`-Klasse, um ein Objekt der Klasse `B` zu erzeugen.
Daher haben wir die Abh�ngigkeit der Objekterstellung von Klasse `A` in Klasse `Factory` invertiert.
Klasse `A` erstellt kein Objekt der Klasse `B` mehr, sondern verwendet die `Factory`-Klasse,
um Objekte der Klasse `B` zu generieren.

###### Ein anwendungsnaheres Beispiel


---

[Zur�ck](../Readme.md)

---
