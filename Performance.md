Performance
===========

Hier wird die Performance der Implementierung eines Satzgenerators in verschiedenen Programmiersprachen verglichen.

Die Referenzimplementierung ist in Python geschrieben, da es eine sehr elegante und einfache Sprache ist.

Bei dem Test werden 1.000.000 Sätze generiert und nicht ausgegeben.

Automatische Tests werden von [Travis CI](https://travis-ci.org/davidak/satzgenerator) ausgeführt, wo auch das aktuellste Ergebnis gefunden werden kann.

Das Test-Script kann auch manuell gestartet werden mit

```
$ make test
```

Ergebnis
--------

Interpreter | Laufzeit in s
--- | ---:
Python 2.7.10 | 3.772
Python 3.5.0 | 6.962
PyPy 2 | 0.610
Perl v5.18.2 | 1.647

Tests wurden auf einer VM mit Ubuntu 14.04 LTS von Travis CI ausgeführt. Die CPU hat 2 Kerne und ist eine .
