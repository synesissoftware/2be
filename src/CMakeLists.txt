
# ######################################################################## #
# File:     /src/CMakeLists.txt
#
# Purpose:  CMake lists file for 2be core library
#
# Created:  ...
# Updated:  11th August 2025
#
# ######################################################################## #


if(_BUILD_AS_UNIX)

	add_definitions(-DUNIX)
	add_definitions(-Dunix)
endif(_BUILD_AS_UNIX)

if(_BUILD_AS_WIN32)

	if(CMAKE_SIZEOF_VOID_P EQUAL 8)

		message (STATUS "Compiling for 64-bit Windows")

		add_definitions(-DWIN64)
	else()

		message (STATUS "Compiling for 32-bit Windows")

		add_definitions(-DWIN32)
	endif()
endif(_BUILD_AS_WIN32)

if(MSVC)
	if(MSVC_VERSION LESS 1920)

		add_compile_options("/wd4822")
	endif()

	if(MSVC_VERSION GREATER_EQUAL 1914)

		add_compile_options("/Zc:__cplusplus")

		add_definitions(-D_SILENCE_CXX17_ITERATOR_BASE_CLASS_DEPRECATION_WARNING)
	endif()
endif(MSVC)


set(COMMON_IMPLEMENTATION_FILES

	2be.c
)

add_library(core
	${COMMON_IMPLEMENTATION_FILES}
)

set_target_properties(core PROPERTIES
	OUTPUT_NAME "2be"
)

target_include_directories(core
	PUBLIC
		$<BUILD_INTERFACE:${CMAKE_SOURCE_DIR}/include>
		$<INSTALL_INTERFACE:include>
)

target_link_libraries(core
	PRIVATE
		$<$<STREQUAL:${STLSOFT_INCLUDE_DIR},>:STLSoft::STLSoft>
		$<$<BOOL:${UNIXem_FOUND}>:UNIXem::UNIXem>
)

target_compile_options(core
	PRIVATE
		$<$<OR:$<CXX_COMPILER_ID:Clang>,$<CXX_COMPILER_ID:AppleClang>,$<CXX_COMPILER_ID:GNU>>:
			-Werror -Wall -Wextra -pedantic

			-Wno-deprecated-copy
			$<$<BOOL:CMAKE_CXX_STANDARD GREATER_EQUAL 2000>:-Wno-deprecated-volatile>
		>
		$<$<CXX_COMPILER_ID:MSVC>:
			/WX /W4
		>
)


# ##########################################################
# install

install(TARGETS core
	EXPORT project-targets
	ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}
	LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
	RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
	# PUBLIC_HEADER DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}/${PROJECT_NAME_LOWER}
)

# install the include/2be/*/ subdirectories here, as do not (yet) know how to do so via PUBLIC_HEADER property
install(
	DIRECTORY ${CMAKE_SOURCE_DIR}/include/${PROJECT_NAME_LOWER}/
	DESTINATION include/${PROJECT_NAME_LOWER}
	FILES_MATCHING
	PATTERN "*.h*"
)


# ############################## end of file ############################# #

