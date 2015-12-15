#!/usr/bin/env ruby

# Textdateien einlesen
$vornamen_m = File.readlines("../data/vornamen_m.txt").map(&:chomp)
$vornamen_w = File.readlines("../data/vornamen_w.txt").map(&:chomp)
$vornamen = $vornamen_m + $vornamen_w
$verben = File.readlines("../data/verben.txt").map(&:chomp)
$adjektive = File.readlines("../data/adjektive.txt").map(&:chomp)
$orte = File.readlines("../data/orte.txt").map(&:chomp)

# Listen
$beziehung_m = [ "Vater", "Bruder", "Mann", "Sohn", "Onkel", "Opa", "Cousin", "Freund", "Kollege", "Mitbewohner" ]
$beziehung_w = [ "Mutter", "Schwester", "Frau", "Tochter", "Tante", "Oma", "Cousine", "Freundin", "Kollegin", "Mitbewohnerin" ]
$beziehung = $beziehung_m + $beziehung_w
$possessivpronomen_m = [ "Mein", "Dein", "Sein", "Ihr" ]
$spezial = [ "Er", "Sie", "Jemand", "Niemand", "Ein Lehrer", "Ein Polizist", "Ein Beamter", "Ein Arzt", "Der Alkoholiker", "Ein normaler Mensch" ]

# Person generieren
def person
  z = Random.rand(6)
  p = case z
    when 0 then $vornamen.sample + "s " + $beziehung.sample
    when 1 then $possessivpronomen_m.sample + " " + $beziehung_m.sample
    when 2 then $possessivpronomen_m.sample + "e " + $beziehung_w.sample
    when 3 then $spezial.sample
    else $vornamen.sample
  end
end

# Satz generieren
def satz
  return person + " " + $verben.sample + " " + $adjektive.sample + " " + $orte.sample + "."
end

# anzahl setzen, wenn eine zahl als parameter angegeben wurde, sonst 1
if ARGV[0].to_i > 1
  anzahl = ARGV[0].to_i
else
  anzahl = 1
end

# Sätze entsprechend anzahl ausgeben
anzahl.times do
  puts satz
end
