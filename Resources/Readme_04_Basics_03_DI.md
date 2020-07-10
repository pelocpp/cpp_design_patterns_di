# Grundlagen

#### Dependency Injection

Im letzten Abschnitt sind wir auf *Abstraktion* eingegangen, um Klassen lose zu koppeln.
In diesem Abschnitt werden wir *Dependency Injection* und das Strategie-Entwurfsmuster zusammen implementieren,
um jegliche Abh�ngigkeit in der Erstellung eines abh�ngigen Objekts vollst�ndig aus der Klasse zu entfernen.
Das Ziel ist es also, die betrachteten Klassen vollst�ndig lose zu koppeln.

*Dependency Injection* (DI) ist ein Entwurfsmuster, das zur Implementierung von IoC verwendet wird.
Es erm�glicht die Erstellung abh�ngiger Objekte au�erhalb einer Klasse und stellt den Zugang 
dieser Objekte einer Klasse auf unterschiedliche Weise zur Verf�gung.
Mit *Dependency Injection* verschieben wir die Erstellung und Bindung der abh�ngigen Objekte
au�erhalb der von ihnen abh�ngigen Klasse.

#### Die 4 Rollen bei *Dependency Injection*

Um sich mit der *Dependency Injection* Technik vertraut zu werden,
ben�tigt man eine Reihe von Klassen und/oder Schnittstellen,
die vier grundlegende Rollen erf�llen. Diese sind:

  * Ein *Service*, der eine Dienstleitung bereit stellt und dem *Client* zur Verf�gung stellt.
  * Ein *Client*, der den *Service* in Anspruch nehmen m�chte.
  * Eine Schnittstelle (*Interface*), die vom *Client* verwendet und vom *Service* implementiert wird.
  * Eine *Injector* Klasse, die eine *Service* Instanz erstellt und diese in den Client injiziert.

<img src="dp_di_04_relationship_classes.svg" width="450">

Abbildung 1: Beziehung zwischen den unterschiedlichen Klassen bei *Dependency Injection*.

Wie man Abbildung 1 entnehmen kann, erstellt die *Injector*-Klasse ein Objekt der *Service*-Klasse
und injiziert dieses Objekt in ein *Client*-Objekt.
Auf diese Weise trennt das *Dependency Injection*-Entwurfsmuster die Verantwortung
f�r das Erstellen eines Objekts der Serviceklasse aus der Clientklasse heraus.

#### Arten der *Dependency Injection*

Wie wir gesehen haben, injiziert die Injektorklasse den Dienst (Abh�ngigkeit) in den Client (abh�ngig).

Technisch betrachten kann dieses "*injizieren*" auf drei Arten erfolgen:
�ber einen Konstruktor, �ber eine Eigenschaft oder �ber eine Methode.

  * *Construktor-Injection*:<br/>Die Abh�ngigkeit(en) werden �ber den Konstruktor einer Klasse bereitgestellt.
  * *Setter-Injection*:<br/>Der Client stellt eine *setter*-Methode zur Verf�gung,
     mit deren Hilfe der *Injektor* die Abh�ngigkeit injiziert.
  * *Interface-Injection*:<br/>Bei dieser Art der Injektion implementiert die Clientklasse eine Schnittstelle,
    die die Methode(n) zum Bereitstellen der Abh�ngigkeit enthalten,
    und der Injektor verwendet diese Schnittstelle, um die Abh�ngigkeit der Clientklasse bereitzustellen.

In den Verantwortungsbereich einer *Dependency Injection* fallen somit:

1. Das Erstellen neuer Objekte,
2. die Kenntnis, welche Klassen diese Objekte ben�tigen.
3. diesen Klassen den Zugang zu diesen neu erzeugten Objekten zu erm�glichen.

WEITER MIT DEM BEISPIEL AUS DEM LEZTEN ABSCHNITT ..


```cpp

```

---

[Zur�ck](../Readme.md)

---
