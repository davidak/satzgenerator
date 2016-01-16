default: all

genie:
	@(cd genie ; valac satzgenerator.gs)

all: genie

test:
	@(./test.sh)
