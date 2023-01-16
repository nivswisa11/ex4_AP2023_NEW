make:
	g++ -o client.out -std=c++11 client/*.h client/*.cpp
	g++ -o server.out -std=c++11 server/*.h server/*.cpp
