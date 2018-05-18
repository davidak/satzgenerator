package main

import "testing"

func TestReadlines(t *testing.T) {
  val := readlines("../data/vornamen_w.txt")
  // test if first line is as expected
  if got, want := val[0], "Adelheid"; got != want {
    t.Fatalf("readlines(): unexpected value: got %v, want %s", got , want)
  }
  // test if last line is as expected
  if got, want := val[len(val)-1], "Zoe"; got != want {
    t.Fatalf("readlines(): unexpected value: got %v, want %s", got , want)
  }
}

// TODO: expect error with empty path

func BenchmarkReadlines(b *testing.B) {
  for n := 0; n < b.N; n++ {
    readlines("../data/vornamen_w.txt")
  }
}

func BenchmarkChoice(b *testing.B) {
  items := []string{"Er", "Sie", "Jemand", "Niemand", "Ein Lehrer", "Ein Polizist", "Ein Beamter", "Ein Arzt", "Der Alkoholiker", "Ein normaler Mensch"}
  for n := 0; n < b.N; n++ {
    choice(items)
  }
}
