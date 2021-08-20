all:collect2

collect2:collector2.cpp
	g++ -g3 -o $@ $<

clean:
	rm -f collect2 collect2.j *~
