# THIS IS A WORK IN PROGRESS   :)

#AM_LDFLAGS=-L/usr/lib/mysql -lmysqlclient

DBMSCPP_FILES = $(wildcard *.cpp)
DBMSOBJ_FILES := $(DBMSCPP_FILES:.cpp=.o)
DBMSSO_FILES := $(DBMSOBJ_FILES:.o=.so)

all : $(DBMSOBJ_FILES) $(DBMSSO_FILES)
	@echo "All DBMS libraries built!"

%.so : %.o
	$(CXX) $(LDFLAGS) -shared -o $@ $<

%.o : %.cpp
	$(CXX) -Wall -fPIC -c $(CXXFLAGS) $(CPPFLAGS) -o $@ $<

distclean: clean

clean :
	rm -f *.o *.so