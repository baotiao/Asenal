WORKROOT=../../

LIBNAME = ullib

BIN_DIR = bin
SRC_DIR = src
SRC_DEPRECATED_DIR = src/dep
LIB_DIR = lib

INCLUDE = -I./include 

ifeq ($(shell uname -m), x86_64)
	INSTALL_PATH=$(WORKROOT)lib2-64/ullib
else
	INSTALL_PATH=$(WORKROOT)lib2/ullib
endif

LIB     =  

SOURCES = $(wildcard $(SRC_DIR)/*.cpp) $(wildcard $(SRC_DEPRECATED_DIR)/*.cpp)
OBJS = $(patsubst %.cpp,%.o,$(SOURCES))

COMMON_DEFINES = -DLINUX -D_REENTERANT
GCC4_IGNORE_WARNINGS= -Wno-write-strings

ifeq "$(MAKECMDGOALS)" "release"
	DEFINES=$(COMMON_DEFINES) -DNDEBUG
	CXXFLAGS= -fPIC -O2 -fsigned-char -Wall -W $(DEFINES) $(INCLUDE) $(GCC4_IGNORE_WARNINGS)
else
	ifeq "$(MAKECMDGOALS)" "withpg"
		DEFINES=$(COMMON_DEFINES)
		CXXFLAGS= -fPIC -g -pg -fsigned-char -Wall -W $(DEFINES) $(INCLUDE) $(GCC4_IGNORE_WARNINGS)
	else
		DEFINES=$(COMMON_DEFINES)
		CXXFLAGS= -fPIC -g -fsigned-char -Wall -W $(DEFINES) $(INCLUDE) $(GCC4_IGNORE_WARNINGS)
	endif
endif

CXX = g++ 
AR  = ar
#=========================================================================
OUTPUT_LIB=lib$(LIBNAME).a
OUTPUT_PATH=./output


#-----------------------------------------------------------------#
# make all
#-----------------------------------------------------------------#
all: clean outputdir

outputdir: output
	if [ ! -d $(OUTPUT_PATH) ]; then mkdir $(OUTPUT_PATH); fi
	if [ ! -d $(OUTPUT_PATH)/lib ]; then mkdir $(OUTPUT_PATH)/lib; fi
	if [ ! -d $(OUTPUT_PATH)/include ]; then mkdir $(OUTPUT_PATH)/include; fi
	if [ ! -d $(OUTPUT_PATH)/include/dep ]; then mkdir $(OUTPUT_PATH)/include/dep; fi
	if [ ! -d $(OUTPUT_PATH)/include/comlog ]; then mkdir $(OUTPUT_PATH)/include/comlog; fi
	if [ ! -d $(OUTPUT_PATH)/include/comlog/appender ]; then mkdir $(OUTPUT_PATH)/include/comlog/appender; fi
	if [ ! -d $(OUTPUT_PATH)/include/comlog/sendsvr ]; then mkdir $(OUTPUT_PATH)/include/comlog/sendsvr; fi
	if [ ! -d $(OUTPUT_PATH)/include/comlog/comempool ]; then mkdir $(OUTPUT_PATH)/include/comlog/comempool; fi
	cp lib/$(OUTPUT_LIB) $(OUTPUT_PATH)/lib
	cp include/*.h $(OUTPUT_PATH)/include
	cp include/dep/*.h $(OUTPUT_PATH)/include/dep
	cp include/comlog/*.h $(OUTPUT_PATH)/include/comlog
	cp include/comlog/appender/*.h $(OUTPUT_PATH)/include/comlog/appender
	cp include/comlog/sendsvr/*.h $(OUTPUT_PATH)/include/comlog/sendsvr
	cp include/comlog/comempool/*.h $(OUTPUT_PATH)/include/comlog/comempool
#-----------------------------------------------------------------#
# make library
#-----------------------------------------------------------------#
output: $(OBJS) 
	make -C src/comlog
	if [ ! -d $(LIB_DIR) ]; then mkdir $(LIB_DIR); fi
	ar -ruv $(LIB_DIR)/$(OUTPUT_LIB) $(OBJS) $(SRC_DIR)/comlog/*.o $(SRC_DIR)/comlog/*/*.o

	mkdir -p output/dict
	cp src/ul_url_default_dict.txt output/dict

$(OBJS): %.o: %.cpp
	$(CXX) -c $< -o $@ $(INCLUDE) $(LIB) $(CXXFLAGS)
    
deps :
	$(CXX) -MM -MG *.cpp >depends

-include depends 

#-----------------------------------------------------------------#
# make clean
#-----------------------------------------------------------------#
clean:
	rm -f $(OBJS) $(LIB_DIR)/*.a
	if [ -d $(OUTPUT_PATH) ]; then rm  -r $(OUTPUT_PATH); fi
	make -C $(SRC_DIR)/comlog clean

#-----------------------------------------------------------------#
# make install
#-----------------------------------------------------------------#
install: outputdir
	if [ ! -d $(INSTALL_PATH) ]; then mkdir -p $(INSTALL_PATH); fi
	cp -rf $(OUTPUT_PATH)/* $(INSTALL_PATH)
