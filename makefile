lab1: lab1.c
	$(CC) -o $@ $@.c

clean:
	-rm -f *.o
	@echo "All clean!"
