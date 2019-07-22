CXX ?= g++
NAVIO = ../../Navio
INCLUDES = -I ../../Navio

all:
	$(MAKE) -C ../../Navio all
	$(CXX) -std=c++11 $(INCLUDES) AHRS.cpp main.cpp -L$(NAVIO) -lnavio -o AHRS -lrt -lpthread
	$(CXX) -std=c++11 $(INCLUDES) -fpic -shared AHRS.cpp -L$(NAVIO) -lnavio2 -o libAHRS -lrt -lpthread 
clean:
	rm -f AHRS
