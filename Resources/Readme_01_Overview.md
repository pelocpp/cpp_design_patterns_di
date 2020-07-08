# �berblick

#### Definition

Aus "Wikipedia", der freien Enzyklop�die:

In der Softwareentwicklung versteht man unter *Dependency Injection* (kurz auch ***DI***) eine Technik,
welche Abh�ngigkeiten eines Objekts zur Laufzeit verwaltet.
Ben�tigt ein Objekt beispielsweise bei seiner Initialisierung ein anderes Objekt, 
ist diese Abh�ngigkeit an einem zentralen Ort hinterlegt. Die Abh�ngigkeit wird also nicht vom zu
initialisierenden Objekt selbst aufgel�st.

Die Aufl�sung einer solchen Abg�ngigkeit bezeichnet man auch als "Injektion" (*Injection*),
das in diesem Zusammenhang zu erzeugende Objekt (auch als "Service" bezeichnet),
wird in ein Empf�ngerobjekt (auch als "Client" bezeichnet) *injiziert*.

An Hand dieser Definitionen bzw. Aussagen erschlie�t sich sicherlich nicht ein tiefsch�rfendes Verst�ndnis,
....

Wenn eine Klasse A ein oder mehrere Funktionen einer Klasse B verwendet, dann sagt man,
dass Klasse A eine Abh�ngigkeit zu Klasse B aufweist.

*Alternative Formulierung*:
Bevor wir in C++ (gerne auch Java oder C#) Methoden anderer Klassen verwenden k�nnen,
m�ssen wir zuerst ein Objekt dieser Klasse erstellen, das hei�t
Klasse `A` muss eine Instanz der Klasse `B` erstellen.

*Sprich*:
Das �bertragen der Aufgabe des Erstellens eines Objekts an eine andere *Instanz* als auch
das Eruieren dieser *Abh�ngigkeit* wird als **Dependency Injection** bezeichnet.

<img src="DI_Comic.png" width="800">

Abbildung 1: **Dependency Injection** bildlich dargestellt.


###### Motivation f�r den Einsatz von DI

Was spricht f�r den Einsatz von *Dependency Injection*?

Nehmen wir an, wir haben eine Fahrzeugklasse `Car`, die verschiedene Objekte wie R�der, Motor usw. enth�lt.

Prinzipiell ist die Fahrzeugklasse f�r die Erstellung aller von ihr abh�ngigen Objekte verantwortlich.
Was ist nun, wenn wir uns entscheiden, *Bridgestone*-R�der in Zukunft wegzulassen und an deren Stelle *Michelin* R�der verwenden m�chten?

Wir m�ssen die Klasse `Car` mit einer neuen Abh�ngigkeit zu *Michelin* R�dern neu erstellen.
W�rden wir auf *Dependency Injection* zur�ckgreifen, k�nnten wir die R�der jedoch zur Laufzeit �ndern,
da Abh�ngigkeiten zur Laufzeit und nicht zur �bersetzungszeit injizierbar sind.

Sie k�nnen sich DI als den Mittelsmann in unserem Code vorstellen, der die gesamte Arbeit erledigt, um das bevorzugte Radobjekt zu erstellen und es der Fahrzeugklasse zur Verf�gung zu stellen.

Auf diese Weise schaffen wir es, eine Fahrzeugklasse `Car` unabh�ngig von der Erstellung von Objekten wie R�der, Batterien usw. zu definieren!

---

[Zur�ck](../Readme.md)

---
