build:
	@g++ -std=c++11 -o ./bin/main main.cpp
run: build
	@./bin/main
