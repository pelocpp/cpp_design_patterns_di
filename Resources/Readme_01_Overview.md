# �berblick

#### Definition

Aus "Wikipedia", der freien Enzyklop�die:

In der Softwareentwicklung versteht man unter *Dependency Injection* (kurz auch ***DI***) eine Technik,
welche Abh�ngigkeiten eines Objekts zur Laufzeit verwaltet.
Ben�tigt ein Objekt beispielsweise bei seiner Initialisierung ein anderes Objekt, 
ist diese Abh�ngigkeit an einem zentralen Ort hinterlegt. Die Abh�ngigkeit wird also nicht vom zu
initialisierenden Objekt selbst aufgel�st.

#### Ein kurzer �berblick

Die *Dependency Injection* ist eine Programmiertechnik, die eine Klasse von ihren Abh�ngigkeiten unabh�ngig macht.
Dies wird erreicht, indem die Verwendung eines Objekts von seiner Erstellung entkoppelt wird.
Auf diese Weise lassen sich Sie die Prinzipien der *Dependency Injection* und das *Single Responsibility Prinzip*
von **SOLID** befolgen.

Die Aufl�sung einer solchen Abg�ngigkeit bezeichnet man auch als "Injektion" (*Injection*),
das in diesem Zusammenhang zu erzeugende Objekt (auch als "Service" bezeichnet),
wird in ein Empf�ngerobjekt (auch als "Client" bezeichnet) *injiziert*.


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


#### Motivation f�r den Einsatz von DI

Was spricht f�r den Einsatz von *Dependency Injection*?

Nehmen wir an, wir haben eine Fahrzeugklasse `Car`, die verschiedene Objekte wie R�der, Motor usw. enth�lt.

Prinzipiell ist die Fahrzeugklasse f�r die Erstellung aller von ihr abh�ngigen Objekte verantwortlich.
Was ist nun, wenn wir uns entscheiden, *Bridgestone*-R�der in Zukunft wegzulassen und an deren Stelle *Michelin* R�der verwenden m�chten?

Wir m�ssen die Klasse `Car` mit einer neuen Abh�ngigkeit zu *Michelin* R�dern neu erstellen.
W�rden wir auf *Dependency Injection* zur�ckgreifen, k�nnten wir die R�der jedoch zur Laufzeit �ndern,
da Abh�ngigkeiten zur Laufzeit und nicht zur �bersetzungszeit injizierbar sind.

Sie k�nnen sich DI als den Mittelsmann in unserem Code vorstellen, der die gesamte Arbeit erledigt, um das bevorzugte Radobjekt zu erstellen und es der Fahrzeugklasse zur Verf�gung zu stellen.

Auf diese Weise schaffen wir es, eine Fahrzeugklasse `Car` unabh�ngig von der Erstellung von Objekten wie R�der, Batterien usw. zu definieren!

#### Die Details im �berblick

Die Begriffe *Inversion of Control* (*IoC*), *Dependency Inversion Principle* (*DIP*), *Dependency Injection* (*DI*) 
und *IoC*-Container sind m�glicherweise bekannt. Aber ist Ihnen klar, was jeder Begriff bedeutet?

<img src="dp_di_01_principles.svg" width="600">

Abbildung 2: Buzzwords im "Inversion of Control" Umfeld.

Wie in Abbildung 2 dargestellt, sind *IoC* und *DIP* allgemeine Entwurfsprinzipien, 
die beim Entwerfen von Klassen verwendet werden sollten. Da es sich um Entwurfsprinzipien handelt,
empfehlen sie bestimmte "Best Practices", helfen jedoch nicht mit spezifischen Implementierungsdetails.
*Dependency Injection* (*DI*) ist ein Software Entwurfsmuster und der *IoC*-Container wird durch ein Framework bereitgestellt.

###### Inversion of Control

IoC ist ein Entwurfsprinzip, das die Umkehrung (Inversion) unterschiedlicher Arten von "Kontrolle"
im objektorientierten Entwurf vorsieht, um eine lose Kopplung zwischen verschiendenen Klassen zu erreichen

Mit "Kontrolle" sind alle Verantwortlichkeiten gemeint, die eine Klasse hat,
wie z. B. die Kontrolle �ber den Ablauf einer Anwendung (Kontrollfluss)
oder die Kontrolle �ber die Erstellung und Verkn�pfung (Bindung) abh�ngiger Objekte.

###### Dependency Inversion Principle

Das *Dependency Inversion Principle* sagt aus, dass High-Level-Module nicht von Low-Level-Modulen abh�ngen sollten.
Beide Ebenen (Klassen, Module) sollten mittels Schnittstellen abstrahiert werden.

Schnittstellen sollten nicht von Details, sondern die Details sollten von den Schnittstellen abh�ngen.

Das *Dependency Inversion Principle* wurde von Robert Martin (a.k.a. "Onkel Bob") erfunden.
Er ist einer der Begr�nder der **SOLID**-Prinzipien.

###### Dependency Injection

*Dependency Injection* (*DI*) ist ein Entwurfsmuster, das das *IoC*-Prinzip implementiert,
um die Erstellung abh�ngiger Objekte zu invertieren.

###### IoC Container

Ein *IoC*-Container ist ein Framework zur automatisierten Verwaltung der *Dependency Injections* 
in einer Anwendung, so dass der Programmierer hierf�r nicht mehr Zeit und Aufwand spendieren muss.


## Literaturhinweise

*Hinweise*:

Viele Beispiele dieses Repositories stammen aus

[Hypodermic IoC Containers](https://www.tutorialsteacher.com/ioc/introduction)

---

[Zur�ck](../Readme.md)

---
