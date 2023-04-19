cmake_minimum_required(VERSION 3.8)
project( cppCodes )


include_directories( 
                      include   )


add_executable( Image src/image_lib.cpp 
                         src/main.cpp                             
              )