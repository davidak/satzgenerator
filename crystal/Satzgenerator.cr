struct Tuple
  def sample
    self[rand({{@type.size}})]
  end
end

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
  VORNAMEN = lese("../data/vornamen_w.txt").concat(lese("../data/vornamen_m.txt"))
  VERBEN = lese("../data/verben.txt")
  ADJEKTIVE = lese("../data/adjektive.txt")
  ORTE = lese("../data/orte.txt")

  # Listen
  BEZIEHUNG_M = {"Vater", "Bruder", "Mann", "Sohn", "Onkel", "Opa", "Cousin", "Freund", "Kollege", "Mitbewohner"}
  BEZIEHUNG_W = {"Mutter", "Schwester", "Frau", "Tochter", "Tante", "Oma", "Cousine", "Freundin", "Kollegin", "Mitbewohnerin"}
  BEZIEHUNG = Tuple.new(*BEZIEHUNG_M, *BEZIEHUNG_W)
  POSSESSIVPRONOMEN_M = {"Mein", "Dein", "Sein", "Ihr"}
  SPEZIAL = {"Er", "Sie", "Jemand", "Niemand", "Ein Lehrer", "Ein Polizist", "Ein Beamter", "Ein Arzt", "Der Alkoholiker", "Ein normaler Mensch"}

  # Person generieren
  def person(io)
    case rand(6)
    when 0
      io << VORNAMEN.sample << "s " << BEZIEHUNG.sample
    when 1
      io << POSSESSIVPRONOMEN_M.sample << ' ' << BEZIEHUNG_M.sample
    when 2
      io << POSSESSIVPRONOMEN_M.sample << "e " << BEZIEHUNG_W.sample
    when 3
      io << SPEZIAL.sample
    else
      io << VORNAMEN.sample
    end
  end

  # Satz generieren
  def satz(io)
    person(io)
    io << ' ' << VERBEN.sample << ' ' << ADJEKTIVE.sample << ' ' << ORTE.sample << ".\n"
  end

end

# anzahl setzen, wenn eine zahl als parameter angegeben wurde, sonst 1
anzahl = ARGV[0]?.try(&.to_i?) || 1

# Sätze entsprechend anzahl ausgeben
anzahl.times do
  Satzgenerator.satz(STDOUT)
end
