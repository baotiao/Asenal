#COMAKE2 edit-mode: -*- Makefile -*-
####################64Bit Mode####################
ifeq ($(shell uname -m),x86_64)
CC=gcc
CXX=g++
CXXFLAGS=-g \
  -pipe \
  -W \
  -Wall \
  -fPIC
CFLAGS=-g \
  -pipe \
  -W \
  -Wall \
  -fPIC
CPPFLAGS=-D_GNU_SOURCE \
  -D__STDC_LIMIT_MACROS \
  -DVERSION="1.0.0.0"
INCPATH=-I../../include/ \
  -I../../../../com-test/itest/tools/fault/common/ \
  -I../../../../com-test/itest/tools/fault/api
DEP_INCPATH=-I../../../../com-test/itest/tools/fault \
  -I../../../../com-test/itest/tools/fault/include \
  -I../../../../com-test/itest/tools/fault/output \
  -I../../../../com-test/itest/tools/fault/output/include \
  -I../../../../com/btest/gtest \
  -I../../../../com/btest/gtest/include \
  -I../../../../com/btest/gtest/output \
  -I../../../../com/btest/gtest/output/include \
  -I../../../../com/idlcompiler \
  -I../../../../com/idlcompiler/include \
  -I../../../../com/idlcompiler/output \
  -I../../../../com/idlcompiler/output/include \
  -I../../../../lib2-64/bsl \
  -I../../../../lib2-64/bsl/include \
  -I../../../../lib2-64/bsl/output \
  -I../../../../lib2-64/bsl/output/include \
  -I../../../../lib2-64/dict \
  -I../../../../lib2-64/dict/include \
  -I../../../../lib2-64/dict/output \
  -I../../../../lib2-64/dict/output/include \
  -I../../../../lib2-64/ullib \
  -I../../../../lib2-64/ullib/include \
  -I../../../../lib2-64/ullib/output \
  -I../../../../lib2-64/ullib/output/include \
  -I../../../../op/oped/noah/webfoot/naming-lib \
  -I../../../../op/oped/noah/webfoot/naming-lib/include \
  -I../../../../op/oped/noah/webfoot/naming-lib/output \
  -I../../../../op/oped/noah/webfoot/naming-lib/output/include \
  -I../../../../public/bslext \
  -I../../../../public/bslext/include \
  -I../../../../public/bslext/output \
  -I../../../../public/bslext/output/include \
  -I../../../../public/comlog-plugin \
  -I../../../../public/comlog-plugin/include \
  -I../../../../public/comlog-plugin/output \
  -I../../../../public/comlog-plugin/output/include \
  -I../../../../public/configure \
  -I../../../../public/configure/include \
  -I../../../../public/configure/output \
  -I../../../../public/configure/output/include \
  -I../../../../public/connectpool \
  -I../../../../public/connectpool/include \
  -I../../../../public/connectpool/output \
  -I../../../../public/connectpool/output/include \
  -I../../../../public/idlcompiler \
  -I../../../../public/idlcompiler/include \
  -I../../../../public/idlcompiler/output \
  -I../../../../public/idlcompiler/output/include \
  -I../../../../public/mcpack \
  -I../../../../public/mcpack/include \
  -I../../../../public/mcpack/output \
  -I../../../../public/mcpack/output/include \
  -I../../../../public/nshead \
  -I../../../../public/nshead/include \
  -I../../../../public/nshead/output \
  -I../../../../public/nshead/output/include \
  -I../../../../public/odict \
  -I../../../../public/odict/include \
  -I../../../../public/odict/output \
  -I../../../../public/odict/output/include \
  -I../../../../public/spreg \
  -I../../../../public/spreg/include \
  -I../../../../public/spreg/output \
  -I../../../../public/spreg/output/include \
  -I../../../../public/ub \
  -I../../../../public/ub/include \
  -I../../../../public/ub/output \
  -I../../../../public/ub/output/include \
  -I../../../../public/uconv \
  -I../../../../public/uconv/include \
  -I../../../../public/uconv/output \
  -I../../../../public/uconv/output/include \
  -I../../../../quality/autotest/reportlib/cpp \
  -I../../../../quality/autotest/reportlib/cpp/include \
  -I../../../../quality/autotest/reportlib/cpp/output \
  -I../../../../quality/autotest/reportlib/cpp/output/include \
  -I../../../../third-64/pcre \
  -I../../../../third-64/pcre/include \
  -I../../../../third-64/pcre/output \
  -I../../../../third-64/pcre/output/include \
  -I../../../../third-64/protobuf \
  -I../../../../third-64/protobuf/include \
  -I../../../../third-64/protobuf/output \
  -I../../../../third-64/protobuf/output/include

#============ CCP vars ============
CCHECK=@ccheck.py
CCHECK_FLAGS=
PCLINT=@pclint
PCLINT_FLAGS=
CCP=@ccp.py
CCP_FLAGS=


#COMAKE UUID
COMAKE_MD5=beb85a30da1ef28d8d796e49e098e036  COMAKE


.PHONY:all
all:comake2_makefile_check test_ul_pack_client test_ul_pack_server test_ul_pack_serial test_comlog_hostname test_ul_url test_comlog_level test_comlog_guard test_ullog_level test_com_openlog_r test_comlog_disk test_ulnet_read test_ulnet_write test_write_failure 
	@echo "[[1;32;40mCOMAKE:BUILD[0m][Target:'[1;32;40mall[0m']"
	@echo "make all done"

.PHONY:comake2_makefile_check
comake2_makefile_check:
	@echo "[[1;32;40mCOMAKE:BUILD[0m][Target:'[1;32;40mcomake2_makefile_check[0m']"
	#in case of error, update 'Makefile' by 'comake2'
	@echo "$(COMAKE_MD5)">comake2.md5
	@md5sum -c --status comake2.md5
	@rm -f comake2.md5

.PHONY:ccpclean
ccpclean:
	@echo "[[1;32;40mCOMAKE:BUILD[0m][Target:'[1;32;40mccpclean[0m']"
	@echo "make ccpclean done"

.PHONY:clean
clean:ccpclean
	@echo "[[1;32;40mCOMAKE:BUILD[0m][Target:'[1;32;40mclean[0m']"
	rm -rf test_ul_pack_client
	rm -rf test_ul_pack_server
	rm -rf test_ul_pack_serial
	rm -rf test_comlog_hostname
	rm -rf test_ul_url
	rm -rf test_comlog_level
	rm -rf test_comlog_guard
	rm -rf test_ullog_level
	rm -rf test_com_openlog_r
	rm -rf test_comlog_disk
	rm -rf test_ulnet_read
	rm -rf test_ulnet_write
	rm -rf test_write_failure
	rm -rf test_ul_pack_client_test_ul_pack_client.o
	rm -rf test_ul_pack_server_test_ul_pack_server.o
	rm -rf test_ul_pack_serial_test_ul_pack_serial.o
	rm -rf test_comlog_hostname_test_comlog_hostname.o
	rm -rf test_ul_url_test_ul_url.o
	rm -rf test_comlog_level_test_comlog_level.o
	rm -rf test_comlog_guard_test_comlog_guard.o
	rm -rf test_ullog_level_test_ullog_level.o
	rm -rf test_com_openlog_r_test_com_openlog_r.o
	rm -rf test_comlog_disk_test_comlog_disk.o
	rm -rf test_ulnet_read_test_ulnet_read.o
	rm -rf test_ulnet_write_test_ulnet_write.o
	rm -rf test_write_failure_test_write_failure.o

.PHONY:dist
dist:
	@echo "[[1;32;40mCOMAKE:BUILD[0m][Target:'[1;32;40mdist[0m']"
	tar czvf output.tar.gz output
	@echo "make dist done"

.PHONY:distclean
distclean:clean
	@echo "[[1;32;40mCOMAKE:BUILD[0m][Target:'[1;32;40mdistclean[0m']"
	rm -f output.tar.gz
	@echo "make distclean done"

.PHONY:love
love:
	@echo "[[1;32;40mCOMAKE:BUILD[0m][Target:'[1;32;40mlove[0m']"
	@echo "make love done"

test_ul_pack_client:test_ul_pack_client_test_ul_pack_client.o \
  ../../lib/libullib.a
	@echo "[[1;32;40mCOMAKE:BUILD[0m][Target:'[1;32;40mtest_ul_pack_client[0m']"
	$(CXX) test_ul_pack_client_test_ul_pack_client.o -Xlinker "-(" ../../lib/libullib.a ../../../../com-test/itest/tools/fault/output/lib/libfault.a \
  ../../../../com-test/itest/tools/fault/output/lib/libfault1.a \
  ../../../../com/btest/gtest/output/lib/libgtest.a \
  ../../../../com/btest/gtest/output/lib/libgtest_main.a \
  ../../../../com/idlcompiler/astyle/libastyle.a \
  ../../../../com/idlcompiler/cxx/libskeleton.a \
  ../../../../com/idlcompiler/java/libjava_skeleton.a \
  ../../../../com/idlcompiler/parser/libparser.a \
  ../../../../com/idlcompiler/php/libphp_skeleton.a \
  ../../../../lib2-64/bsl/lib/libbsl.a \
  ../../../../lib2-64/bsl/lib/libbsl_ResourcePool.a \
  ../../../../lib2-64/bsl/lib/libbsl_archive.a \
  ../../../../lib2-64/bsl/lib/libbsl_buffer.a \
  ../../../../lib2-64/bsl/lib/libbsl_check_cast.a \
  ../../../../lib2-64/bsl/lib/libbsl_exception.a \
  ../../../../lib2-64/bsl/lib/libbsl_pool.a \
  ../../../../lib2-64/bsl/lib/libbsl_utils.a \
  ../../../../lib2-64/bsl/lib/libbsl_var.a \
  ../../../../lib2-64/bsl/lib/libbsl_var_implement.a \
  ../../../../lib2-64/bsl/lib/libbsl_var_utils.a \
  ../../../../lib2-64/dict/lib/libuldict.a \
  ../../../../lib2-64/ullib/lib/libullib.a \
  ../../../../op/oped/noah/webfoot/naming-lib/output/lib/libwebfoot_naming.a \
  ../../../../public/bslext/output/lib/libbsl_bml.a \
  ../../../../public/bslext/output/lib/libbsl_containers_utils.a \
  ../../../../public/bslext/output/lib/libbsl_var_scripting.a \
  ../../../../public/bslext/output/lib/libbsl_var_serializer.a \
  ../../../../public/bslext/output/lib/libbsl_var_vscript.a \
  ../../../../public/bslext/output/lib/libbsl_vs.a \
  ../../../../public/bslext/output/lib/libbslext.a \
  ../../../../public/comlog-plugin/libcomlog.a \
  ../../../../public/comlog-plugin/output/lib/libdfsappender.a \
  ../../../../public/configure/libconfig.a \
  ../../../../public/connectpool/libconnectpool.a \
  ../../../../public/idlcompiler/output/lib/libmcpack_idl.a \
  ../../../../public/mcpack/libmcpack.a \
  ../../../../public/nshead/libnshead.a \
  ../../../../public/odict/libodict.a \
  ../../../../public/spreg/libspreg.a \
  ../../../../public/ub/output/lib/libub.a \
  ../../../../public/ub/output/lib/libub_aserver.a \
  ../../../../public/ub/output/lib/libub_client.a \
  ../../../../public/ub/output/lib/libub_conf.a \
  ../../../../public/ub/output/lib/libub_galileo.a \
  ../../../../public/ub/output/lib/libub_log.a \
  ../../../../public/ub/output/lib/libub_misc.a \
  ../../../../public/ub/output/lib/libub_monitor.a \
  ../../../../public/ub/output/lib/libub_naming.a \
  ../../../../public/ub/output/lib/libub_server.a \
  ../../../../public/ub/output/lib/libubex.a \
  ../../../../public/ub/output/lib/libubfw.a \
  ../../../../public/uconv/libuconv.a \
  ../../../../quality/autotest/reportlib/cpp/libautotest.a \
  ../../../../third-64/pcre/lib/libpcre.a \
  ../../../../third-64/pcre/lib/libpcrecpp.a \
  ../../../../third-64/pcre/lib/libpcreposix.a \
  ../../../../third-64/protobuf/lib/libprotobuf-lite.a \
  ../../../../third-64/protobuf/lib/libprotobuf.a \
  ../../../../third-64/protobuf/lib/libprotoc.a -lpthread \
  -lcrypto \
  -lrt -Xlinker "-)" -o test_ul_pack_client

test_ul_pack_server:test_ul_pack_server_test_ul_pack_server.o \
  ../../lib/libullib.a
	@echo "[[1;32;40mCOMAKE:BUILD[0m][Target:'[1;32;40mtest_ul_pack_server[0m']"
	$(CXX) test_ul_pack_server_test_ul_pack_server.o -Xlinker "-(" ../../lib/libullib.a ../../../../com-test/itest/tools/fault/output/lib/libfault.a \
  ../../../../com-test/itest/tools/fault/output/lib/libfault1.a \
  ../../../../com/btest/gtest/output/lib/libgtest.a \
  ../../../../com/btest/gtest/output/lib/libgtest_main.a \
  ../../../../com/idlcompiler/astyle/libastyle.a \
  ../../../../com/idlcompiler/cxx/libskeleton.a \
  ../../../../com/idlcompiler/java/libjava_skeleton.a \
  ../../../../com/idlcompiler/parser/libparser.a \
  ../../../../com/idlcompiler/php/libphp_skeleton.a \
  ../../../../lib2-64/bsl/lib/libbsl.a \
  ../../../../lib2-64/bsl/lib/libbsl_ResourcePool.a \
  ../../../../lib2-64/bsl/lib/libbsl_archive.a \
  ../../../../lib2-64/bsl/lib/libbsl_buffer.a \
  ../../../../lib2-64/bsl/lib/libbsl_check_cast.a \
  ../../../../lib2-64/bsl/lib/libbsl_exception.a \
  ../../../../lib2-64/bsl/lib/libbsl_pool.a \
  ../../../../lib2-64/bsl/lib/libbsl_utils.a \
  ../../../../lib2-64/bsl/lib/libbsl_var.a \
  ../../../../lib2-64/bsl/lib/libbsl_var_implement.a \
  ../../../../lib2-64/bsl/lib/libbsl_var_utils.a \
  ../../../../lib2-64/dict/lib/libuldict.a \
  ../../../../lib2-64/ullib/lib/libullib.a \
  ../../../../op/oped/noah/webfoot/naming-lib/output/lib/libwebfoot_naming.a \
  ../../../../public/bslext/output/lib/libbsl_bml.a \
  ../../../../public/bslext/output/lib/libbsl_containers_utils.a \
  ../../../../public/bslext/output/lib/libbsl_var_scripting.a \
  ../../../../public/bslext/output/lib/libbsl_var_serializer.a \
  ../../../../public/bslext/output/lib/libbsl_var_vscript.a \
  ../../../../public/bslext/output/lib/libbsl_vs.a \
  ../../../../public/bslext/output/lib/libbslext.a \
  ../../../../public/comlog-plugin/libcomlog.a \
  ../../../../public/comlog-plugin/output/lib/libdfsappender.a \
  ../../../../public/configure/libconfig.a \
  ../../../../public/connectpool/libconnectpool.a \
  ../../../../public/idlcompiler/output/lib/libmcpack_idl.a \
  ../../../../public/mcpack/libmcpack.a \
  ../../../../public/nshead/libnshead.a \
  ../../../../public/odict/libodict.a \
  ../../../../public/spreg/libspreg.a \
  ../../../../public/ub/output/lib/libub.a \
  ../../../../public/ub/output/lib/libub_aserver.a \
  ../../../../public/ub/output/lib/libub_client.a \
  ../../../../public/ub/output/lib/libub_conf.a \
  ../../../../public/ub/output/lib/libub_galileo.a \
  ../../../../public/ub/output/lib/libub_log.a \
  ../../../../public/ub/output/lib/libub_misc.a \
  ../../../../public/ub/output/lib/libub_monitor.a \
  ../../../../public/ub/output/lib/libub_naming.a \
  ../../../../public/ub/output/lib/libub_server.a \
  ../../../../public/ub/output/lib/libubex.a \
  ../../../../public/ub/output/lib/libubfw.a \
  ../../../../public/uconv/libuconv.a \
  ../../../../quality/autotest/reportlib/cpp/libautotest.a \
  ../../../../third-64/pcre/lib/libpcre.a \
  ../../../../third-64/pcre/lib/libpcrecpp.a \
  ../../../../third-64/pcre/lib/libpcreposix.a \
  ../../../../third-64/protobuf/lib/libprotobuf-lite.a \
  ../../../../third-64/protobuf/lib/libprotobuf.a \
  ../../../../third-64/protobuf/lib/libprotoc.a -lpthread \
  -lcrypto \
  -lrt -Xlinker "-)" -o test_ul_pack_server

test_ul_pack_serial:test_ul_pack_serial_test_ul_pack_serial.o \
  ../../lib/libullib.a
	@echo "[[1;32;40mCOMAKE:BUILD[0m][Target:'[1;32;40mtest_ul_pack_serial[0m']"
	$(CXX) test_ul_pack_serial_test_ul_pack_serial.o -Xlinker "-(" ../../lib/libullib.a ../../../../com-test/itest/tools/fault/output/lib/libfault.a \
  ../../../../com-test/itest/tools/fault/output/lib/libfault1.a \
  ../../../../com/btest/gtest/output/lib/libgtest.a \
  ../../../../com/btest/gtest/output/lib/libgtest_main.a \
  ../../../../com/idlcompiler/astyle/libastyle.a \
  ../../../../com/idlcompiler/cxx/libskeleton.a \
  ../../../../com/idlcompiler/java/libjava_skeleton.a \
  ../../../../com/idlcompiler/parser/libparser.a \
  ../../../../com/idlcompiler/php/libphp_skeleton.a \
  ../../../../lib2-64/bsl/lib/libbsl.a \
  ../../../../lib2-64/bsl/lib/libbsl_ResourcePool.a \
  ../../../../lib2-64/bsl/lib/libbsl_archive.a \
  ../../../../lib2-64/bsl/lib/libbsl_buffer.a \
  ../../../../lib2-64/bsl/lib/libbsl_check_cast.a \
  ../../../../lib2-64/bsl/lib/libbsl_exception.a \
  ../../../../lib2-64/bsl/lib/libbsl_pool.a \
  ../../../../lib2-64/bsl/lib/libbsl_utils.a \
  ../../../../lib2-64/bsl/lib/libbsl_var.a \
  ../../../../lib2-64/bsl/lib/libbsl_var_implement.a \
  ../../../../lib2-64/bsl/lib/libbsl_var_utils.a \
  ../../../../lib2-64/dict/lib/libuldict.a \
  ../../../../lib2-64/ullib/lib/libullib.a \
  ../../../../op/oped/noah/webfoot/naming-lib/output/lib/libwebfoot_naming.a \
  ../../../../public/bslext/output/lib/libbsl_bml.a \
  ../../../../public/bslext/output/lib/libbsl_containers_utils.a \
  ../../../../public/bslext/output/lib/libbsl_var_scripting.a \
  ../../../../public/bslext/output/lib/libbsl_var_serializer.a \
  ../../../../public/bslext/output/lib/libbsl_var_vscript.a \
  ../../../../public/bslext/output/lib/libbsl_vs.a \
  ../../../../public/bslext/output/lib/libbslext.a \
  ../../../../public/comlog-plugin/libcomlog.a \
  ../../../../public/comlog-plugin/output/lib/libdfsappender.a \
  ../../../../public/configure/libconfig.a \
  ../../../../public/connectpool/libconnectpool.a \
  ../../../../public/idlcompiler/output/lib/libmcpack_idl.a \
  ../../../../public/mcpack/libmcpack.a \
  ../../../../public/nshead/libnshead.a \
  ../../../../public/odict/libodict.a \
  ../../../../public/spreg/libspreg.a \
  ../../../../public/ub/output/lib/libub.a \
  ../../../../public/ub/output/lib/libub_aserver.a \
  ../../../../public/ub/output/lib/libub_client.a \
  ../../../../public/ub/output/lib/libub_conf.a \
  ../../../../public/ub/output/lib/libub_galileo.a \
  ../../../../public/ub/output/lib/libub_log.a \
  ../../../../public/ub/output/lib/libub_misc.a \
  ../../../../public/ub/output/lib/libub_monitor.a \
  ../../../../public/ub/output/lib/libub_naming.a \
  ../../../../public/ub/output/lib/libub_server.a \
  ../../../../public/ub/output/lib/libubex.a \
  ../../../../public/ub/output/lib/libubfw.a \
  ../../../../public/uconv/libuconv.a \
  ../../../../quality/autotest/reportlib/cpp/libautotest.a \
  ../../../../third-64/pcre/lib/libpcre.a \
  ../../../../third-64/pcre/lib/libpcrecpp.a \
  ../../../../third-64/pcre/lib/libpcreposix.a \
  ../../../../third-64/protobuf/lib/libprotobuf-lite.a \
  ../../../../third-64/protobuf/lib/libprotobuf.a \
  ../../../../third-64/protobuf/lib/libprotoc.a -lpthread \
  -lcrypto \
  -lrt -Xlinker "-)" -o test_ul_pack_serial

test_comlog_hostname:test_comlog_hostname_test_comlog_hostname.o \
  ../../lib/libullib.a
	@echo "[[1;32;40mCOMAKE:BUILD[0m][Target:'[1;32;40mtest_comlog_hostname[0m']"
	$(CXX) test_comlog_hostname_test_comlog_hostname.o -Xlinker "-(" ../../lib/libullib.a ../../../../com-test/itest/tools/fault/output/lib/libfault.a \
  ../../../../com-test/itest/tools/fault/output/lib/libfault1.a \
  ../../../../com/btest/gtest/output/lib/libgtest.a \
  ../../../../com/btest/gtest/output/lib/libgtest_main.a \
  ../../../../com/idlcompiler/astyle/libastyle.a \
  ../../../../com/idlcompiler/cxx/libskeleton.a \
  ../../../../com/idlcompiler/java/libjava_skeleton.a \
  ../../../../com/idlcompiler/parser/libparser.a \
  ../../../../com/idlcompiler/php/libphp_skeleton.a \
  ../../../../lib2-64/bsl/lib/libbsl.a \
  ../../../../lib2-64/bsl/lib/libbsl_ResourcePool.a \
  ../../../../lib2-64/bsl/lib/libbsl_archive.a \
  ../../../../lib2-64/bsl/lib/libbsl_buffer.a \
  ../../../../lib2-64/bsl/lib/libbsl_check_cast.a \
  ../../../../lib2-64/bsl/lib/libbsl_exception.a \
  ../../../../lib2-64/bsl/lib/libbsl_pool.a \
  ../../../../lib2-64/bsl/lib/libbsl_utils.a \
  ../../../../lib2-64/bsl/lib/libbsl_var.a \
  ../../../../lib2-64/bsl/lib/libbsl_var_implement.a \
  ../../../../lib2-64/bsl/lib/libbsl_var_utils.a \
  ../../../../lib2-64/dict/lib/libuldict.a \
  ../../../../lib2-64/ullib/lib/libullib.a \
  ../../../../op/oped/noah/webfoot/naming-lib/output/lib/libwebfoot_naming.a \
  ../../../../public/bslext/output/lib/libbsl_bml.a \
  ../../../../public/bslext/output/lib/libbsl_containers_utils.a \
  ../../../../public/bslext/output/lib/libbsl_var_scripting.a \
  ../../../../public/bslext/output/lib/libbsl_var_serializer.a \
  ../../../../public/bslext/output/lib/libbsl_var_vscript.a \
  ../../../../public/bslext/output/lib/libbsl_vs.a \
  ../../../../public/bslext/output/lib/libbslext.a \
  ../../../../public/comlog-plugin/libcomlog.a \
  ../../../../public/comlog-plugin/output/lib/libdfsappender.a \
  ../../../../public/configure/libconfig.a \
  ../../../../public/connectpool/libconnectpool.a \
  ../../../../public/idlcompiler/output/lib/libmcpack_idl.a \
  ../../../../public/mcpack/libmcpack.a \
  ../../../../public/nshead/libnshead.a \
  ../../../../public/odict/libodict.a \
  ../../../../public/spreg/libspreg.a \
  ../../../../public/ub/output/lib/libub.a \
  ../../../../public/ub/output/lib/libub_aserver.a \
  ../../../../public/ub/output/lib/libub_client.a \
  ../../../../public/ub/output/lib/libub_conf.a \
  ../../../../public/ub/output/lib/libub_galileo.a \
  ../../../../public/ub/output/lib/libub_log.a \
  ../../../../public/ub/output/lib/libub_misc.a \
  ../../../../public/ub/output/lib/libub_monitor.a \
  ../../../../public/ub/output/lib/libub_naming.a \
  ../../../../public/ub/output/lib/libub_server.a \
  ../../../../public/ub/output/lib/libubex.a \
  ../../../../public/ub/output/lib/libubfw.a \
  ../../../../public/uconv/libuconv.a \
  ../../../../quality/autotest/reportlib/cpp/libautotest.a \
  ../../../../third-64/pcre/lib/libpcre.a \
  ../../../../third-64/pcre/lib/libpcrecpp.a \
  ../../../../third-64/pcre/lib/libpcreposix.a \
  ../../../../third-64/protobuf/lib/libprotobuf-lite.a \
  ../../../../third-64/protobuf/lib/libprotobuf.a \
  ../../../../third-64/protobuf/lib/libprotoc.a -lpthread \
  -lcrypto \
  -lrt -Xlinker "-)" -o test_comlog_hostname

test_ul_url:test_ul_url_test_ul_url.o \
  ../../lib/libullib.a
	@echo "[[1;32;40mCOMAKE:BUILD[0m][Target:'[1;32;40mtest_ul_url[0m']"
	$(CXX) test_ul_url_test_ul_url.o -Xlinker "-(" ../../lib/libullib.a ../../../../com-test/itest/tools/fault/output/lib/libfault.a \
  ../../../../com-test/itest/tools/fault/output/lib/libfault1.a \
  ../../../../com/btest/gtest/output/lib/libgtest.a \
  ../../../../com/btest/gtest/output/lib/libgtest_main.a \
  ../../../../com/idlcompiler/astyle/libastyle.a \
  ../../../../com/idlcompiler/cxx/libskeleton.a \
  ../../../../com/idlcompiler/java/libjava_skeleton.a \
  ../../../../com/idlcompiler/parser/libparser.a \
  ../../../../com/idlcompiler/php/libphp_skeleton.a \
  ../../../../lib2-64/bsl/lib/libbsl.a \
  ../../../../lib2-64/bsl/lib/libbsl_ResourcePool.a \
  ../../../../lib2-64/bsl/lib/libbsl_archive.a \
  ../../../../lib2-64/bsl/lib/libbsl_buffer.a \
  ../../../../lib2-64/bsl/lib/libbsl_check_cast.a \
  ../../../../lib2-64/bsl/lib/libbsl_exception.a \
  ../../../../lib2-64/bsl/lib/libbsl_pool.a \
  ../../../../lib2-64/bsl/lib/libbsl_utils.a \
  ../../../../lib2-64/bsl/lib/libbsl_var.a \
  ../../../../lib2-64/bsl/lib/libbsl_var_implement.a \
  ../../../../lib2-64/bsl/lib/libbsl_var_utils.a \
  ../../../../lib2-64/dict/lib/libuldict.a \
  ../../../../lib2-64/ullib/lib/libullib.a \
  ../../../../op/oped/noah/webfoot/naming-lib/output/lib/libwebfoot_naming.a \
  ../../../../public/bslext/output/lib/libbsl_bml.a \
  ../../../../public/bslext/output/lib/libbsl_containers_utils.a \
  ../../../../public/bslext/output/lib/libbsl_var_scripting.a \
  ../../../../public/bslext/output/lib/libbsl_var_serializer.a \
  ../../../../public/bslext/output/lib/libbsl_var_vscript.a \
  ../../../../public/bslext/output/lib/libbsl_vs.a \
  ../../../../public/bslext/output/lib/libbslext.a \
  ../../../../public/comlog-plugin/libcomlog.a \
  ../../../../public/comlog-plugin/output/lib/libdfsappender.a \
  ../../../../public/configure/libconfig.a \
  ../../../../public/connectpool/libconnectpool.a \
  ../../../../public/idlcompiler/output/lib/libmcpack_idl.a \
  ../../../../public/mcpack/libmcpack.a \
  ../../../../public/nshead/libnshead.a \
  ../../../../public/odict/libodict.a \
  ../../../../public/spreg/libspreg.a \
  ../../../../public/ub/output/lib/libub.a \
  ../../../../public/ub/output/lib/libub_aserver.a \
  ../../../../public/ub/output/lib/libub_client.a \
  ../../../../public/ub/output/lib/libub_conf.a \
  ../../../../public/ub/output/lib/libub_galileo.a \
  ../../../../public/ub/output/lib/libub_log.a \
  ../../../../public/ub/output/lib/libub_misc.a \
  ../../../../public/ub/output/lib/libub_monitor.a \
  ../../../../public/ub/output/lib/libub_naming.a \
  ../../../../public/ub/output/lib/libub_server.a \
  ../../../../public/ub/output/lib/libubex.a \
  ../../../../public/ub/output/lib/libubfw.a \
  ../../../../public/uconv/libuconv.a \
  ../../../../quality/autotest/reportlib/cpp/libautotest.a \
  ../../../../third-64/pcre/lib/libpcre.a \
  ../../../../third-64/pcre/lib/libpcrecpp.a \
  ../../../../third-64/pcre/lib/libpcreposix.a \
  ../../../../third-64/protobuf/lib/libprotobuf-lite.a \
  ../../../../third-64/protobuf/lib/libprotobuf.a \
  ../../../../third-64/protobuf/lib/libprotoc.a -lpthread \
  -lcrypto \
  -lrt -Xlinker "-)" -o test_ul_url

test_comlog_level:test_comlog_level_test_comlog_level.o \
  ../../lib/libullib.a
	@echo "[[1;32;40mCOMAKE:BUILD[0m][Target:'[1;32;40mtest_comlog_level[0m']"
	$(CXX) test_comlog_level_test_comlog_level.o -Xlinker "-(" ../../lib/libullib.a ../../../../com-test/itest/tools/fault/output/lib/libfault.a \
  ../../../../com-test/itest/tools/fault/output/lib/libfault1.a \
  ../../../../com/btest/gtest/output/lib/libgtest.a \
  ../../../../com/btest/gtest/output/lib/libgtest_main.a \
  ../../../../com/idlcompiler/astyle/libastyle.a \
  ../../../../com/idlcompiler/cxx/libskeleton.a \
  ../../../../com/idlcompiler/java/libjava_skeleton.a \
  ../../../../com/idlcompiler/parser/libparser.a \
  ../../../../com/idlcompiler/php/libphp_skeleton.a \
  ../../../../lib2-64/bsl/lib/libbsl.a \
  ../../../../lib2-64/bsl/lib/libbsl_ResourcePool.a \
  ../../../../lib2-64/bsl/lib/libbsl_archive.a \
  ../../../../lib2-64/bsl/lib/libbsl_buffer.a \
  ../../../../lib2-64/bsl/lib/libbsl_check_cast.a \
  ../../../../lib2-64/bsl/lib/libbsl_exception.a \
  ../../../../lib2-64/bsl/lib/libbsl_pool.a \
  ../../../../lib2-64/bsl/lib/libbsl_utils.a \
  ../../../../lib2-64/bsl/lib/libbsl_var.a \
  ../../../../lib2-64/bsl/lib/libbsl_var_implement.a \
  ../../../../lib2-64/bsl/lib/libbsl_var_utils.a \
  ../../../../lib2-64/dict/lib/libuldict.a \
  ../../../../lib2-64/ullib/lib/libullib.a \
  ../../../../op/oped/noah/webfoot/naming-lib/output/lib/libwebfoot_naming.a \
  ../../../../public/bslext/output/lib/libbsl_bml.a \
  ../../../../public/bslext/output/lib/libbsl_containers_utils.a \
  ../../../../public/bslext/output/lib/libbsl_var_scripting.a \
  ../../../../public/bslext/output/lib/libbsl_var_serializer.a \
  ../../../../public/bslext/output/lib/libbsl_var_vscript.a \
  ../../../../public/bslext/output/lib/libbsl_vs.a \
  ../../../../public/bslext/output/lib/libbslext.a \
  ../../../../public/comlog-plugin/libcomlog.a \
  ../../../../public/comlog-plugin/output/lib/libdfsappender.a \
  ../../../../public/configure/libconfig.a \
  ../../../../public/connectpool/libconnectpool.a \
  ../../../../public/idlcompiler/output/lib/libmcpack_idl.a \
  ../../../../public/mcpack/libmcpack.a \
  ../../../../public/nshead/libnshead.a \
  ../../../../public/odict/libodict.a \
  ../../../../public/spreg/libspreg.a \
  ../../../../public/ub/output/lib/libub.a \
  ../../../../public/ub/output/lib/libub_aserver.a \
  ../../../../public/ub/output/lib/libub_client.a \
  ../../../../public/ub/output/lib/libub_conf.a \
  ../../../../public/ub/output/lib/libub_galileo.a \
  ../../../../public/ub/output/lib/libub_log.a \
  ../../../../public/ub/output/lib/libub_misc.a \
  ../../../../public/ub/output/lib/libub_monitor.a \
  ../../../../public/ub/output/lib/libub_naming.a \
  ../../../../public/ub/output/lib/libub_server.a \
  ../../../../public/ub/output/lib/libubex.a \
  ../../../../public/ub/output/lib/libubfw.a \
  ../../../../public/uconv/libuconv.a \
  ../../../../quality/autotest/reportlib/cpp/libautotest.a \
  ../../../../third-64/pcre/lib/libpcre.a \
  ../../../../third-64/pcre/lib/libpcrecpp.a \
  ../../../../third-64/pcre/lib/libpcreposix.a \
  ../../../../third-64/protobuf/lib/libprotobuf-lite.a \
  ../../../../third-64/protobuf/lib/libprotobuf.a \
  ../../../../third-64/protobuf/lib/libprotoc.a -lpthread \
  -lcrypto \
  -lrt -Xlinker "-)" -o test_comlog_level

test_comlog_guard:test_comlog_guard_test_comlog_guard.o \
  ../../lib/libullib.a
	@echo "[[1;32;40mCOMAKE:BUILD[0m][Target:'[1;32;40mtest_comlog_guard[0m']"
	$(CXX) test_comlog_guard_test_comlog_guard.o -Xlinker "-(" ../../lib/libullib.a ../../../../com-test/itest/tools/fault/output/lib/libfault.a \
  ../../../../com-test/itest/tools/fault/output/lib/libfault1.a \
  ../../../../com/btest/gtest/output/lib/libgtest.a \
  ../../../../com/btest/gtest/output/lib/libgtest_main.a \
  ../../../../com/idlcompiler/astyle/libastyle.a \
  ../../../../com/idlcompiler/cxx/libskeleton.a \
  ../../../../com/idlcompiler/java/libjava_skeleton.a \
  ../../../../com/idlcompiler/parser/libparser.a \
  ../../../../com/idlcompiler/php/libphp_skeleton.a \
  ../../../../lib2-64/bsl/lib/libbsl.a \
  ../../../../lib2-64/bsl/lib/libbsl_ResourcePool.a \
  ../../../../lib2-64/bsl/lib/libbsl_archive.a \
  ../../../../lib2-64/bsl/lib/libbsl_buffer.a \
  ../../../../lib2-64/bsl/lib/libbsl_check_cast.a \
  ../../../../lib2-64/bsl/lib/libbsl_exception.a \
  ../../../../lib2-64/bsl/lib/libbsl_pool.a \
  ../../../../lib2-64/bsl/lib/libbsl_utils.a \
  ../../../../lib2-64/bsl/lib/libbsl_var.a \
  ../../../../lib2-64/bsl/lib/libbsl_var_implement.a \
  ../../../../lib2-64/bsl/lib/libbsl_var_utils.a \
  ../../../../lib2-64/dict/lib/libuldict.a \
  ../../../../lib2-64/ullib/lib/libullib.a \
  ../../../../op/oped/noah/webfoot/naming-lib/output/lib/libwebfoot_naming.a \
  ../../../../public/bslext/output/lib/libbsl_bml.a \
  ../../../../public/bslext/output/lib/libbsl_containers_utils.a \
  ../../../../public/bslext/output/lib/libbsl_var_scripting.a \
  ../../../../public/bslext/output/lib/libbsl_var_serializer.a \
  ../../../../public/bslext/output/lib/libbsl_var_vscript.a \
  ../../../../public/bslext/output/lib/libbsl_vs.a \
  ../../../../public/bslext/output/lib/libbslext.a \
  ../../../../public/comlog-plugin/libcomlog.a \
  ../../../../public/comlog-plugin/output/lib/libdfsappender.a \
  ../../../../public/configure/libconfig.a \
  ../../../../public/connectpool/libconnectpool.a \
  ../../../../public/idlcompiler/output/lib/libmcpack_idl.a \
  ../../../../public/mcpack/libmcpack.a \
  ../../../../public/nshead/libnshead.a \
  ../../../../public/odict/libodict.a \
  ../../../../public/spreg/libspreg.a \
  ../../../../public/ub/output/lib/libub.a \
  ../../../../public/ub/output/lib/libub_aserver.a \
  ../../../../public/ub/output/lib/libub_client.a \
  ../../../../public/ub/output/lib/libub_conf.a \
  ../../../../public/ub/output/lib/libub_galileo.a \
  ../../../../public/ub/output/lib/libub_log.a \
  ../../../../public/ub/output/lib/libub_misc.a \
  ../../../../public/ub/output/lib/libub_monitor.a \
  ../../../../public/ub/output/lib/libub_naming.a \
  ../../../../public/ub/output/lib/libub_server.a \
  ../../../../public/ub/output/lib/libubex.a \
  ../../../../public/ub/output/lib/libubfw.a \
  ../../../../public/uconv/libuconv.a \
  ../../../../quality/autotest/reportlib/cpp/libautotest.a \
  ../../../../third-64/pcre/lib/libpcre.a \
  ../../../../third-64/pcre/lib/libpcrecpp.a \
  ../../../../third-64/pcre/lib/libpcreposix.a \
  ../../../../third-64/protobuf/lib/libprotobuf-lite.a \
  ../../../../third-64/protobuf/lib/libprotobuf.a \
  ../../../../third-64/protobuf/lib/libprotoc.a -lpthread \
  -lcrypto \
  -lrt -Xlinker "-)" -o test_comlog_guard

test_ullog_level:test_ullog_level_test_ullog_level.o \
  ../../lib/libullib.a
	@echo "[[1;32;40mCOMAKE:BUILD[0m][Target:'[1;32;40mtest_ullog_level[0m']"
	$(CXX) test_ullog_level_test_ullog_level.o -Xlinker "-(" ../../lib/libullib.a ../../../../com-test/itest/tools/fault/output/lib/libfault.a \
  ../../../../com-test/itest/tools/fault/output/lib/libfault1.a \
  ../../../../com/btest/gtest/output/lib/libgtest.a \
  ../../../../com/btest/gtest/output/lib/libgtest_main.a \
  ../../../../com/idlcompiler/astyle/libastyle.a \
  ../../../../com/idlcompiler/cxx/libskeleton.a \
  ../../../../com/idlcompiler/java/libjava_skeleton.a \
  ../../../../com/idlcompiler/parser/libparser.a \
  ../../../../com/idlcompiler/php/libphp_skeleton.a \
  ../../../../lib2-64/bsl/lib/libbsl.a \
  ../../../../lib2-64/bsl/lib/libbsl_ResourcePool.a \
  ../../../../lib2-64/bsl/lib/libbsl_archive.a \
  ../../../../lib2-64/bsl/lib/libbsl_buffer.a \
  ../../../../lib2-64/bsl/lib/libbsl_check_cast.a \
  ../../../../lib2-64/bsl/lib/libbsl_exception.a \
  ../../../../lib2-64/bsl/lib/libbsl_pool.a \
  ../../../../lib2-64/bsl/lib/libbsl_utils.a \
  ../../../../lib2-64/bsl/lib/libbsl_var.a \
  ../../../../lib2-64/bsl/lib/libbsl_var_implement.a \
  ../../../../lib2-64/bsl/lib/libbsl_var_utils.a \
  ../../../../lib2-64/dict/lib/libuldict.a \
  ../../../../lib2-64/ullib/lib/libullib.a \
  ../../../../op/oped/noah/webfoot/naming-lib/output/lib/libwebfoot_naming.a \
  ../../../../public/bslext/output/lib/libbsl_bml.a \
  ../../../../public/bslext/output/lib/libbsl_containers_utils.a \
  ../../../../public/bslext/output/lib/libbsl_var_scripting.a \
  ../../../../public/bslext/output/lib/libbsl_var_serializer.a \
  ../../../../public/bslext/output/lib/libbsl_var_vscript.a \
  ../../../../public/bslext/output/lib/libbsl_vs.a \
  ../../../../public/bslext/output/lib/libbslext.a \
  ../../../../public/comlog-plugin/libcomlog.a \
  ../../../../public/comlog-plugin/output/lib/libdfsappender.a \
  ../../../../public/configure/libconfig.a \
  ../../../../public/connectpool/libconnectpool.a \
  ../../../../public/idlcompiler/output/lib/libmcpack_idl.a \
  ../../../../public/mcpack/libmcpack.a \
  ../../../../public/nshead/libnshead.a \
  ../../../../public/odict/libodict.a \
  ../../../../public/spreg/libspreg.a \
  ../../../../public/ub/output/lib/libub.a \
  ../../../../public/ub/output/lib/libub_aserver.a \
  ../../../../public/ub/output/lib/libub_client.a \
  ../../../../public/ub/output/lib/libub_conf.a \
  ../../../../public/ub/output/lib/libub_galileo.a \
  ../../../../public/ub/output/lib/libub_log.a \
  ../../../../public/ub/output/lib/libub_misc.a \
  ../../../../public/ub/output/lib/libub_monitor.a \
  ../../../../public/ub/output/lib/libub_naming.a \
  ../../../../public/ub/output/lib/libub_server.a \
  ../../../../public/ub/output/lib/libubex.a \
  ../../../../public/ub/output/lib/libubfw.a \
  ../../../../public/uconv/libuconv.a \
  ../../../../quality/autotest/reportlib/cpp/libautotest.a \
  ../../../../third-64/pcre/lib/libpcre.a \
  ../../../../third-64/pcre/lib/libpcrecpp.a \
  ../../../../third-64/pcre/lib/libpcreposix.a \
  ../../../../third-64/protobuf/lib/libprotobuf-lite.a \
  ../../../../third-64/protobuf/lib/libprotobuf.a \
  ../../../../third-64/protobuf/lib/libprotoc.a -lpthread \
  -lcrypto \
  -lrt -Xlinker "-)" -o test_ullog_level

test_com_openlog_r:test_com_openlog_r_test_com_openlog_r.o \
  ../../lib/libullib.a
	@echo "[[1;32;40mCOMAKE:BUILD[0m][Target:'[1;32;40mtest_com_openlog_r[0m']"
	$(CXX) test_com_openlog_r_test_com_openlog_r.o -Xlinker "-(" ../../lib/libullib.a ../../../../com-test/itest/tools/fault/output/lib/libfault.a \
  ../../../../com-test/itest/tools/fault/output/lib/libfault1.a \
  ../../../../com/btest/gtest/output/lib/libgtest.a \
  ../../../../com/btest/gtest/output/lib/libgtest_main.a \
  ../../../../com/idlcompiler/astyle/libastyle.a \
  ../../../../com/idlcompiler/cxx/libskeleton.a \
  ../../../../com/idlcompiler/java/libjava_skeleton.a \
  ../../../../com/idlcompiler/parser/libparser.a \
  ../../../../com/idlcompiler/php/libphp_skeleton.a \
  ../../../../lib2-64/bsl/lib/libbsl.a \
  ../../../../lib2-64/bsl/lib/libbsl_ResourcePool.a \
  ../../../../lib2-64/bsl/lib/libbsl_archive.a \
  ../../../../lib2-64/bsl/lib/libbsl_buffer.a \
  ../../../../lib2-64/bsl/lib/libbsl_check_cast.a \
  ../../../../lib2-64/bsl/lib/libbsl_exception.a \
  ../../../../lib2-64/bsl/lib/libbsl_pool.a \
  ../../../../lib2-64/bsl/lib/libbsl_utils.a \
  ../../../../lib2-64/bsl/lib/libbsl_var.a \
  ../../../../lib2-64/bsl/lib/libbsl_var_implement.a \
  ../../../../lib2-64/bsl/lib/libbsl_var_utils.a \
  ../../../../lib2-64/dict/lib/libuldict.a \
  ../../../../lib2-64/ullib/lib/libullib.a \
  ../../../../op/oped/noah/webfoot/naming-lib/output/lib/libwebfoot_naming.a \
  ../../../../public/bslext/output/lib/libbsl_bml.a \
  ../../../../public/bslext/output/lib/libbsl_containers_utils.a \
  ../../../../public/bslext/output/lib/libbsl_var_scripting.a \
  ../../../../public/bslext/output/lib/libbsl_var_serializer.a \
  ../../../../public/bslext/output/lib/libbsl_var_vscript.a \
  ../../../../public/bslext/output/lib/libbsl_vs.a \
  ../../../../public/bslext/output/lib/libbslext.a \
  ../../../../public/comlog-plugin/libcomlog.a \
  ../../../../public/comlog-plugin/output/lib/libdfsappender.a \
  ../../../../public/configure/libconfig.a \
  ../../../../public/connectpool/libconnectpool.a \
  ../../../../public/idlcompiler/output/lib/libmcpack_idl.a \
  ../../../../public/mcpack/libmcpack.a \
  ../../../../public/nshead/libnshead.a \
  ../../../../public/odict/libodict.a \
  ../../../../public/spreg/libspreg.a \
  ../../../../public/ub/output/lib/libub.a \
  ../../../../public/ub/output/lib/libub_aserver.a \
  ../../../../public/ub/output/lib/libub_client.a \
  ../../../../public/ub/output/lib/libub_conf.a \
  ../../../../public/ub/output/lib/libub_galileo.a \
  ../../../../public/ub/output/lib/libub_log.a \
  ../../../../public/ub/output/lib/libub_misc.a \
  ../../../../public/ub/output/lib/libub_monitor.a \
  ../../../../public/ub/output/lib/libub_naming.a \
  ../../../../public/ub/output/lib/libub_server.a \
  ../../../../public/ub/output/lib/libubex.a \
  ../../../../public/ub/output/lib/libubfw.a \
  ../../../../public/uconv/libuconv.a \
  ../../../../quality/autotest/reportlib/cpp/libautotest.a \
  ../../../../third-64/pcre/lib/libpcre.a \
  ../../../../third-64/pcre/lib/libpcrecpp.a \
  ../../../../third-64/pcre/lib/libpcreposix.a \
  ../../../../third-64/protobuf/lib/libprotobuf-lite.a \
  ../../../../third-64/protobuf/lib/libprotobuf.a \
  ../../../../third-64/protobuf/lib/libprotoc.a -lpthread \
  -lcrypto \
  -lrt -Xlinker "-)" -o test_com_openlog_r

test_comlog_disk:test_comlog_disk_test_comlog_disk.o \
  ../../lib/libullib.a
	@echo "[[1;32;40mCOMAKE:BUILD[0m][Target:'[1;32;40mtest_comlog_disk[0m']"
	$(CXX) test_comlog_disk_test_comlog_disk.o -Xlinker "-(" ../../lib/libullib.a ../../../../com-test/itest/tools/fault/output/lib/libfault.a \
  ../../../../com-test/itest/tools/fault/output/lib/libfault1.a \
  ../../../../com/btest/gtest/output/lib/libgtest.a \
  ../../../../com/btest/gtest/output/lib/libgtest_main.a \
  ../../../../com/idlcompiler/astyle/libastyle.a \
  ../../../../com/idlcompiler/cxx/libskeleton.a \
  ../../../../com/idlcompiler/java/libjava_skeleton.a \
  ../../../../com/idlcompiler/parser/libparser.a \
  ../../../../com/idlcompiler/php/libphp_skeleton.a \
  ../../../../lib2-64/bsl/lib/libbsl.a \
  ../../../../lib2-64/bsl/lib/libbsl_ResourcePool.a \
  ../../../../lib2-64/bsl/lib/libbsl_archive.a \
  ../../../../lib2-64/bsl/lib/libbsl_buffer.a \
  ../../../../lib2-64/bsl/lib/libbsl_check_cast.a \
  ../../../../lib2-64/bsl/lib/libbsl_exception.a \
  ../../../../lib2-64/bsl/lib/libbsl_pool.a \
  ../../../../lib2-64/bsl/lib/libbsl_utils.a \
  ../../../../lib2-64/bsl/lib/libbsl_var.a \
  ../../../../lib2-64/bsl/lib/libbsl_var_implement.a \
  ../../../../lib2-64/bsl/lib/libbsl_var_utils.a \
  ../../../../lib2-64/dict/lib/libuldict.a \
  ../../../../lib2-64/ullib/lib/libullib.a \
  ../../../../op/oped/noah/webfoot/naming-lib/output/lib/libwebfoot_naming.a \
  ../../../../public/bslext/output/lib/libbsl_bml.a \
  ../../../../public/bslext/output/lib/libbsl_containers_utils.a \
  ../../../../public/bslext/output/lib/libbsl_var_scripting.a \
  ../../../../public/bslext/output/lib/libbsl_var_serializer.a \
  ../../../../public/bslext/output/lib/libbsl_var_vscript.a \
  ../../../../public/bslext/output/lib/libbsl_vs.a \
  ../../../../public/bslext/output/lib/libbslext.a \
  ../../../../public/comlog-plugin/libcomlog.a \
  ../../../../public/comlog-plugin/output/lib/libdfsappender.a \
  ../../../../public/configure/libconfig.a \
  ../../../../public/connectpool/libconnectpool.a \
  ../../../../public/idlcompiler/output/lib/libmcpack_idl.a \
  ../../../../public/mcpack/libmcpack.a \
  ../../../../public/nshead/libnshead.a \
  ../../../../public/odict/libodict.a \
  ../../../../public/spreg/libspreg.a \
  ../../../../public/ub/output/lib/libub.a \
  ../../../../public/ub/output/lib/libub_aserver.a \
  ../../../../public/ub/output/lib/libub_client.a \
  ../../../../public/ub/output/lib/libub_conf.a \
  ../../../../public/ub/output/lib/libub_galileo.a \
  ../../../../public/ub/output/lib/libub_log.a \
  ../../../../public/ub/output/lib/libub_misc.a \
  ../../../../public/ub/output/lib/libub_monitor.a \
  ../../../../public/ub/output/lib/libub_naming.a \
  ../../../../public/ub/output/lib/libub_server.a \
  ../../../../public/ub/output/lib/libubex.a \
  ../../../../public/ub/output/lib/libubfw.a \
  ../../../../public/uconv/libuconv.a \
  ../../../../quality/autotest/reportlib/cpp/libautotest.a \
  ../../../../third-64/pcre/lib/libpcre.a \
  ../../../../third-64/pcre/lib/libpcrecpp.a \
  ../../../../third-64/pcre/lib/libpcreposix.a \
  ../../../../third-64/protobuf/lib/libprotobuf-lite.a \
  ../../../../third-64/protobuf/lib/libprotobuf.a \
  ../../../../third-64/protobuf/lib/libprotoc.a -lpthread \
  -lcrypto \
  -lrt -Xlinker "-)" -o test_comlog_disk

test_ulnet_read:test_ulnet_read_test_ulnet_read.o \
  ../../lib/libullib.a
	@echo "[[1;32;40mCOMAKE:BUILD[0m][Target:'[1;32;40mtest_ulnet_read[0m']"
	$(CXX) test_ulnet_read_test_ulnet_read.o -Xlinker "-(" ../../lib/libullib.a ../../../../com-test/itest/tools/fault/output/lib/libfault.a \
  ../../../../com-test/itest/tools/fault/output/lib/libfault1.a \
  ../../../../com/btest/gtest/output/lib/libgtest.a \
  ../../../../com/btest/gtest/output/lib/libgtest_main.a \
  ../../../../com/idlcompiler/astyle/libastyle.a \
  ../../../../com/idlcompiler/cxx/libskeleton.a \
  ../../../../com/idlcompiler/java/libjava_skeleton.a \
  ../../../../com/idlcompiler/parser/libparser.a \
  ../../../../com/idlcompiler/php/libphp_skeleton.a \
  ../../../../lib2-64/bsl/lib/libbsl.a \
  ../../../../lib2-64/bsl/lib/libbsl_ResourcePool.a \
  ../../../../lib2-64/bsl/lib/libbsl_archive.a \
  ../../../../lib2-64/bsl/lib/libbsl_buffer.a \
  ../../../../lib2-64/bsl/lib/libbsl_check_cast.a \
  ../../../../lib2-64/bsl/lib/libbsl_exception.a \
  ../../../../lib2-64/bsl/lib/libbsl_pool.a \
  ../../../../lib2-64/bsl/lib/libbsl_utils.a \
  ../../../../lib2-64/bsl/lib/libbsl_var.a \
  ../../../../lib2-64/bsl/lib/libbsl_var_implement.a \
  ../../../../lib2-64/bsl/lib/libbsl_var_utils.a \
  ../../../../lib2-64/dict/lib/libuldict.a \
  ../../../../lib2-64/ullib/lib/libullib.a \
  ../../../../op/oped/noah/webfoot/naming-lib/output/lib/libwebfoot_naming.a \
  ../../../../public/bslext/output/lib/libbsl_bml.a \
  ../../../../public/bslext/output/lib/libbsl_containers_utils.a \
  ../../../../public/bslext/output/lib/libbsl_var_scripting.a \
  ../../../../public/bslext/output/lib/libbsl_var_serializer.a \
  ../../../../public/bslext/output/lib/libbsl_var_vscript.a \
  ../../../../public/bslext/output/lib/libbsl_vs.a \
  ../../../../public/bslext/output/lib/libbslext.a \
  ../../../../public/comlog-plugin/libcomlog.a \
  ../../../../public/comlog-plugin/output/lib/libdfsappender.a \
  ../../../../public/configure/libconfig.a \
  ../../../../public/connectpool/libconnectpool.a \
  ../../../../public/idlcompiler/output/lib/libmcpack_idl.a \
  ../../../../public/mcpack/libmcpack.a \
  ../../../../public/nshead/libnshead.a \
  ../../../../public/odict/libodict.a \
  ../../../../public/spreg/libspreg.a \
  ../../../../public/ub/output/lib/libub.a \
  ../../../../public/ub/output/lib/libub_aserver.a \
  ../../../../public/ub/output/lib/libub_client.a \
  ../../../../public/ub/output/lib/libub_conf.a \
  ../../../../public/ub/output/lib/libub_galileo.a \
  ../../../../public/ub/output/lib/libub_log.a \
  ../../../../public/ub/output/lib/libub_misc.a \
  ../../../../public/ub/output/lib/libub_monitor.a \
  ../../../../public/ub/output/lib/libub_naming.a \
  ../../../../public/ub/output/lib/libub_server.a \
  ../../../../public/ub/output/lib/libubex.a \
  ../../../../public/ub/output/lib/libubfw.a \
  ../../../../public/uconv/libuconv.a \
  ../../../../quality/autotest/reportlib/cpp/libautotest.a \
  ../../../../third-64/pcre/lib/libpcre.a \
  ../../../../third-64/pcre/lib/libpcrecpp.a \
  ../../../../third-64/pcre/lib/libpcreposix.a \
  ../../../../third-64/protobuf/lib/libprotobuf-lite.a \
  ../../../../third-64/protobuf/lib/libprotobuf.a \
  ../../../../third-64/protobuf/lib/libprotoc.a -lpthread \
  -lcrypto \
  -lrt -Xlinker "-)" -o test_ulnet_read

test_ulnet_write:test_ulnet_write_test_ulnet_write.o \
  ../../lib/libullib.a
	@echo "[[1;32;40mCOMAKE:BUILD[0m][Target:'[1;32;40mtest_ulnet_write[0m']"
	$(CXX) test_ulnet_write_test_ulnet_write.o -Xlinker "-(" ../../lib/libullib.a ../../../../com-test/itest/tools/fault/output/lib/libfault.a \
  ../../../../com-test/itest/tools/fault/output/lib/libfault1.a \
  ../../../../com/btest/gtest/output/lib/libgtest.a \
  ../../../../com/btest/gtest/output/lib/libgtest_main.a \
  ../../../../com/idlcompiler/astyle/libastyle.a \
  ../../../../com/idlcompiler/cxx/libskeleton.a \
  ../../../../com/idlcompiler/java/libjava_skeleton.a \
  ../../../../com/idlcompiler/parser/libparser.a \
  ../../../../com/idlcompiler/php/libphp_skeleton.a \
  ../../../../lib2-64/bsl/lib/libbsl.a \
  ../../../../lib2-64/bsl/lib/libbsl_ResourcePool.a \
  ../../../../lib2-64/bsl/lib/libbsl_archive.a \
  ../../../../lib2-64/bsl/lib/libbsl_buffer.a \
  ../../../../lib2-64/bsl/lib/libbsl_check_cast.a \
  ../../../../lib2-64/bsl/lib/libbsl_exception.a \
  ../../../../lib2-64/bsl/lib/libbsl_pool.a \
  ../../../../lib2-64/bsl/lib/libbsl_utils.a \
  ../../../../lib2-64/bsl/lib/libbsl_var.a \
  ../../../../lib2-64/bsl/lib/libbsl_var_implement.a \
  ../../../../lib2-64/bsl/lib/libbsl_var_utils.a \
  ../../../../lib2-64/dict/lib/libuldict.a \
  ../../../../lib2-64/ullib/lib/libullib.a \
  ../../../../op/oped/noah/webfoot/naming-lib/output/lib/libwebfoot_naming.a \
  ../../../../public/bslext/output/lib/libbsl_bml.a \
  ../../../../public/bslext/output/lib/libbsl_containers_utils.a \
  ../../../../public/bslext/output/lib/libbsl_var_scripting.a \
  ../../../../public/bslext/output/lib/libbsl_var_serializer.a \
  ../../../../public/bslext/output/lib/libbsl_var_vscript.a \
  ../../../../public/bslext/output/lib/libbsl_vs.a \
  ../../../../public/bslext/output/lib/libbslext.a \
  ../../../../public/comlog-plugin/libcomlog.a \
  ../../../../public/comlog-plugin/output/lib/libdfsappender.a \
  ../../../../public/configure/libconfig.a \
  ../../../../public/connectpool/libconnectpool.a \
  ../../../../public/idlcompiler/output/lib/libmcpack_idl.a \
  ../../../../public/mcpack/libmcpack.a \
  ../../../../public/nshead/libnshead.a \
  ../../../../public/odict/libodict.a \
  ../../../../public/spreg/libspreg.a \
  ../../../../public/ub/output/lib/libub.a \
  ../../../../public/ub/output/lib/libub_aserver.a \
  ../../../../public/ub/output/lib/libub_client.a \
  ../../../../public/ub/output/lib/libub_conf.a \
  ../../../../public/ub/output/lib/libub_galileo.a \
  ../../../../public/ub/output/lib/libub_log.a \
  ../../../../public/ub/output/lib/libub_misc.a \
  ../../../../public/ub/output/lib/libub_monitor.a \
  ../../../../public/ub/output/lib/libub_naming.a \
  ../../../../public/ub/output/lib/libub_server.a \
  ../../../../public/ub/output/lib/libubex.a \
  ../../../../public/ub/output/lib/libubfw.a \
  ../../../../public/uconv/libuconv.a \
  ../../../../quality/autotest/reportlib/cpp/libautotest.a \
  ../../../../third-64/pcre/lib/libpcre.a \
  ../../../../third-64/pcre/lib/libpcrecpp.a \
  ../../../../third-64/pcre/lib/libpcreposix.a \
  ../../../../third-64/protobuf/lib/libprotobuf-lite.a \
  ../../../../third-64/protobuf/lib/libprotobuf.a \
  ../../../../third-64/protobuf/lib/libprotoc.a -lpthread \
  -lcrypto \
  -lrt -Xlinker "-)" -o test_ulnet_write

test_write_failure:test_write_failure_test_write_failure.o \
  ../../lib/libullib.a
	@echo "[[1;32;40mCOMAKE:BUILD[0m][Target:'[1;32;40mtest_write_failure[0m']"
	$(CXX) test_write_failure_test_write_failure.o -Xlinker "-(" ../../lib/libullib.a ../../../../com-test/itest/tools/fault/output/lib/libfault.a \
  ../../../../com-test/itest/tools/fault/output/lib/libfault1.a \
  ../../../../com/btest/gtest/output/lib/libgtest.a \
  ../../../../com/btest/gtest/output/lib/libgtest_main.a \
  ../../../../com/idlcompiler/astyle/libastyle.a \
  ../../../../com/idlcompiler/cxx/libskeleton.a \
  ../../../../com/idlcompiler/java/libjava_skeleton.a \
  ../../../../com/idlcompiler/parser/libparser.a \
  ../../../../com/idlcompiler/php/libphp_skeleton.a \
  ../../../../lib2-64/bsl/lib/libbsl.a \
  ../../../../lib2-64/bsl/lib/libbsl_ResourcePool.a \
  ../../../../lib2-64/bsl/lib/libbsl_archive.a \
  ../../../../lib2-64/bsl/lib/libbsl_buffer.a \
  ../../../../lib2-64/bsl/lib/libbsl_check_cast.a \
  ../../../../lib2-64/bsl/lib/libbsl_exception.a \
  ../../../../lib2-64/bsl/lib/libbsl_pool.a \
  ../../../../lib2-64/bsl/lib/libbsl_utils.a \
  ../../../../lib2-64/bsl/lib/libbsl_var.a \
  ../../../../lib2-64/bsl/lib/libbsl_var_implement.a \
  ../../../../lib2-64/bsl/lib/libbsl_var_utils.a \
  ../../../../lib2-64/dict/lib/libuldict.a \
  ../../../../lib2-64/ullib/lib/libullib.a \
  ../../../../op/oped/noah/webfoot/naming-lib/output/lib/libwebfoot_naming.a \
  ../../../../public/bslext/output/lib/libbsl_bml.a \
  ../../../../public/bslext/output/lib/libbsl_containers_utils.a \
  ../../../../public/bslext/output/lib/libbsl_var_scripting.a \
  ../../../../public/bslext/output/lib/libbsl_var_serializer.a \
  ../../../../public/bslext/output/lib/libbsl_var_vscript.a \
  ../../../../public/bslext/output/lib/libbsl_vs.a \
  ../../../../public/bslext/output/lib/libbslext.a \
  ../../../../public/comlog-plugin/libcomlog.a \
  ../../../../public/comlog-plugin/output/lib/libdfsappender.a \
  ../../../../public/configure/libconfig.a \
  ../../../../public/connectpool/libconnectpool.a \
  ../../../../public/idlcompiler/output/lib/libmcpack_idl.a \
  ../../../../public/mcpack/libmcpack.a \
  ../../../../public/nshead/libnshead.a \
  ../../../../public/odict/libodict.a \
  ../../../../public/spreg/libspreg.a \
  ../../../../public/ub/output/lib/libub.a \
  ../../../../public/ub/output/lib/libub_aserver.a \
  ../../../../public/ub/output/lib/libub_client.a \
  ../../../../public/ub/output/lib/libub_conf.a \
  ../../../../public/ub/output/lib/libub_galileo.a \
  ../../../../public/ub/output/lib/libub_log.a \
  ../../../../public/ub/output/lib/libub_misc.a \
  ../../../../public/ub/output/lib/libub_monitor.a \
  ../../../../public/ub/output/lib/libub_naming.a \
  ../../../../public/ub/output/lib/libub_server.a \
  ../../../../public/ub/output/lib/libubex.a \
  ../../../../public/ub/output/lib/libubfw.a \
  ../../../../public/uconv/libuconv.a \
  ../../../../quality/autotest/reportlib/cpp/libautotest.a \
  ../../../../third-64/pcre/lib/libpcre.a \
  ../../../../third-64/pcre/lib/libpcrecpp.a \
  ../../../../third-64/pcre/lib/libpcreposix.a \
  ../../../../third-64/protobuf/lib/libprotobuf-lite.a \
  ../../../../third-64/protobuf/lib/libprotobuf.a \
  ../../../../third-64/protobuf/lib/libprotoc.a -lpthread \
  -lcrypto \
  -lrt -Xlinker "-)" -o test_write_failure

test_ul_pack_client_test_ul_pack_client.o:test_ul_pack_client.cpp
	@echo "[[1;32;40mCOMAKE:BUILD[0m][Target:'[1;32;40mtest_ul_pack_client_test_ul_pack_client.o[0m']"
	$(CXX) -c $(INCPATH) $(DEP_INCPATH) $(CPPFLAGS) $(CXXFLAGS)  -o test_ul_pack_client_test_ul_pack_client.o test_ul_pack_client.cpp

test_ul_pack_server_test_ul_pack_server.o:test_ul_pack_server.cpp
	@echo "[[1;32;40mCOMAKE:BUILD[0m][Target:'[1;32;40mtest_ul_pack_server_test_ul_pack_server.o[0m']"
	$(CXX) -c $(INCPATH) $(DEP_INCPATH) $(CPPFLAGS) $(CXXFLAGS)  -o test_ul_pack_server_test_ul_pack_server.o test_ul_pack_server.cpp

test_ul_pack_serial_test_ul_pack_serial.o:test_ul_pack_serial.cpp
	@echo "[[1;32;40mCOMAKE:BUILD[0m][Target:'[1;32;40mtest_ul_pack_serial_test_ul_pack_serial.o[0m']"
	$(CXX) -c $(INCPATH) $(DEP_INCPATH) $(CPPFLAGS) $(CXXFLAGS)  -o test_ul_pack_serial_test_ul_pack_serial.o test_ul_pack_serial.cpp

test_comlog_hostname_test_comlog_hostname.o:test_comlog_hostname.cpp
	@echo "[[1;32;40mCOMAKE:BUILD[0m][Target:'[1;32;40mtest_comlog_hostname_test_comlog_hostname.o[0m']"
	$(CXX) -c $(INCPATH) $(DEP_INCPATH) $(CPPFLAGS) $(CXXFLAGS)  -o test_comlog_hostname_test_comlog_hostname.o test_comlog_hostname.cpp

test_ul_url_test_ul_url.o:test_ul_url.cpp
	@echo "[[1;32;40mCOMAKE:BUILD[0m][Target:'[1;32;40mtest_ul_url_test_ul_url.o[0m']"
	$(CXX) -c $(INCPATH) $(DEP_INCPATH) $(CPPFLAGS) $(CXXFLAGS)  -o test_ul_url_test_ul_url.o test_ul_url.cpp

test_comlog_level_test_comlog_level.o:test_comlog_level.cpp
	@echo "[[1;32;40mCOMAKE:BUILD[0m][Target:'[1;32;40mtest_comlog_level_test_comlog_level.o[0m']"
	$(CXX) -c $(INCPATH) $(DEP_INCPATH) $(CPPFLAGS) $(CXXFLAGS)  -o test_comlog_level_test_comlog_level.o test_comlog_level.cpp

test_comlog_guard_test_comlog_guard.o:test_comlog_guard.cpp
	@echo "[[1;32;40mCOMAKE:BUILD[0m][Target:'[1;32;40mtest_comlog_guard_test_comlog_guard.o[0m']"
	$(CXX) -c $(INCPATH) $(DEP_INCPATH) $(CPPFLAGS) $(CXXFLAGS)  -o test_comlog_guard_test_comlog_guard.o test_comlog_guard.cpp

test_ullog_level_test_ullog_level.o:test_ullog_level.cpp
	@echo "[[1;32;40mCOMAKE:BUILD[0m][Target:'[1;32;40mtest_ullog_level_test_ullog_level.o[0m']"
	$(CXX) -c $(INCPATH) $(DEP_INCPATH) $(CPPFLAGS) $(CXXFLAGS)  -o test_ullog_level_test_ullog_level.o test_ullog_level.cpp

test_com_openlog_r_test_com_openlog_r.o:test_com_openlog_r.cpp
	@echo "[[1;32;40mCOMAKE:BUILD[0m][Target:'[1;32;40mtest_com_openlog_r_test_com_openlog_r.o[0m']"
	$(CXX) -c $(INCPATH) $(DEP_INCPATH) $(CPPFLAGS) $(CXXFLAGS)  -o test_com_openlog_r_test_com_openlog_r.o test_com_openlog_r.cpp

test_comlog_disk_test_comlog_disk.o:test_comlog_disk.cpp
	@echo "[[1;32;40mCOMAKE:BUILD[0m][Target:'[1;32;40mtest_comlog_disk_test_comlog_disk.o[0m']"
	$(CXX) -c $(INCPATH) $(DEP_INCPATH) $(CPPFLAGS) $(CXXFLAGS)  -o test_comlog_disk_test_comlog_disk.o test_comlog_disk.cpp

test_ulnet_read_test_ulnet_read.o:test_ulnet_read.cpp
	@echo "[[1;32;40mCOMAKE:BUILD[0m][Target:'[1;32;40mtest_ulnet_read_test_ulnet_read.o[0m']"
	$(CXX) -c $(INCPATH) $(DEP_INCPATH) $(CPPFLAGS) $(CXXFLAGS)  -o test_ulnet_read_test_ulnet_read.o test_ulnet_read.cpp

test_ulnet_write_test_ulnet_write.o:test_ulnet_write.cpp
	@echo "[[1;32;40mCOMAKE:BUILD[0m][Target:'[1;32;40mtest_ulnet_write_test_ulnet_write.o[0m']"
	$(CXX) -c $(INCPATH) $(DEP_INCPATH) $(CPPFLAGS) $(CXXFLAGS)  -o test_ulnet_write_test_ulnet_write.o test_ulnet_write.cpp

test_write_failure_test_write_failure.o:test_write_failure.cpp
	@echo "[[1;32;40mCOMAKE:BUILD[0m][Target:'[1;32;40mtest_write_failure_test_write_failure.o[0m']"
	$(CXX) -c $(INCPATH) $(DEP_INCPATH) $(CPPFLAGS) $(CXXFLAGS)  -o test_write_failure_test_write_failure.o test_write_failure.cpp

endif #ifeq ($(shell uname -m),x86_64)


