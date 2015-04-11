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
	${OBJECTDIR}/1.\ Static/Static.o \
	${OBJECTDIR}/2.\ Friends/Friends.o \
	${OBJECTDIR}/3.\ This/This.o \
	${OBJECTDIR}/4.\ Operatoru\ pardefinesana/OperPard.o


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
	"${MAKE}"  -f nbproject/Makefile-${CND_CONF}.mk ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/class_property_samples.exe

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/class_property_samples.exe: ${OBJECTFILES}
	${MKDIR} -p ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}
	${LINK.cc} -o ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/class_property_samples ${OBJECTFILES} ${LDLIBSOPTIONS}

.NO_PARALLEL:${OBJECTDIR}/1.\ Static/Static.o
${OBJECTDIR}/1.\ Static/Static.o: 1.\ Static/Static.cpp 
	${MKDIR} -p ${OBJECTDIR} Static
	${RM} "$@.d"
	$(COMPILE.cc) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/1.\ Static/Static.o 1.\ Static/Static.cpp

.NO_PARALLEL:${OBJECTDIR}/2.\ Friends/Friends.o
${OBJECTDIR}/2.\ Friends/Friends.o: 2.\ Friends/Friends.cpp 
	${MKDIR} -p ${OBJECTDIR} Friends
	${RM} "$@.d"
	$(COMPILE.cc) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/2.\ Friends/Friends.o 2.\ Friends/Friends.cpp

.NO_PARALLEL:${OBJECTDIR}/3.\ This/This.o
${OBJECTDIR}/3.\ This/This.o: 3.\ This/This.cpp 
	${MKDIR} -p ${OBJECTDIR} This
	${RM} "$@.d"
	$(COMPILE.cc) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/3.\ This/This.o 3.\ This/This.cpp

.NO_PARALLEL:${OBJECTDIR}/4.\ Operatoru\ pardefinesana/OperPard.o
${OBJECTDIR}/4.\ Operatoru\ pardefinesana/OperPard.o: 4.\ Operatoru\ pardefinesana/OperPard.cpp 
	${MKDIR} -p ${OBJECTDIR} pardefinesana
	${RM} "$@.d"
	$(COMPILE.cc) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/4.\ Operatoru\ pardefinesana/OperPard.o 4.\ Operatoru\ pardefinesana/OperPard.cpp

# Subprojects
.build-subprojects:

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r ${CND_BUILDDIR}/${CND_CONF}
	${RM} ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/class_property_samples.exe

# Subprojects
.clean-subprojects:

# Enable dependency checking
.dep.inc: .depcheck-impl

include .dep.inc
