all: genie java
.PHONY: all genie java

genie:
	cd genie ; valac satzgenerator.gs

java:
	cd java ; javac Satzgenerator.java

test:
	@(./test.sh)
