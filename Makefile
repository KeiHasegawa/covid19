all:gather TAGS

gather:01_gather.cpp
	g++ -g3 -o $@ $< -lX11

TAGS:gather
	mktags.exe -e $<

clean:
	rm -f gather 01_gather.j TAGS *~
