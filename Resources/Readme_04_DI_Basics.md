# Grundlagen der Dependency Injection

#### Die 4 Rollen bei der *Dependency Injection*

Um mit den der *Dependency Injection* Technik vertraut zu werden, ben�tigen man eine Reihe von Klassen und/oder Schnittstellen,
die vier grundlegende Rollen erf�llen. Diese sind:

  * Ein *Service*, der eine Dienstleitung bereit stell.
  * Ein *Client*, der den *Service* in Anspruch nehmen m�chte.
  * Eine Schnittstelle (*Interface*), die vom *Client* verwendet und vom *Service* implementiert wird.
  * Der *Injector*, der eine *Service* Instanz erstellt und diese in den Client injiziert.


#### 3 Arten 

Grunds�tzlich gibt es drei Arten der *Dependency Injection*:
  * *Construktor-Injection*:<br/>Die Abh�ngigkeit(en) werden �ber den Konstruktor einer Klasse aufgel�st.
  * *Setter-Injection*:<br/>Der Client stellt eine *setter*-Methode zur Verf�gung, mit deren Hilfe der Injektor die Abh�ngigkeit injiziert.
  * *Interface-Injection*:<br/>Die Abh�ngigkeit bietet eine Injektormethode, mit der die Abh�ngigkeit in jeden an sie �bergebenen Client injiziert wird. Clients m�ssen eine Schnittstelle implementieren, die eine Setter-Methode verf�gbar macht, die die Abh�ngigkeit akzeptiert.

In den Verantwortungsbereich einer *Dependency Injection* fallen somit:

1. Das Erstellen neuer Objekte.
2. Die Kenntnis, welche Klassen diese Objekte ben�tigen.
3. Diesen Klassen den Zugang zu diesen neu erzeugten Objekten erm�glichen.

#### Service Locator



---

[Zur�ck](../Readme.md)

---
