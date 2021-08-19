all:gather TAGS

gather:gather.cpp
	g++ -g3 -o $@ $< -lX11

TAGS:gather
	mktags.exe -e $<

clean:
	rm -f gather gather.j TAGS *~
