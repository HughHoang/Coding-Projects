--TEST--
Test for bug #1209: Tracing property assignments in user-readable function traces (PHP < 8)
--INI--
xdebug.mode=trace
xdebug.start_with_request=no
xdebug.trace_format=0
xdebug.collect_return=0
xdebug.collect_assignments=0
--SKIPIF--
<?php
require __DIR__ . '/../utils.inc';
check_reqs('PHP < 8');
?>
--FILE--
<?php
require_once 'capture-trace.inc';

function foo()
{
	$newfunc = @create_function('$a,$b', 'return "ln($a) + ln($b) = " . log($a * $b);');
	echo "New anonymous function: $newfunc\n";
	echo $newfunc(2, M_E) . "\n";

	return $newfunc;
}

$f = foo();

echo $f(2, M_PI), "\n";

xdebug_stop_trace();
?>
--EXPECTF--
New anonymous function:  lambda_1
ln(2) + ln(2.718281828459) = 1.6931471805599
ln(2) + ln(3.1415926535898) = 1.8378770664093
TRACE START [%d-%d-%d %d:%d:%d.%d]
%w%f %w%d     -> foo() %sbug01209.php:13
%w%f %w%d       -> create_function($args = '$a,$b', $code = 'return "ln($a) + ln($b) = " . log($a * $b);') %sbug01209.php:6
%w%f %w%d         -> {internal eval}() %sbug01209.php:6
%w%f %w%d       -> __lambda_func($a = 2, $b = 2.718281828459) %sbug01209.php:8
%w%f %w%d         -> log($number = 5.4365636569181) %sbug01209.php(6) : runtime-created function:1
%w%f %w%d     -> __lambda_func($a = 2, $b = 3.1415926535898) %sbug01209.php:15
%w%f %w%d       -> log($number = 6.2831853071796) %sbug01209.php(6) : runtime-created function:1
%w%f %w%d     -> xdebug_stop_trace() %sbug01209.php:17
%w%f %w%d
TRACE END   [%d-%d-%d %d:%d:%d.%d]
