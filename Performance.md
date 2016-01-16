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
Python 2.7.10 | 3.855
Python 3.5.0 | 7.269
PyPy 2.6.1 | 0.681
Ruby 2.2.3p173 | 2.082
Perl v5.18.2 | 1.668
Genie (Vala 0.30.0) | 1.748
Java 1.8.0_60 | 2.023
Crystal 0.10.2 | 1.278

Tests wurden auf einer VM mit Ubuntu 14.04 LTS von Travis CI ausgeführt.
Die CPU hat 2 Kerne und ist eine `Intel(R) Xeon(R) CPU @ 2.30GHz`.

Zum Vergleich auf einem iMac mit `Intel Core i7 @ 2,93 GHz` (8 Kerne).

Interpreter | Laufzeit in s
--- | ---:
Python 2.7.10 | 8.360
Python 3.2.2 | 12.226
PyPy 4.0.1 | 0.819
Ruby 2.2.3p173 | 3.186
jruby 9.0.4.0 (2.2.2) | 5.026
Perl v5.18.2 | 2.675
Genie (Vala 0.30.0) | 3.715
Java 1.8.0_40 | 2.379
Crystal 0.9.1 | 1.759
