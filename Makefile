Program : main.o Account.o oneORtwo.o error_clear.o  
	g++ -o $@ $^

main.o : main.cpp
	g++ -c $^

Account.o : Account.cpp 
	g++ -c $^

checkin.o : checkin.cpp 
	g++ -c $^

error_clear.o : error_clear.cpp 
	g++ -c $^

oneORtwo.o : oneORtwo.cpp 
	g++ -c $^

run : ./Program
	./Program

clean :
	rm -f ./Program
	rm ./main.o ./Account.o ./checkin.o ./error_clear.o 

.PHONY : run clean
