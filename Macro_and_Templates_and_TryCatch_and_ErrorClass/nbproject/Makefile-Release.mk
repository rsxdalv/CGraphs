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
CND_CONF=Release
CND_DISTDIR=dist
CND_BUILDDIR=build

# Include project Makefile
include Makefile

# Object Directory
OBJECTDIR=${CND_BUILDDIR}/${CND_CONF}/${CND_PLATFORM}

# Object Files
OBJECTFILES= \
	${OBJECTDIR}/ErrorKlase.o \
	${OBJECTDIR}/_uzdevumi/Masivs_Atrisinajums.o \
	${OBJECTDIR}/_uzdevumi/T_Masivs_Atrisinajums.o \
	${OBJECTDIR}/define/define.o \
	${OBJECTDIR}/template/template03.o \
	${OBJECTDIR}/template/template04.o \
	${OBJECTDIR}/trycatch/06.o


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
	"${MAKE}"  -f nbproject/Makefile-${CND_CONF}.mk ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/macro_and_templates_and_trycatch_and_errorclass.exe

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/macro_and_templates_and_trycatch_and_errorclass.exe: ${OBJECTFILES}
	${MKDIR} -p ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}
	${LINK.cc} -o ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/macro_and_templates_and_trycatch_and_errorclass ${OBJECTFILES} ${LDLIBSOPTIONS}

${OBJECTDIR}/ErrorKlase.o: ErrorKlase.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/ErrorKlase.o ErrorKlase.cpp

${OBJECTDIR}/_uzdevumi/Masivs_Atrisinajums.o: _uzdevumi/Masivs_Atrisinajums.cpp 
	${MKDIR} -p ${OBJECTDIR}/_uzdevumi
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_uzdevumi/Masivs_Atrisinajums.o _uzdevumi/Masivs_Atrisinajums.cpp

${OBJECTDIR}/_uzdevumi/T_Masivs_Atrisinajums.o: _uzdevumi/T_Masivs_Atrisinajums.cpp 
	${MKDIR} -p ${OBJECTDIR}/_uzdevumi
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_uzdevumi/T_Masivs_Atrisinajums.o _uzdevumi/T_Masivs_Atrisinajums.cpp

${OBJECTDIR}/define/define.o: define/define.cpp 
	${MKDIR} -p ${OBJECTDIR}/define
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/define/define.o define/define.cpp

${OBJECTDIR}/template/template03.o: template/template03.cpp 
	${MKDIR} -p ${OBJECTDIR}/template
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/template/template03.o template/template03.cpp

${OBJECTDIR}/template/template04.o: template/template04.cpp 
	${MKDIR} -p ${OBJECTDIR}/template
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/template/template04.o template/template04.cpp

${OBJECTDIR}/trycatch/06.o: trycatch/06.cpp 
	${MKDIR} -p ${OBJECTDIR}/trycatch
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/trycatch/06.o trycatch/06.cpp

# Subprojects
.build-subprojects:

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r ${CND_BUILDDIR}/${CND_CONF}
	${RM} ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/macro_and_templates_and_trycatch_and_errorclass.exe

# Subprojects
.clean-subprojects:

# Enable dependency checking
.dep.inc: .depcheck-impl

include .dep.inc
