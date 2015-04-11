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
	${OBJECTDIR}/FileFormat.o \
	${OBJECTDIR}/bitchain/main.o \
	${OBJECTDIR}/faili/Patvaliga\ \(binarie\ faili\)/CREATE.o \
	${OBJECTDIR}/faili/Patvaliga\ \(binarie\ faili\)/FILL.o \
	${OBJECTDIR}/faili/Patvaliga\ \(binarie\ faili\)/READ.o \
	${OBJECTDIR}/main.o \
	${OBJECTDIR}/main_1.o \
	${OBJECTDIR}/main_2.o


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
	"${MAKE}"  -f nbproject/Makefile-${CND_CONF}.mk ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/compress_1.exe

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/compress_1.exe: ${OBJECTFILES}
	${MKDIR} -p ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}
	${LINK.cc} -o ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/compress_1 ${OBJECTFILES} ${LDLIBSOPTIONS}

${OBJECTDIR}/FileFormat.o: FileFormat.c 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.c) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/FileFormat.o FileFormat.c

${OBJECTDIR}/bitchain/main.o: bitchain/main.cpp 
	${MKDIR} -p ${OBJECTDIR}/bitchain
	${RM} "$@.d"
	$(COMPILE.cc) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/bitchain/main.o bitchain/main.cpp

.NO_PARALLEL:${OBJECTDIR}/faili/Patvaliga\ \(binarie\ faili\)/CREATE.o
${OBJECTDIR}/faili/Patvaliga\ \(binarie\ faili\)/CREATE.o: faili/Patvaliga\ \(binarie\ faili\)/CREATE.cpp 
	${MKDIR} -p ${OBJECTDIR}/faili  faili\)
	${RM} "$@.d"
	$(COMPILE.cc) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/faili/Patvaliga\ \(binarie\ faili\)/CREATE.o faili/Patvaliga\ \(binarie\ faili\)/CREATE.cpp

.NO_PARALLEL:${OBJECTDIR}/faili/Patvaliga\ \(binarie\ faili\)/FILL.o
${OBJECTDIR}/faili/Patvaliga\ \(binarie\ faili\)/FILL.o: faili/Patvaliga\ \(binarie\ faili\)/FILL.cpp 
	${MKDIR} -p ${OBJECTDIR}/faili  faili\)
	${RM} "$@.d"
	$(COMPILE.cc) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/faili/Patvaliga\ \(binarie\ faili\)/FILL.o faili/Patvaliga\ \(binarie\ faili\)/FILL.cpp

.NO_PARALLEL:${OBJECTDIR}/faili/Patvaliga\ \(binarie\ faili\)/READ.o
${OBJECTDIR}/faili/Patvaliga\ \(binarie\ faili\)/READ.o: faili/Patvaliga\ \(binarie\ faili\)/READ.cpp 
	${MKDIR} -p ${OBJECTDIR}/faili  faili\)
	${RM} "$@.d"
	$(COMPILE.cc) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/faili/Patvaliga\ \(binarie\ faili\)/READ.o faili/Patvaliga\ \(binarie\ faili\)/READ.cpp

${OBJECTDIR}/main.o: main.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/main.o main.cpp

${OBJECTDIR}/main_1.o: main_1.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/main_1.o main_1.cpp

${OBJECTDIR}/main_2.o: main_2.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/main_2.o main_2.cpp

# Subprojects
.build-subprojects:

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r ${CND_BUILDDIR}/${CND_CONF}
	${RM} ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/compress_1.exe

# Subprojects
.clean-subprojects:

# Enable dependency checking
.dep.inc: .depcheck-impl

include .dep.inc
