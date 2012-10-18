TESTCPP_FILES = $(wildcard *.cpp)
TESTOBJ_FILES := $(TESTCPP_FILES:.cpp=.o)
TESTSO_FILES := $(TESTOBJ_FILES:.o=.so)

all : $(TESTOBJ_FILES) $(TESTSO_FILES)
	@echo "All benchmark libraries built!"

%.so : %.o
	$(CXX) $(LDFLAGS) -shared -o $@ $<

%.o : %.cpp
	$(CXX) -Wall -fPIC -c $(CXXFLAGS) $(CPPFLAGS) -o $@ $<

distclean: clean

clean :
	rm -f *.o *.so