DEBUG   := no


FLAG_DEBUG = -g -D _DEBUG  -fpic -std=c++17 -Wall
FLAG_RELEASE =   -fpic -std=c++17 -Wall

TARGET_DEBUG = libtools.a
TARGET_RELEASE = libtools.a

ifeq (yes, $(DEBUG))
	CFLAG       = $(FLAG_DEBUG)
	TARGET       = $(TARGET_DEBUG)
else
	CFLAG       = $(FLAG_RELEASE)
	TARGET = $(TARGET_RELEASE)
endif



CC = g++
SRC = $(wildcard *.cpp)
OBJ = $(patsubst %.cpp, %.o, $(SRC))

	
INCLUDE = -I../../common \
-I../../message/cpp \
-I../../3rd \
-I../../3rd/protobuf \
-I../../3rd/bsoncxx/v_noabi \
-I../../3rd/mongocxx/v_noabi \
-I../../common/liblog


LIBS := -lboost_system -lpthread -lboost_thread

LIB_DIR := -L../lib

$(TARGET) : $(OBJ)
	ar crv $(TARGET) *.o
	cp -f $(TARGET) ../lib

$(OBJ): %.o: %.cpp
	$(CC) -c $(CFLAG) $(INCLUDE) $< -o $@

all :
	make

.PHONY : clean
clean :
	-rm -f $(TARGET) $(OBJ)
