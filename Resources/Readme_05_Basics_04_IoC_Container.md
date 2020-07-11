# IoC Container / Service Locator

#### Definition

*Dependency Injection* (DI) ist ein Entwurfsmuster, um als Resultat lose gekoppelte Klassen zu erzielen.
*IoC Container* (auch als *DI Container* oder *Service Locator* bezeichnet) sind ein Framework zur Implementierung
einer automatisierten *Dependency Injection*.
Ein solcher Container verwaltet die Objekterstellung und die Lebensdauer abh�ngiger Objekte
und f�gt diese Objekte Klassen hinzu, die abh�ngig sind.

Ein IoC-Container erstellt ein Objekt der angegebenen Klasse und injiziiert zur Laufzeit
alle Abh�ngigkeitsobjekte �ber einen Konstruktor, eine Eigenschaft oder eine Methode in dieses Objekt.
IoC-Container k�mmern sich auch um die Freigabe derartiger Objekte zum entsprechenden Zeitpunkt.

Die bedeutet, dass wir in der Anwendung diese Objekte weder manuell erstellen noch verwalten noch freigeben m�ssen.

In diesem Zusammenhang gibt es den Begriff des so genannten *DI-Lebenszyklus*:

  * **Register**: Der Container muss wissen, welche Abh�ngigkeit instanziiert werden muss,
   wenn er auf einen bestimmten Typ st��t. Dieser Vorgang wird als Registrierung bezeichnet.
   Grunds�tzlich muss der Container in der Lage sein, eine Zuordnung von Typen verwalten zu k�nnen.

  * **Resolve**: Bei Verwendung des IoC-Containers werden Objekte nicht manuell erstellt.
    Der Container erledigt das f�r uns. Dies nennt man Resolution.
    Der Container muss Methoden zum Aufl�sen des angegebenen Typs besitzen.
    Der Container kreiert ein Objekt des angegebenen Typs, f�gt gegebenenfalls die erforderlichen Abh�ngigkeiten ein
    und gibt das Objekt zur�ck.

  * **Dispose**: Der Container muss die Lebensdauer der abh�ngigen Objekte verwalten.
   Die meisten IoC-Container enthalten verschiedene Lebenszeitmanager,
   um den Lebenszyklus eines Objekts zu verwalten und sie freizugeben.



---

[Zur�ck](../Readme.md)

---
