// Satzgenerator in Go
package main

import (
	"fmt"
	"io/ioutil"
	"math/rand"
	"os"
	"strconv"
	"strings"
	"time"
)

// declare some variables
var vornamen_m, vornamen_w, vornamen, verben, adjektive, orte []string
var beziehung_m = []string{"Vater", "Bruder", "Mann", "Sohn", "Onkel", "Opa", "Cousin", "Freund", "Kollege", "Mitbewohner"}
var beziehung_w = []string{"Mutter", "Schwester", "Frau", "Tochter", "Tante", "Oma", "Cousine", "Freundin", "Kollegin", "Mitbewohnerin"}
var beziehung = append(beziehung_m, beziehung_w...)
var possessivpronomen_m = []string{"Mein", "Dein", "Sein", "Ihr"}
var spezial = []string{"Er", "Sie", "Jemand", "Niemand", "Ein Lehrer", "Ein Polizist", "Ein Beamter", "Ein Arzt", "Der Alkoholiker", "Ein normaler Mensch"}

// read file and return array of strings (lines)
func readlines(path string) []string {
	val, err := ioutil.ReadFile(path)
	if err != nil {
		fmt.Println("error:", err)
		os.Exit(1)
	}
	return strings.Split(string(val), "\n")
}

// returns a random element from an array of strings
func choice(seq []string) string {
	return seq[rand.Intn(len(seq))]
}

func person() string {
	switch rand.Intn(5) {
	case 0:
		return fmt.Sprintf("%ss %s", choice(vornamen), choice(beziehung))
	case 1:
		return fmt.Sprintf("%s %s", choice(possessivpronomen_m), choice(beziehung_m))
	case 2:
		return fmt.Sprintf("%se %s", choice(possessivpronomen_m), choice(beziehung_w))
	case 3:
		return choice(spezial)
	default:
		return choice(vornamen)
	}
}

func main() {
	// initialize global pseudo random generator
	rand.Seed(time.Now().Unix())

	// read data from files
	vornamen_m = readlines("../data/vornamen_m.txt")
	vornamen_w = readlines("../data/vornamen_w.txt")
	vornamen = append(vornamen_m, vornamen_w...)
	verben = readlines("../data/verben.txt")
	adjektive = readlines("../data/adjektive.txt")
	orte = readlines("../data/orte.txt")

	count := 1
	// set count to number from first parameter when given
	if len(os.Args) > 1 {
		val, err := strconv.Atoi(os.Args[1])
		if err != nil {
			fmt.Printf("error: parameter %v is not a number\n", os.Args[1])
			os.Exit(1)
		}
		count = val
	}

	// generate sentences
	for i := 0; i < count; i++ {
		fmt.Println(person(), choice(verben), choice(adjektive), choice(orte)+".")
	}
}
