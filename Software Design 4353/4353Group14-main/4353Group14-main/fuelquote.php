<?php
include("connect.php");
session_start();


if(!(isset($_SESSION['user']) && isset($_SESSION['id']))){
    header('Location: login.php');
}else if(!(isset($_SESSION['info']))){
    header('Location: profilemanagement.php');
}else{
    $form = file_get_contents('fuelquoteform.html');
    echo $form;

    if(isset($_POST['butfuelsubmit'])){

    $gallonsrequest = mysqli_real_escape_string($con,$_POST['gallonsrequest']);
    $deliveryaddress = mysqli_real_escape_string($con,$_POST['deliveryaddress']);
    $deliverydate = mysqli_real_escape_string($con,$_POST['deliverydate']);

     //if username and password arent empty
     if ($gallonsrequest != "" && $deliveryaddress != ""&& $deliverydate != ""){
        // make sure the password is above 5 characters and dont include illegal characters
        if (mysqli_num_rows($query) == 0){
            $id = $length;
            //insert into database
            mysqli_query($conn, "INSERT INTO clientinformation VALUES (
                '{$gallonsrequest}', '{$deliveryaddress}',  '{$deliverydate}''
            )");
        }
    }
    else
        $error_msg = 'Please fill out all required fields.';

    }
}

?>