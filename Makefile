CC=gcc

CFLAGS=-O2 -std=c99

SOURCES=heap.c insertion.c selection.c shell.c quick_left.c quick_rand.c
EXEC=$(SOURCES:.c=)
SWEAVE=plots.Rnw
PDF=$(SWEAVE:.Rnw=.pdf)

.cpp:
	$(CC) $(CFLAGS) $< -o $@

.PHONY: all clean test report
all: $(EXEC)

$(PDF): $(SWEAVE)
	R CMD Sweave --pdf $<

data: generate.sh
	./generate.sh

test: all data test.sh
	./test.sh $(EXEC)

clean:
	rm -r $(EXEC) out data $(PDF)

report: test $(PDF)
