# The name of our project is "lmc".  CMakeLists files in this project can
# refer to the root source directory of the project as ${LMC_SOURCE_DIR} and
# to the root binary directory of the project as ${LMC_BINARY_DIR}.

cmake_minimum_required(VERSION 2.4)
if(COMMAND cmake_policy)
	cmake_policy(SET CMP0003 NEW)
endif(COMMAND cmake_policy)

PROJECT(LMC)

# Compiler and path settings:
SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${OPTIMIZATION_FLAGS}" CACHE INTERNAL "Compiler optimization flags.")
SET(EXECUTABLE_OUTPUT_PATH ${LMC_BINARY_DIR}/bin CACHE INTERNAL "Single output directory for executables.")
SET(LIBRARY_OUTPUT_PATH ${LMC_BINARY_DIR}/lib CACHE INTERNAL "Single output directory for libraries.")
SET(OPTIMIZATION_FLAGS "-O3 -funroll-loops -Wall" CACHE STRING "Compiler optimization flags.")
SET(SWIG_DIR /usr/local CACHE STRING "directory containing SWIG.")

# Wrappers:

# Define statements:
#OPTION(ENABLE_DOXYGEN "use Doxgen to build developer documentation" 1)
#OPTION(WRAP_PYTHON "use structure library from python" 0)
#OPTION(WRAP_JAVA "use structure library from java" 0)

# Advanced options in the ccmake gui:

#Set up definitions and libraries:

#################################

#write a configure file 
FILE(WRITE ${LMC_SOURCE_DIR}/src/config.h "//configure file for lmc\n")
FILE(APPEND ${LMC_SOURCE_DIR}/src/config.h "#define _LMC_SRC_PATH \"${LMC_SOURCE_DIR}\"\n")

#################################

#Set up source files:
AUX_SOURCE_DIRECTORY(src LMC_SRC)

#################################
#find_package(Doxygen)
#IF(DOXYGEN_FOUND)
#	OPTION(ENABLE_DOXYGEN "Enables building of documentation with doxygen" 1)
#	IF(ENABLE_DOXYGEN)
#		ADD_SUBDIRECTORY(dox)
#		#ADD_CUSTOM_TARGET(doc ALL ${DOXYGEN_EXECUTABLE} ${TPS_SOURCE_DIR}/Doxyfile)
#	ENDIF(ENABLE_DOXYGEN)
#ENDIF(DOXYGEN_FOUND)
#################################

#################################

#make lmc.h header file:

FILE(GLOB HEADER_FILES "${LMC_SOURCE_DIR}/src/*.h")
STRING(REPLACE "${LMC_SOURCE_DIR}/src/lmc.h;" "" HEADER_FILES "${HEADER_FILES}")
STRING(REPLACE "${LMC_SOURCE_DIR}/src/" "" HEADER_FILES "${HEADER_FILES}")
FILE(WRITE ${LMC_SOURCE_DIR}/src/lmc.h "#ifndef _LMC_H\n#define _LMC_H\n\n")
FOREACH(_FILENAME ${HEADER_FILES})
	FILE(APPEND ${LMC_SOURCE_DIR}/src/lmc.h "#include \"${_FILENAME}\"\n")
ENDFOREACH(_FILENAME ${HEADER_FILES})
FILE(APPEND ${LMC_SOURCE_DIR}/src/lmc.h "\n#endif\n\n") 

#install headers:

FILE(GLOB files "${LMC_SOURCE_DIR}/src/*.h*")
INSTALL(FILES ${files} DESTINATION ${CMAKE_INSTALL_PREFIX}/include/lmc)

################################

# Create a library called "lmc" 
# note: some of these variables will be empty if not defined

ADD_LIBRARY(lmc 
	${LMC_SRC} ${THIRD_PARTY_SRC}
)

TARGET_LINK_LIBRARIES(lmc ${LIBRARIES_USED})

INSTALL(TARGETS lmc
			RUNTIME DESTINATION ${CMAKE_INSTALL_PREFIX}/bin
			LIBRARY DESTINATION ${CMAKE_INSTALL_PREFIX}/lib
            ARCHIVE DESTINATION ${CMAKE_INSTALL_PREFIX}/lib)
			
IF(WRAP_PYTHON)
	ADD_SUBDIRECTORY(wrap/python)
ENDIF(WRAP_PYTHON)


#################################
#ADD_SUBDIRECTORY(unit_tests)
#################################
