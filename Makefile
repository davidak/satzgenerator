all: genie java crystal
.PHONY: all genie java crystal

genie:
	cd genie ; valac satzgenerator.gs

java:
	cd java ; javac Satzgenerator.java

crystal:
	cd crystal ; crystal build Satzgenerator.cr --release

test:
	@(./test.sh)
