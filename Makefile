all:
	g++ race.cpp -pthread -o race

clean:
	rm race
