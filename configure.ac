AC_PREREQ(2.61)
AC_INIT([dnstap], [0.1.0], [todo@dns-oarc.net], [dnstap], [https://github.com/DNS-OARC/dnstap/issues])
AM_INIT_AUTOMAKE([-Wall -Werror foreign subdir-objects])
AC_CONFIG_SRCDIR([src/dnstap.c])
AC_CONFIG_HEADER([src/config.h])
AC_CONFIG_MACRO_DIR([m4])

# Checks for programs.
AC_PROG_CC
AC_PROG_CXX
AM_PROG_CC_C_O
AC_CANONICAL_HOST
m4_ifdef([AM_PROG_AR], [AM_PROG_AR])
LT_INIT
PKG_PROG_PKG_CONFIG
AC_PATH_PROG([PROTOC_C], [protoc-c])
AS_IF([test -z "$PROTOC_C"], [
  AC_MSG_ERROR([The protoc-c program was not found. Please install the protobuf-c compiler!])
])

# Check --enable-warn-all
AC_ARG_ENABLE([warn-all], [AS_HELP_STRING([--enable-warn-all], [Enable all compiler warnings])], [AX_CFLAGS_WARN_ALL()])

# Check --with-extra-cflags
AC_ARG_WITH([extra-cflags], [AS_HELP_STRING([--with-extra-cflags=CFLAGS], [Add extra CFLAGS])], [
  AC_MSG_NOTICE([appending extra CFLAGS... $withval])
  AS_VAR_APPEND(CFLAGS, [" $withval"])
])

# Check --with-extra-ldflags
AC_ARG_WITH([extra-ldflags], [AS_HELP_STRING([--with-extra-ldflags=CFLAGS], [Add extra LDFLAGS])], [
  AC_MSG_NOTICE([appending extra LDFLAGS... $withval])
  AS_VAR_APPEND(LDFLAGS, [" $withval"])
])

# pkg-config
PKG_INSTALLDIR

# Checks for libraries.
PKG_CHECK_MODULES([tinyframe], [libtinyframe >= 0.1.0], , [AC_MSG_ERROR([libtinyframe not found])])
PKG_CHECK_MODULES([protobuf_c], [libprotobuf-c >= 1.0.1])

# Checks for header files.

# Checks for library functions.

# Output Makefiles
AC_CONFIG_FILES([
    Makefile
	libdnstap.pc
    src/Makefile
    src/test/Makefile
])
AC_OUTPUT