import fnmatch
import os

# A few constants
SUFFIX = "*.cpp"
OUTPUT = "CMakeLists.txt"

# The output file
outputFile = open(OUTPUT, "w")

# Return the full path to all files respecting the pattern
def getFiles(dir_, patterns="*", recursive=True):
    patterns = patterns.split()
    retValue = []
    for path, dirs, files in os.walk(dir_):
        for file_ in files:
            for pattern in patterns:
                if fnmatch.fnmatch(file_, pattern):
                    retValue.append(os.path.join(path, file_))
                    break
        if not recursive: break
    return retValue


# Get all files of the current working directory ending with *.cpp
def getAllFilenames():
    allFiles = getFiles(os.getcwd(), SUFFIX , False) 
    return [ os.path.basename(file_)[:-len(SUFFIX)+1] for file_ in allFiles ]

# Create the CMakeLists.txt header for GCC, Clang, and MSVC
def getHeader():
    return """# Require a recent version of cmake
cmake_minimum_required(VERSION 2.8.4 FATAL_ERROR)

# This project is C++ based.
project(seminar)

if(${CMAKE_CXX_COMPILER_ID} STREQUAL GNU)
    set(CMAKE_CXX_FLAGS "-O3 -std=c++14 -pthread")
    if (CMAKE_CXX_COMPILER_VERSION VERSION_LESS 5.0)
	    message(WARNING "!!!! GCC versions must be at least 5.0 !!!!")
        message(WARNING "!!!! Adust the makefile to build with a different compiler. !!!!")
    endif()
elseif (${CMAKE_CXX_COMPILER_ID} STREQUAL Clang)
    set(CMAKE_CXX_FLAGS "-O3 -std=c++14 -pthread")
    if (CMAKE_CXX_COMPILER_VERSION VERSION_LESS 3.5)
        message(WARNING "!!!! Clang version must be at least 3.5 !!!!")
		message(WARNING "!!!! Adust the makefile to build with a different compiler. !!!!")
    endif()
elseif (${CMAKE_CXX_COMPILER_ID} STREQUAL MSVC)
    set(CMAKE_CXX_FLAGS "/Ox /EHsc")
    if (CMAKE_CXX_COMPILER_VERSION VERSION_LESS 19.10)    
        message(WARNING "!!!! MSVC version must be at least 19.10 !!!!")
    endif()	
else()
    message(WARNING "!!! You are using an unsupported compiler! Compilation has only been tested with GCC >= 5.0, Clang >= 3.5, or MSVC >= 19.10. !!!")
endif()
    

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "bin/")

set(CMAKE_VERBOSE_MAKEFILE on)

"""
    
# Create the list of all source files    
def getAllNames(allNames):    
    outNames = "set(example_programs" 
    for entry in allNames:
        outNames += "    " + entry + "\n"
    outNames += "   )"
    outNames += "\n"
    
    return outNames

# Create an executable from the source file
def getTail():
    tail = """foreach(example_program ${example_programs})
  set(sources ${example_program}.cpp)
  source_group("Source Files" FILES{sources})
  add_executable(${example_program} ${sources})
endforeach()"""
    return tail


# Create the CMakeLists.txt
allNames = getAllFilenames()

print >> outputFile, getHeader()

print >> outputFile, getAllNames(allNames)

print >> outputFile, getTail()


