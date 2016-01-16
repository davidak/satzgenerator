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
Python 2.7.10 | 4.021
Python 3.5.0 | 7.121
PyPy 2.6.1 | 0.673
Ruby 2.2.3p173 | 2.077
Perl v5.18.2 | 1.687
Genie (Vala 0.30.0) | 1.793
Java 1.8.0_60 | 1.908
Crystal 0.10.2 | 1.192

Tests wurden auf einer VM mit Ubuntu 14.04 LTS von Travis CI ausgeführt. Die CPU hat 2 Kerne und ist eine `Intel(R) Xeon(R) CPU @ 2.30GHz`.
