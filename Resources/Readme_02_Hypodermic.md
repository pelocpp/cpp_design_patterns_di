# Ein Beispiel: Hypodermic

#### Aufgabe

Schreiben Sie ein Programm,
das zufällige Passwörter an Hand von vordefinierten Regeln generieren kann.

Regeln für den Aufbau könnten sein "nur Ziffern", "nur Sonderzeichen",
"nur Großbuchstaben", "nur Kleinbuchstaben" oder beliebige Kombinationen dieser Regeln.

Jede Implementierung einer Regel besitzt eine Längenangabe,
die die Länge der zu erzeugenden Passworts festlegt.

Welches klassische Entwurfsmuster bietet sich zur Realisierung an?

Schreiben Sie eine Testfunktion, die ein oder mehrere Regeln anwendet.

###### Zusatzaufgabe

Ergänzen Sie die vorhandene Lösung um eine Klasse `PinGenerator`.
Unter einer Pin verstehen wir ein Passwort der Länge 4, das ausschließlich
aus den Ziffern 1 bis 6 besteht. Testen Sie die Klasse sowohl an Hand 
eines selbständigen Objekts (also Instanz der Klasse `PinGenerator`)
als auch unter der Regie eines `CompositePasswordGenerator`-Objekts.

---

[Zurück](../Readme.md)

---
