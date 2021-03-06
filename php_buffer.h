/*
  +----------------------------------------------------------------------+
  | PHP Version 7                                                        |
  +----------------------------------------------------------------------+
  | Copyright (c) 1997-2016 The PHP Group                                |
  +----------------------------------------------------------------------+
  | This source file is subject to version 3.01 of the PHP license,      |
  | that is bundled with this package in the file LICENSE, and is        |
  | available through the world-wide-web at the following url:           |
  | http://www.php.net/license/3_01.txt                                  |
  | If you did not receive a copy of the PHP license and are unable to   |
  | obtain it through the world-wide-web, please send a note to          |
  | license@php.net so we can mail you a copy immediately.               |
  +----------------------------------------------------------------------+
  | Author: ___Shies <gukai@bilibili.com>                                |
  +----------------------------------------------------------------------+
*/

/* $Id$ */

#ifndef PHP_BUFFER_H
#define PHP_BUFFER_H

extern zend_module_entry buffer_module_entry;
#define phpext_buffer_ptr &buffer_module_entry

#define PHP_BUFFER_VERSION "0.1.0" /* Replace with version number for your extension */

#ifdef PHP_WIN32
#	define PHP_BUFFER_API __declspec(dllexport)
#elif defined(__GNUC__) && __GNUC__ >= 4
#	define PHP_BUFFER_API __attribute__ ((visibility("default")))
#else
#	define PHP_BUFFER_API
#endif

#ifdef ZTS
#include "TSRM.h"
#endif


#define BUFFER_G(v) ZEND_MODULE_GLOBALS_ACCESSOR(buffer, v)

#if defined(ZTS) && defined(COMPILE_DL_BUFFER)
ZEND_TSRMLS_CACHE_EXTERN()
#endif


ZEND_BEGIN_MODULE_GLOBALS(buffer)
    char        *version;
    size_t      version_len;
    char        *author;
    zend_bool   enable;
ZEND_END_MODULE_GLOBALS(buffer)


extern zend_class_entry *buffer_ce;
#define BUFFER_STARTUP(module)                    ZEND_MODULE_STARTUP_N(buffer_##module)(INIT_FUNC_ARGS_PASSTHRU)
#define BUFFER_MINIT_FUNCTION(module)             ZEND_MINIT_FUNCTION(buffer_##module)


PHP_GINIT_FUNCTION(buffer);
PHP_MINIT_FUNCTION(buffer);
PHP_MSHUTDOWN_FUNCTION(buffer);

#endif	/* PHP_BUFFER_H */

/*
 * Local variables:
 * tab-width: 4
 * c-basic-offset: 4
 * End:
 * vim600: noet sw=4 ts=4 fdm=marker
 * vim<600: noet sw=4 ts=4
 */
