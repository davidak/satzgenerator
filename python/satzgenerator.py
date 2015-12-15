#!/usr/bin/env python
# -*- coding: utf-8 -*-

"""
Satzgenerator

Referenzimplementierung
"""

import sys
import random as r

# Textdateien einlesen, Zeilen in Liste
vornamen_m = open('../data/vornamen_m.txt', 'r').read().splitlines()
vornamen_w = open('../data/vornamen_w.txt', 'r').read().splitlines()
vornamen = vornamen_m + vornamen_w
verben = open('../data/verben.txt', 'r').read().splitlines()
adjektive = open('../data/adjektive.txt', 'r').read().splitlines()
orte = open('../data/orte.txt', 'r').read().splitlines()

# Listen
beziehung_m = ['Vater', 'Bruder', 'Mann', 'Sohn', 'Onkel', 'Opa', 'Cousin', 'Freund', 'Kollege', 'Mitbewohner']
beziehung_w = ['Mutter', 'Schwester', 'Frau', 'Tochter', 'Tante', 'Oma', 'Cousine', 'Freundin', 'Kollegin', 'Mitbewohnerin']
beziehung = beziehung_m + beziehung_w
possessivpronomen_m = ['Mein', 'Dein', 'Sein', 'Ihr']
spezial = ['Er', 'Sie', 'Jemand', 'Niemand', 'Ein Lehrer', 'Ein Polizist', 'Ein Beamter', 'Ein Arzt', 'Der Alkoholiker', 'Ein normaler Mensch']

# Person generieren
def person():
	z = r.randint(1,6)
	if z == 1:
		_s = r.choice(vornamen) + 's ' + r.choice(beziehung)
	elif z == 2:
		_s = r.choice(possessivpronomen_m) + ' ' + r.choice(beziehung_m)
	elif z == 3:
		_s = r.choice(possessivpronomen_m) + 'e ' + r.choice(beziehung_w)
	elif z == 4:
		_s = r.choice(spezial)
	else:
		_s = r.choice(vornamen)
	return _s

# Satz generieren
def satz():
	return person() + ' ' + r.choice(verben) + ' ' + r.choice(adjektive) + ' ' + r.choice(orte) + '.'

# Sätze ausgeben
def main():
	# Anzahl als Parameter übergeben
	try:
		anzahl = int(sys.argv[1])
	except:
		anzahl = 1

	for i in range(anzahl):
		print(satz())

if __name__ == "__main__":
	main()
