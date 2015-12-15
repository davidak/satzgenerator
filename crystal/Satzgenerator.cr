module Satzgenerator
  extend self

  # Datei einlesen und zeilenweise als Array zurückgeben, ohne newline am Ende
  def lese(filename)
    lines = [] of String
    File.each_line(filename) do |line|
      lines << line.chomp
    end
    return lines
  end

  # Textdateien einlesen
  $vornamen_m = lese("../data/vornamen_m.txt")
  $vornamen_w = lese("../data/vornamen_w.txt")
  $vornamen = $vornamen_m + $vornamen_w
  $verben = lese("../data/verben.txt")
  $adjektive = lese("../data/adjektive.txt")
  $orte = lese("../data/orte.txt")

  # Listen
  $beziehung_m = [ "Vater", "Bruder", "Mann", "Sohn", "Onkel", "Opa", "Cousin", "Freund", "Kollege", "Mitbewohner" ]
  $beziehung_w = [ "Mutter", "Schwester", "Frau", "Tochter", "Tante", "Oma", "Cousine", "Freundin", "Kollegin", "Mitbewohnerin" ]
  $beziehung = $beziehung_m + $beziehung_w
  $possessivpronomen_m = [ "Mein", "Dein", "Sein", "Ihr" ]
  $spezial = [ "Er", "Sie", "Jemand", "Niemand", "Ein Lehrer", "Ein Polizist", "Ein Beamter", "Ein Arzt", "Der Alkoholiker", "Ein normaler Mensch" ]

  # Person generieren
  def person
    case Random.rand(6)
    when 0
      p = $vornamen.sample + "s " + $beziehung.sample
    when 1
      p = $possessivpronomen_m.sample + " " + $beziehung_m.sample
    when 2
      p = $possessivpronomen_m.sample + "e " + $beziehung_w.sample
    when 3
      p = $spezial.sample
    else
      p = $vornamen.sample
    end
  end

  # Satz generieren
  def satz
    return person + " " + $verben.sample + " " + $adjektive.sample + " " + $orte.sample + "."
  end

  # anzahl setzen, wenn eine zahl als parameter angegeben wurde, sonst 1
  begin
    anzahl = ARGV[0].to_i
  rescue
    anzahl = 1
  end

  # Sätze entsprechend anzahl ausgeben
  anzahl.times do
    puts satz
  end

end
