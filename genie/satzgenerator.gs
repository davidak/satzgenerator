/*
Copyright (C) 2015 davidak

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see {http://www.gnu.org/licenses/}.
*/

// Textdatei einlesen, Zeilen in Arrays
def lese (datei:string) : array of string
	s:string
	FileUtils.get_contents(datei,out s)
	return s.split("\n")

// Arrays
const beziehung_m : array of string = {"Vater", "Bruder", "Mann", "Sohn", "Onkel", "Opa", "Cousin", "Freund", "Kollege", "Mitbewohner"}
const beziehung_w : array of string = {"Mutter", "Schwester", "Frau", "Tochter", "Tante", "Oma", "Cousine", "Freundin", "Kollegin", "Mitbewohnerin"}
//const beziehung = beziehung_m + beziehung_w
const possessivpronomen_m : array of string = {"Mein", "Dein", "Sein", "Ihr"}
const spezial : array of string = {"Er", "Sie", "Jemand", "Niemand", "Ein Lehrer", "Ein Polizist", "Ein Beamter", "Ein Arzt", "Der Alkoholiker", "Ein normaler Mensch"}

// Person generieren
def person (vornamen_m:array of string) : string
	z:int = GLib.Random.int_range(1,6)
	s:string
	//print "%d", z
	case z
		when 1
			// should be vornamen and beziehung as added m + w
			s = vornamen_m[GLib.Random.int_range(0,vornamen_m.length)] + "s " + beziehung_m[GLib.Random.int_range(0,beziehung_m.length)]
		when 2
			s = possessivpronomen_m[GLib.Random.int_range(0,possessivpronomen_m.length)] + " " + beziehung_m[GLib.Random.int_range(0,beziehung_m.length)]
		when 3
			s = possessivpronomen_m[GLib.Random.int_range(0,possessivpronomen_m.length)] + "e " + beziehung_w[GLib.Random.int_range(0,beziehung_w.length)]
		when 4
			s = spezial[GLib.Random.int_range(0,spezial.length)]
		default
			s = vornamen_m[GLib.Random.int_range(0,vornamen_m.length)]
	return s

// Satz generieren
def satz (p:string, verben:array of string, adjektive:array of string, orte:array of string) : string
	return p + " " + verben[GLib.Random.int_range(0,verben.length)] + " " + adjektive[GLib.Random.int_range(0,adjektive.length)] + " " + orte[GLib.Random.int_range(0,orte.length)] + "."

init
	Intl.setlocale( LocaleCategory.ALL, "" )

	vornamen_m : array of string = lese("../data/vornamen_m.txt")
	vornamen_w : array of string = lese("../data/vornamen_w.txt")
	//vornamen = vornamen_m + vornamen_w
	verben : array of string = lese("../data/verben.txt")
	adjektive : array of string = lese("../data/adjektive.txt")
	orte : array of string = lese("../data/orte.txt")

	anzahl:int
	try
		anzahl = int.parse(args[1])
	except
		anzahl = 1

	for i:int = 1 to anzahl
		p:string = person(vornamen_m)
		print satz(p, verben, adjektive, orte)
