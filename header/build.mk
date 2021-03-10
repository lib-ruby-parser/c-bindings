ALL_HEADERS = $(wildcard src/*.h)
HEADER = target/lib-ruby-parser.h

$(HEADER): $(ALL_HEADERS)
	bash header/build.sh
