.PHONY:all
all:db_test order_server
db_test:db_test.cc
	g++ $^ -o $@ -L/usr/lib64/mysql -lmysqlclient -ljsoncpp

order_server:order_server.cc
	g++ $^ -o $@ -L/usr/lib64/mysql -lmysqlclient -ljsoncpp -std=c++11 -lpthread

.PHONY:clean
clean:
	rm db_test order_server
