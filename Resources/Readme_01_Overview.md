# Überblick

#### Definition

Aus "Wikipedia", der freien Enzyklopädie:

In der Softwareentwicklung versteht man unter *Dependency Injection* (kurz auch ***DI***) eine Technik,
welche Abhängigkeiten eines Objekts zur Laufzeit verwaltet.
Benötigt ein Objekt beispielsweise bei seiner Initialisierung ein anderes Objekt, 
ist diese Abhängigkeit an einem zentralen Ort hinterlegt. Die Abhängigkeit wird also nicht vom zu
initialisierenden Objekt selbst aufgelöst.

Die Auflösung einer solchen Abgängigkeit bezeichnet man auch als "Injektion" (*Injection*),
das in diesem Zusammenhang zu erzeugende Objekt (auch als "Service" bezeichnet),
wird in ein Empfängerobjekt (auch als "Client" bezeichnet) *injiziert*.

An Hand dieser Definitionen bzw. Aussagen erschließt sich sicherlich nicht ein tiefschürfendes Verständnis,
....

Wenn eine Klasse A ein oder mehrere Funktionen einer Klasse B verwendet, dann sagt man,
dass Klasse A eine Abhängigkeit zu Klasse B aufweist.

*Alternative Formulierung*:
Bevor wir in C++ (gerne auch Java oder C#) Methoden anderer Klassen verwenden können,
müssen wir zuerst ein Objekt dieser Klasse erstellen, das heißt
Klasse `A` muss eine Instanz der Klasse `B` erstellen.

*Sprich*:
Das Übertragen der Aufgabe des Erstellens eines Objekts an eine andere *Instanz* als auch
das Eruieren dieser *Abhängigkeit* wird als **Dependency Injection** bezeichnet.

<img src="DI_Comic.png" width="800">

Abbildung 1: **Dependency Injection** bildlich dargestellt.


###### Motivation für den Einsatz von DI

Was spricht für den Einsatz von *Dependency Injection*?

Nehmen wir an, wir haben eine Fahrzeugklasse `Car`, die verschiedene Objekte wie Räder, Motor usw. enthält.

Prinzipiell ist die Fahrzeugklasse für die Erstellung aller von ihr abhängigen Objekte verantwortlich.
Was ist nun, wenn wir uns entscheiden, *Bridgestone*-Räder in Zukunft wegzulassen und an deren Stelle *Michelin* Räder verwenden möchten?

Wir müssen die Klasse `Car` mit einer neuen Abhängigkeit zu *Michelin* Rädern neu erstellen.
Würden wir auf *Dependency Injection* zurückgreifen, könnten wir die Räder jedoch zur Laufzeit ändern,
da Abhängigkeiten zur Laufzeit und nicht zur Übersetzungszeit injizierbar sind.

Sie können sich DI als den Mittelsmann in unserem Code vorstellen, der die gesamte Arbeit erledigt, um das bevorzugte Radobjekt zu erstellen und es der Fahrzeugklasse zur Verfügung zu stellen.

Auf diese Weise schaffen wir es, eine Fahrzeugklasse `Car` unabhängig von der Erstellung von Objekten wie Räder, Batterien usw. zu definieren!

---

[Zurück](../Readme.md)

---
