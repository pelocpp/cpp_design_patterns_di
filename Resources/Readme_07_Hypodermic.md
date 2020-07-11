# Ein Beispiel: Hypodermic

#### �berblick

In den Sources dieses Repositories werden eine Reihe von Beispielen
auf Basis des Hypodermic IoC Containers vorgestellt:

  * *Source.cpp*<br/>Testbeispiel aus dem Hypodermic Wiki / *Getting Started*. Man betrachte im Detail die einzelnen Schritte, die bei der Aufl�sung von `IMessageWriter` vollzogen werden:

    * Der Container sucht nach einer Registrierung, die diesem Typ entspricht.
    * Der Container erkennt, dass `IMessageWriter` dem Typ `ConsoleMessageWriter` zugeordnet ist.
    * `ConsoleMessageWriter` ben�tigt allerdings ein `IMessageSerializer`-Objekt.
    * Der Container sucht also nach `IMessageSerializer` und sieht, dass dieser der Klasse `LengthPrefixedMessageSerializer` zugeordnet ist.
    * Der Container instanziiert `LengthPrefixedMessageSerializer` und �bergibt dieses Objekt an den Konstruktor von `ConsoleMessageWriter`.
    * Eine neue Instanz von `ConsoleMessageWriter wird` zur�ckgegeben.

  * *Source1.cpp*<br/>Was passiert, wenn zu einer Klasse mehrere Klassen registriert sind (`registerType`).
  * *Source2.cpp*<br/>Pro Aufruf von `resolve` wird ein neues Objekt des registrierten Typs zur�ckgegeben. Mit `singleInstance` kann man dem Container explizit mitteilen, dass ein Objekt nur einmal erstellt werden soll.
  * *Source3.cpp*<br/>Wie Beipiel *Source2.cpp* / Vergleich von Adressen der Objekte. 
  * *Source4.cpp*<br/>Hypodermic Logging Mechanismus.
  * *Source5.cpp*<br/>Mehrfach-Registrierung einer Klasse und Gebrauch von `useIfNone`.
  * *Source6.cpp*<br/>Demonstration einer tiefer verschachtelten Aufl�sung von Klassenabh�ngigkeiten.
  * *Source7.cpp*<br/>Demonstration einer Factory f�r Klassen / Methode `registerInstanceFactory`.

---

[Zur�ck](../Readme.md)

---

