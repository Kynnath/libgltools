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
CC=gcc
CCC=g++
CXX=g++
FC=gfortran
AS=as

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
	${OBJECTDIR}/src/GLT/Frame.o \
	${OBJECTDIR}/src/GLT/GLMatrix.o \
	${OBJECTDIR}/src/GLT/GeometryTransform.o \
	${OBJECTDIR}/src/GLT/Image.o \
	${OBJECTDIR}/src/GLT/MVPMatrix.o \
	${OBJECTDIR}/src/GLT/MatrixStack.o \
	${OBJECTDIR}/src/GLT/Model.o \
	${OBJECTDIR}/src/GLT/Shader.o \
	${OBJECTDIR}/src/GLT/Texture.o \
	${OBJECTDIR}/src/GLT/Triangle.o \
	${OBJECTDIR}/src/GLT/Vertex.o \
	${OBJECTDIR}/src/GLT/VertexArray.o


# C Compiler Flags
CFLAGS=

# CC Compiler Flags
CCFLAGS=-m64 -std=c++14 -Wfatal-errors -Wall -Wextra -pedantic -Winit-self -Wmissing-include-dirs -Wswitch-default -Wswitch-enum -Wswitch-default -Wfloat-equal -Wshadow -Wcast-qual -Wcast-align -Wwrite-strings -Wconversion -Wsign-conversion -Wlogical-op -Wmissing-declarations -Wmissing-noreturn -Wmissing-format-attribute -Wpacked -Wredundant-decls -Wunreachable-code -Winvalid-pch -Wvolatile-register-var -Wdisabled-optimization -Wstack-protector
CXXFLAGS=-m64 -std=c++14 -Wfatal-errors -Wall -Wextra -pedantic -Winit-self -Wmissing-include-dirs -Wswitch-default -Wswitch-enum -Wswitch-default -Wfloat-equal -Wshadow -Wcast-qual -Wcast-align -Wwrite-strings -Wconversion -Wsign-conversion -Wlogical-op -Wmissing-declarations -Wmissing-noreturn -Wmissing-format-attribute -Wpacked -Wredundant-decls -Wunreachable-code -Winvalid-pch -Wvolatile-register-var -Wdisabled-optimization -Wstack-protector

# Fortran Compiler Flags
FFLAGS=

# Assembler Flags
ASFLAGS=

# Link Libraries and Options
LDLIBSOPTIONS=

# Build Targets
.build-conf: ${BUILD_SUBPROJECTS}
	"${MAKE}"  -f nbproject/Makefile-${CND_CONF}.mk ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/liblibgltools.a

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/liblibgltools.a: ${OBJECTFILES}
	${MKDIR} -p ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}
	${RM} ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/liblibgltools.a
	${AR} -rv ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/liblibgltools.a ${OBJECTFILES} 
	$(RANLIB) ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/liblibgltools.a

${OBJECTDIR}/src/GLT/Frame.o: src/GLT/Frame.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/GLT
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -Werror -s -DGLEW_STATIC -I../../../lib/glew-1.12.0/include -I../libmatrix/src -I../libvector/src -I../libtools/src -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/GLT/Frame.o src/GLT/Frame.cpp

${OBJECTDIR}/src/GLT/GLMatrix.o: src/GLT/GLMatrix.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/GLT
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -Werror -s -DGLEW_STATIC -I../../../lib/glew-1.12.0/include -I../libmatrix/src -I../libvector/src -I../libtools/src -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/GLT/GLMatrix.o src/GLT/GLMatrix.cpp

${OBJECTDIR}/src/GLT/GeometryTransform.o: src/GLT/GeometryTransform.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/GLT
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -Werror -s -DGLEW_STATIC -I../../../lib/glew-1.12.0/include -I../libmatrix/src -I../libvector/src -I../libtools/src -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/GLT/GeometryTransform.o src/GLT/GeometryTransform.cpp

${OBJECTDIR}/src/GLT/Image.o: src/GLT/Image.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/GLT
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -Werror -s -DGLEW_STATIC -I../../../lib/glew-1.12.0/include -I../libmatrix/src -I../libvector/src -I../libtools/src -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/GLT/Image.o src/GLT/Image.cpp

${OBJECTDIR}/src/GLT/MVPMatrix.o: src/GLT/MVPMatrix.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/GLT
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -Werror -s -DGLEW_STATIC -I../../../lib/glew-1.12.0/include -I../libmatrix/src -I../libvector/src -I../libtools/src -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/GLT/MVPMatrix.o src/GLT/MVPMatrix.cpp

${OBJECTDIR}/src/GLT/MatrixStack.o: src/GLT/MatrixStack.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/GLT
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -Werror -s -DGLEW_STATIC -I../../../lib/glew-1.12.0/include -I../libmatrix/src -I../libvector/src -I../libtools/src -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/GLT/MatrixStack.o src/GLT/MatrixStack.cpp

${OBJECTDIR}/src/GLT/Model.o: src/GLT/Model.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/GLT
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -Werror -s -DGLEW_STATIC -I../../../lib/glew-1.12.0/include -I../libmatrix/src -I../libvector/src -I../libtools/src -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/GLT/Model.o src/GLT/Model.cpp

${OBJECTDIR}/src/GLT/Shader.o: src/GLT/Shader.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/GLT
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -Werror -s -DGLEW_STATIC -I../../../lib/glew-1.12.0/include -I../libmatrix/src -I../libvector/src -I../libtools/src -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/GLT/Shader.o src/GLT/Shader.cpp

${OBJECTDIR}/src/GLT/Texture.o: src/GLT/Texture.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/GLT
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -Werror -s -DGLEW_STATIC -I../../../lib/glew-1.12.0/include -I../libmatrix/src -I../libvector/src -I../libtools/src -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/GLT/Texture.o src/GLT/Texture.cpp

${OBJECTDIR}/src/GLT/Triangle.o: src/GLT/Triangle.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/GLT
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -Werror -s -DGLEW_STATIC -I../../../lib/glew-1.12.0/include -I../libmatrix/src -I../libvector/src -I../libtools/src -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/GLT/Triangle.o src/GLT/Triangle.cpp

${OBJECTDIR}/src/GLT/Vertex.o: src/GLT/Vertex.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/GLT
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -Werror -s -DGLEW_STATIC -I../../../lib/glew-1.12.0/include -I../libmatrix/src -I../libvector/src -I../libtools/src -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/GLT/Vertex.o src/GLT/Vertex.cpp

${OBJECTDIR}/src/GLT/VertexArray.o: src/GLT/VertexArray.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/GLT
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -Werror -s -DGLEW_STATIC -I../../../lib/glew-1.12.0/include -I../libmatrix/src -I../libvector/src -I../libtools/src -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/GLT/VertexArray.o src/GLT/VertexArray.cpp

# Subprojects
.build-subprojects:

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r ${CND_BUILDDIR}/${CND_CONF}
	${RM} ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/liblibgltools.a

# Subprojects
.clean-subprojects:

# Enable dependency checking
.dep.inc: .depcheck-impl

include .dep.inc
