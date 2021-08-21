all:collect2 tdata

collect2:collect2.cpp
	g++ -g3 -o $@ $<

tdata:tdata.cpp
	g++ -g3 -o $@ $< -lX11

clean:
	rm -f collect2 collect2.j tdata tdata.j *~
