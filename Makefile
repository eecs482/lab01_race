all:
	g++ -std=c++20 -ldl -pthread race.cpp libthread.o -o race

clean:
	rm race

# if macos, replace the all line with 
# g++ -std=c++20 race.cpp libthread_macos.o -D_XOPEN_SOURCE -o race
