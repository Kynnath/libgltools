#
# Generated Makefile - do not edit!
#
# Edit the Makefile in the project folder instead (../Makefile). Each target
# has a -pre and a -post target defined where you can add customized code.
#
# This makefile implements configuration specific macros and targets.


# Environment
MKDIR=mkdir
CP=cp
GREP=grep
NM=nm
CCADMIN=CCadmin
RANLIB=ranlib
CC=gcc.exe
CCC=g++.exe
CXX=g++.exe
FC=gfortran.exe
AS=as.exe

# Macros
CND_PLATFORM=MinGW-Windows
CND_DLIB_EXT=dll
CND_CONF=Release
CND_DISTDIR=dist
CND_BUILDDIR=build

# Include project Makefile
include Makefile

# Object Directory
OBJECTDIR=${CND_BUILDDIR}/${CND_CONF}/${CND_PLATFORM}

# Object Files
OBJECTFILES= \
	${OBJECTDIR}/_ext/196920952/MVPMatrix.o \
	${OBJECTDIR}/src/Frame.o \
	${OBJECTDIR}/src/GLMatrix.o \
	${OBJECTDIR}/src/MatrixStack.o \
	${OBJECTDIR}/src/Model.o \
	${OBJECTDIR}/src/Shader.o \
	${OBJECTDIR}/src/Triangle.o \
	${OBJECTDIR}/src/Vertex.o


# C Compiler Flags
CFLAGS=

# CC Compiler Flags
CCFLAGS=
CXXFLAGS=

# Fortran Compiler Flags
FFLAGS=

# Assembler Flags
ASFLAGS=

# Link Libraries and Options
LDLIBSOPTIONS=

# Build Targets
.build-conf: ${BUILD_SUBPROJECTS}
	"${MAKE}"  -f nbproject/Makefile-${CND_CONF}.mk lib/liblibgltools.a

lib/liblibgltools.a: ${OBJECTFILES}
	${MKDIR} -p lib
	${RM} lib/liblibgltools.a
	${AR} -rv lib/liblibgltools.a ${OBJECTFILES} 
	$(RANLIB) lib/liblibgltools.a

${OBJECTDIR}/_ext/196920952/MVPMatrix.o: /C/Users/JoPe/Documents/NetBeansProjects/libgltools/src/MVPMatrix.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/196920952
	${RM} $@.d
	$(COMPILE.cc) -O3 -Wall -s -DNDEBUG -Iinclude -I../libmatrix/include -I../libvector/include -I/C/lib/glew-1.10.0/include -std=c++11 -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/196920952/MVPMatrix.o /C/Users/JoPe/Documents/NetBeansProjects/libgltools/src/MVPMatrix.cpp

${OBJECTDIR}/src/Frame.o: src/Frame.cpp 
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} $@.d
	$(COMPILE.cc) -O3 -Wall -s -DNDEBUG -Iinclude -I../libmatrix/include -I../libvector/include -I/C/lib/glew-1.10.0/include -std=c++11 -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/Frame.o src/Frame.cpp

${OBJECTDIR}/src/GLMatrix.o: src/GLMatrix.cpp 
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} $@.d
	$(COMPILE.cc) -O3 -Wall -s -DNDEBUG -Iinclude -I../libmatrix/include -I../libvector/include -I/C/lib/glew-1.10.0/include -std=c++11 -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/GLMatrix.o src/GLMatrix.cpp

${OBJECTDIR}/src/MatrixStack.o: src/MatrixStack.cpp 
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} $@.d
	$(COMPILE.cc) -O3 -Wall -s -DNDEBUG -Iinclude -I../libmatrix/include -I../libvector/include -I/C/lib/glew-1.10.0/include -std=c++11 -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/MatrixStack.o src/MatrixStack.cpp

${OBJECTDIR}/src/Model.o: src/Model.cpp 
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} $@.d
	$(COMPILE.cc) -O3 -Wall -s -DNDEBUG -Iinclude -I../libmatrix/include -I../libvector/include -I/C/lib/glew-1.10.0/include -std=c++11 -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/Model.o src/Model.cpp

${OBJECTDIR}/src/Shader.o: src/Shader.cpp 
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} $@.d
	$(COMPILE.cc) -O3 -Wall -s -DNDEBUG -Iinclude -I../libmatrix/include -I../libvector/include -I/C/lib/glew-1.10.0/include -std=c++11 -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/Shader.o src/Shader.cpp

${OBJECTDIR}/src/Triangle.o: src/Triangle.cpp 
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} $@.d
	$(COMPILE.cc) -O3 -Wall -s -DNDEBUG -Iinclude -I../libmatrix/include -I../libvector/include -I/C/lib/glew-1.10.0/include -std=c++11 -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/Triangle.o src/Triangle.cpp

${OBJECTDIR}/src/Vertex.o: src/Vertex.cpp 
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} $@.d
	$(COMPILE.cc) -O3 -Wall -s -DNDEBUG -Iinclude -I../libmatrix/include -I../libvector/include -I/C/lib/glew-1.10.0/include -std=c++11 -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/Vertex.o src/Vertex.cpp

# Subprojects
.build-subprojects:

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r ${CND_BUILDDIR}/${CND_CONF}
	${RM} lib/liblibgltools.a

# Subprojects
.clean-subprojects:

# Enable dependency checking
.dep.inc: .depcheck-impl

include .dep.inc
