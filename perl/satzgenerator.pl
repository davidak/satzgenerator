#!/usr/bin/perl
#
# Satzgenerator
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

# Textdateien einlesen, Zeilen in Liste
open(my $FILE, '<', '../data/vornamen_m.txt');
my @vornamen_m = <$FILE>;
close($FILE);

open(my $FILE, '<', '../data/vornamen_w.txt');
my @vornamen_w = <$FILE>;
close($FILE);

open(my $FILE, '<', '../data/verben.txt');
my @verben = <$FILE>;
close($FILE);

open(my $FILE, '<', '../data/adjektive.txt');
my @adjektive = <$FILE>;
close($FILE);

open(my $FILE, '<', '../data/orte.txt');
my @orte = <$FILE>;
close($FILE);

# Zeilenumbrücke am Ende entfernen
chomp(@vornamen_m, @vornamen_w, @verben, @adjektive, @orte);

my @vornamen = (@vornamen_m, @vornamen_w);

# Listen
my @beziehung_m = ('Vater', 'Bruder', 'Mann', 'Sohn', 'Onkel', 'Opa', 'Cousin', 'Freund', 'Kollege', 'Mitbewohner');
my @beziehung_w = ('Mutter', 'Schwester', 'Frau', 'Tochter', 'Tante', 'Oma', 'Cousine', 'Freundin', 'Kollegin', 'Mitbewohnerin');
my @beziehung = (@beziehung_m, @beziehung_w);
my @possessivpronomen_m = ('Mein', 'Dein', 'Sein', 'Ihr');
my @spezial = ('Er', 'Sie', 'Jemand', 'Niemand', 'Ein Lehrer', 'Ein Polizist', 'Ein Beamter', 'Ein Arzt', 'Der Alkoholiker', 'Ein normaler Mensch');

# Person generieren
sub person {
	my $z = int(rand(6)+1);
	if ($z == 1) { $person = $vornamen[rand(@vornamen)] . 's ' . $beziehung[rand(@beziehung)]; }
	elsif ($z == 2) { $person = $possessivpronomen_m[rand(@possessivpronomen_m)] . ' ' . $beziehung_m[rand(@beziehung_m)]; }
	elsif ($z == 3) { $person = $possessivpronomen_m[rand(@possessivpronomen_m)] . 'e ' . $beziehung_w[rand(@beziehung_w)]; }
	elsif ($z == 4) { $person = $spezial[rand(@spezial)]; }
	else { $person = $vornamen[rand(@vornamen)]; }
	return $person;
}

# Satz generieren
sub satz {
	return person() . " $verben[rand(@verben)] $adjektive[rand(@adjektive)] $orte[rand(@orte)].\n";
}

# Satz ausgeben
my $s = satz();
print($s);
