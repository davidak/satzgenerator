#!/usr/bin/env python
# -*- coding: utf-8 -*-
#
# Copyright (C) 2015 davidak
# 
# This program is free software: you can redistribute it and/or modify
# it under the terms of the GNU General Public License as published by
# the Free Software Foundation, either version 3 of the License, or
# (at your option) any later version.
# 
# This program is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU General Public License for more details.
# 
# You should have received a copy of the GNU General Public License
# along with this program.  If not, see {http://www.gnu.org/licenses/}.

"""
Satzgenerator

Referenzimplementierung
"""

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

# Satz ausgeben
def main():
	s = satz()
	print(s)

if __name__ == "__main__":
	main()
