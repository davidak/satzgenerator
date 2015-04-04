/*
* Copyright (C) 2015 davidak
* 
* This program is free software: you can redistribute it and/or modify
* it under the terms of the GNU General Public License as published by
* the Free Software Foundation, either version 3 of the License, or
* (at your option) any later version.
* 
* This program is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
* GNU General Public License for more details.
* 
* You should have received a copy of the GNU General Public License
* along with this program.  If not, see {http://www.gnu.org/licenses/}.
*/

import java.util.Arrays;
import java.util.ArrayList;
import java.util.List; 
import java.util.stream.Stream;
import java.io.IOException;
import java.nio.file.Files;
import java.nio.file.Paths;
import java.io.IOException;
import java.util.Random;

public class Satzgenerator {
	public static Random r = new Random();

	// Arrays
	public static String [] beziehung_m = {"Vater", "Bruder", "Mann", "Sohn", "Onkel", "Opa", "Cousin", "Freund", "Kollege", "Mitbewohner"};
	public static String [] beziehung_w = {"Mutter", "Schwester", "Frau", "Tochter", "Tante", "Oma", "Cousine", "Freundin", "Kollegin", "Mitbewohnerin"};
	public static String [] beziehung = Stream.concat(Arrays.stream(beziehung_m), Arrays.stream(beziehung_w)).toArray(String[]::new);
	public static String [] possessivpronomen_m = {"Mein", "Dein", "Sein", "Ihr"};
	public static String [] spezial = {"Er", "Sie", "Jemand", "Niemand", "Ein Lehrer", "Ein Polizist", "Ein Beamter", "Ein Arzt", "Der Alkoholiker", "Ein normaler Mensch"};
	
	// Textdateien einlesen, Zeilen in Arrays
	public static String [] vornamen_m = lese("../data/vornamen_m.txt");
	public static String [] vornamen_w = lese("../data/vornamen_w.txt");
	public static String [] vornamen = Stream.concat(Arrays.stream(vornamen_m), Arrays.stream(vornamen_w)).toArray(String[]::new);
	public static String [] verben = lese("../data/verben.txt");
	public static String [] adjektive = lese("../data/adjektive.txt");
	public static String [] orte = lese("../data/orte.txt");

	public static String[] lese(String datei) {
		try {
			return Files.readAllLines(Paths.get(datei)).stream().toArray(String[]::new);
		} catch (IOException e) {
			e.printStackTrace();
			return null;
		}
	}

	public static String person() {
		int z = r.nextInt(6);
		String s;
		switch (z) {
			case 0 : s = vornamen[r.nextInt(vornamen.length)] + "s " + beziehung[r.nextInt(beziehung.length)]; break;
			case 1 : s = possessivpronomen_m[r.nextInt(possessivpronomen_m.length)] + " " + beziehung_m[r.nextInt(beziehung_m.length)]; break;
			case 2 : s = possessivpronomen_m[r.nextInt(possessivpronomen_m.length)] + "e " + beziehung_w[r.nextInt(beziehung_w.length)]; break;
			case 3 : s = spezial[r.nextInt(spezial.length)]; break;
			default : s = vornamen[r.nextInt(vornamen.length)];
		}
		return s;
	}

	public static String satz() {
		return person() + " " + verben[r.nextInt(verben.length)] + " " + adjektive[r.nextInt(adjektive.length)] + " " + orte[r.nextInt(orte.length)] + ".";
	}

	public static void main (String[] args) {
		int anzahl;
		try {
            anzahl = Integer.parseInt(args[0]);
        } catch (NumberFormatException | ArrayIndexOutOfBoundsException e) {
        	anzahl = 1;
        }

        for (int i = 1; i <= anzahl; i++) {
        	System.out.println(satz());
        }
	}
}
