<?php
  $dbconn = pg_connect("host=localhost dbname=homework user=postgres password=pass1234") 
    or die('Could not connect: '.pg_last_error()); 
?>