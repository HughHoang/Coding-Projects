--TEST--
Test for bug #1140: Tracing with __debugInfo() crashes Xdebug due to a stack overflow (PHP < 8.0)
--SKIPIF--
<?php
require __DIR__ . '/../utils.inc';
check_reqs('PHP < 8.0');
?>
--INI--
xdebug.mode=trace,develop
xdebug.start_with_request=no
xdebug.trace_format=0
xdebug.dump_globals=0
xdebug.collect_return=0
xdebug.collect_assignments=0
xdebug.force_error_reporting=0
--FILE--
<?php
class Foo
{
	function __debugInfo()
	{
		$p = get_object_vars( $this );
		return $p;
	}
}

require_once 'capture-trace.inc';

$a = new Foo;
var_dump( $a );
	
xdebug_stop_trace();
?>
== I didn't crash ==
--EXPECTF--
%sbug01140-php74.php:14:
class Foo#%d (0) {
}
== I didn't crash ==
TRACE START [%d-%d-%d %d:%d:%d.%d]
%w%f %w%d     -> var_dump(...$vars = variadic(0 => class Foo {  })) %sbug01140-php74.php:14
%w%f %w%d     -> xdebug_stop_trace() %sbug01140-php74.php:16
%w%f %w%d
TRACE END   [%d-%d-%d %d:%d:%d.%d]
