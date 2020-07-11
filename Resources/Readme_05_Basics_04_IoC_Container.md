# IoC Container / Service Locator

#### Definition

*Dependency Injection* (DI) ist ein Entwurfsmuster, um als Resultat lose gekoppelte Klassen zu erzielen.
*IoC Container* (auch als *DI Container* oder *Service Locator* bezeichnet) sind ein Framework zur Implementierung
einer automatisierten *Dependency Injection*.
Ein solcher Container verwaltet die Objekterstellung und die Lebensdauer abhängiger Objekte
und fügt diese Objekte Klassen hinzu, die abhängig sind.

Ein IoC-Container erstellt ein Objekt der angegebenen Klasse und injiziiert zur Laufzeit
alle Abhängigkeitsobjekte über einen Konstruktor, eine Eigenschaft oder eine Methode in dieses Objekt.
IoC-Container kümmern sich auch um die Freigabe derartiger Objekte zum entsprechenden Zeitpunkt.

Die bedeutet, dass wir in der Anwendung diese Objekte weder manuell erstellen noch verwalten noch freigeben müssen.

In diesem Zusammenhang gibt es den Begriff des so genannten *DI-Lebenszyklus*:

  * **Register**: Der Container muss wissen, welche Abhängigkeit instanziiert werden muss,
   wenn er auf einen bestimmten Typ stößt. Dieser Vorgang wird als Registrierung bezeichnet.
   Grundsätzlich muss der Container in der Lage sein, eine Zuordnung von Typen verwalten zu können.

  * **Resolve**: Bei Verwendung des IoC-Containers werden Objekte nicht manuell erstellt.
    Der Container erledigt das für uns. Dies nennt man Resolution.
    Der Container muss Methoden zum Auflösen des angegebenen Typs besitzen.
    Der Container kreiert ein Objekt des angegebenen Typs, fügt gegebenenfalls die erforderlichen Abhängigkeiten ein
    und gibt das Objekt zurück.

  * **Dispose**: Der Container muss die Lebensdauer der abhängigen Objekte verwalten.
   Die meisten IoC-Container enthalten verschiedene Lebenszeitmanager,
   um den Lebenszyklus eines Objekts zu verwalten und sie freizugeben.



---

[Zurück](../Readme.md)

---
