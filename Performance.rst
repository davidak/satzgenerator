Performance
===========

Hier wird die Performance der Implementierung eines Satzgenerators in verschiedenen Programmiersprachen verglichen.

Die Referenzimplementierung ist in Python, da es eine sehr elegante und einfache Sprache ist.

Bei dem Test werden 1.000.000 Sätze generiert und nicht ausgegeben.

::

	$ time python satzgenerator.py 1000000 >/dev/null 2>&1

Ergebnis
--------

============  ========
Sprache       Sekunden
============  ========
Python 2.7    6
Python 3.2    10
Perl 5.8.9    3,5
Genie         4,3
Java          2,7
============  ========
