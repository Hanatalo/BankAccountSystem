gcc_options = -std=c++17 -Wall --pedantic-errors -g

Program : main.cpp all.h all.h.gch Account.cpp checkin.cpp
	LC_AL=C g++  $(gcc_options) -include all.h -o Program main.cpp Account.cpp checkin.cpp

all.h.gch : all.h
	LC_AL=C  g++   $(gcc_options) -x c++-header -o all.h.gch all.h


run : ./Program
	./Program

clean :
	rm -f ./Program
	rm -f ./all.h.gch

.PHONY : run clean
