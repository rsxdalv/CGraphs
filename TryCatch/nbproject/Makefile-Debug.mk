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
CC=cl
CCC=g++
CXX=g++
FC=gfortran
AS=as

# Macros
CND_PLATFORM=Visual_Studio_10-Windows
CND_DLIB_EXT=dll
CND_CONF=Debug
CND_DISTDIR=dist
CND_BUILDDIR=build

# Include project Makefile
include Makefile

# Object Directory
OBJECTDIR=${CND_BUILDDIR}/${CND_CONF}/${CND_PLATFORM}

# Object Files
OBJECTFILES= \
	${OBJECTDIR}/trycatch/trycatch01.o \
	${OBJECTDIR}/trycatch/trycatch02.o \
	${OBJECTDIR}/trycatch/trycatch03.o \
	${OBJECTDIR}/trycatch/trycatch04.o


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
	"${MAKE}"  -f nbproject/Makefile-${CND_CONF}.mk ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/trycatch.exe

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/trycatch.exe: ${OBJECTFILES}
	${MKDIR} -p ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}
	${LINK.cc} -o ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/trycatch ${OBJECTFILES} ${LDLIBSOPTIONS}

${OBJECTDIR}/trycatch/trycatch01.o: trycatch/trycatch01.cpp 
	${MKDIR} -p ${OBJECTDIR}/trycatch
	${RM} "$@.d"
	$(COMPILE.cc) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/trycatch/trycatch01.o trycatch/trycatch01.cpp

${OBJECTDIR}/trycatch/trycatch02.o: trycatch/trycatch02.cpp 
	${MKDIR} -p ${OBJECTDIR}/trycatch
	${RM} "$@.d"
	$(COMPILE.cc) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/trycatch/trycatch02.o trycatch/trycatch02.cpp

${OBJECTDIR}/trycatch/trycatch03.o: trycatch/trycatch03.cpp 
	${MKDIR} -p ${OBJECTDIR}/trycatch
	${RM} "$@.d"
	$(COMPILE.cc) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/trycatch/trycatch03.o trycatch/trycatch03.cpp

${OBJECTDIR}/trycatch/trycatch04.o: trycatch/trycatch04.cpp 
	${MKDIR} -p ${OBJECTDIR}/trycatch
	${RM} "$@.d"
	$(COMPILE.cc) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/trycatch/trycatch04.o trycatch/trycatch04.cpp

# Subprojects
.build-subprojects:

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r ${CND_BUILDDIR}/${CND_CONF}
	${RM} ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/trycatch.exe

# Subprojects
.clean-subprojects:

# Enable dependency checking
.dep.inc: .depcheck-impl

include .dep.inc
