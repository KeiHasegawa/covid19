all:collect2 tdata date_sample

collect2:collect2.cpp
	g++ -g3 -o $@ $<

tdata:tdata.cpp
	g++ -g3 -o $@ $< -lX11

date_sample:date_sample.cpp
	g++ -g3 -o $@ $< -lrt

clean:
	rm -f collect2 collect2.j tdata tdata.j date_sample date_sample.j *~
	rm -f TAGS

