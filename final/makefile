
# Makefile for f2022, ecs36b
# https://macappstore.org/libjson-rpc-cpp/
# https://github.com/cinemast/libjson-rpc-cpp

CC = g++ -std=c++17
CFLAGS = -g

# LDFLAGS = 	-L/Users/sfwu/vcpkg/installed/arm64-osx/lib -ljsoncpp -L/opt/homebrew/lib/ -lmicrohttpd -ljsonrpccpp-common -ljsonrpccpp-server -ljsonrpccpp-client -lcurl

LDFLAGS = 	 -ljsoncpp -lmicrohttpd -ljsonrpccpp-common -ljsonrpccpp-server -ljsonrpccpp-client -lcurl

# INC	=	#ecs36b_Common.h
# INC_CL	=	 #JvTime.h Person.h Thing.h GPS_DD.h 
# OBJ	=	#JvTime.o Person.o Thing.o GPS_DD.o

# rules.
all: finalClient finalServer

#
#
# <target> : [... tab...] <dependency>
# [... tab ....] <action>

finalClient.h:		params.json
	jsonrpcstub params.json --cpp-server=finalServer --cpp-client=finalClient $(LDFLAGS)

finalServer.h:		params.json
	jsonrpcstub params.json --cpp-server=finalServer --cpp-client=finalClient $(LDFLAGS)

finalClient.o:		finalClient.cpp finalClient.h 
	$(CC) -c $(CFLAGS) finalClient.cpp $(LDFLAGS)

finalServer.o:		finalServer.cpp finalServer.h 
	$(CC) -c $(CFLAGS) finalServer.cpp $(LDFLAGS)

# clean:
# 	rm -f *.o *~ core hw5client.h hw5server.h hw5client hw5server hw5Home hw5Forest hw5GrandmaHome Thing Person