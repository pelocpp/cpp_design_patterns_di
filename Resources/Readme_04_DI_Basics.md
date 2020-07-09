# Grundlagen der Dependency Injection

#### Die 4 Rollen bei der *Dependency Injection*

Um mit den der *Dependency Injection* Technik vertraut zu werden, benötigen man eine Reihe von Klassen und/oder Schnittstellen,
die vier grundlegende Rollen erfüllen. Diese sind:

  * Ein *Service*, der eine Dienstleitung bereit stell.
  * Ein *Client*, der den *Service* in Anspruch nehmen möchte.
  * Eine Schnittstelle (*Interface*), die vom *Client* verwendet und vom *Service* implementiert wird.
  * Der *Injector*, der eine *Service* Instanz erstellt und diese in den Client injiziert.


#### 3 Arten 

Grundsätzlich gibt es drei Arten der *Dependency Injection*:
  * *Construktor-Injection*:<br/>Die Abhängigkeit(en) werden über den Konstruktor einer Klasse aufgelöst.
  * *Setter-Injection*:<br/>Der Client stellt eine *setter*-Methode zur Verfügung, mit deren Hilfe der Injektor die Abhängigkeit injiziert.
  * *Interface-Injection*:<br/>Die Abhängigkeit bietet eine Injektormethode, mit der die Abhängigkeit in jeden an sie übergebenen Client injiziert wird. Clients müssen eine Schnittstelle implementieren, die eine Setter-Methode verfügbar macht, die die Abhängigkeit akzeptiert.

In den Verantwortungsbereich einer *Dependency Injection* fallen somit:

1. Das Erstellen neuer Objekte.
2. Die Kenntnis, welche Klassen diese Objekte benötigen.
3. Diesen Klassen den Zugang zu diesen neu erzeugten Objekten ermöglichen.

#### Service Locator



---

[Zurück](../Readme.md)

---
