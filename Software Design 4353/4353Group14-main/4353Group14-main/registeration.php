<?php
session_start();

include("connect.php"); 
if(isset($_SESSION['user']) && isset($_SESSION['id'])){
    header('Location: home.php');
}else{
    $reg = file_get_contents('registeration.html');
    echo $reg;

    $username="";
    $passwd="";
    //if registerbutton clicked assign values
    if (isset($_POST['registerBtn'])){ 
        $username = $_POST['username']?? '';; 
        $passwd = $_POST['password']?? '';; 
        //if username and password arent empty
        if ($username != "" && $passwd != ""){
            // make sure the password is above 5 characters and dont include illegal characters
            if ( strlen($passwd) >= 5 && strpbrk($passwd, "!#$.,:;()") == false ){
                //query and check if username is not in database
                $query = mysqli_query($conn, "SELECT * FROM usercredentials WHERE username='{$username}'");
                //assigns id based on number of rows in database

                if (mysqli_num_rows($query) == 0){
                    //insert into database
                    mysqli_query($conn, "INSERT INTO usercredentials(username,password) VALUES (
                        '$username',  '$passwd')");
                    
                    // verify the user's account was created
                    $query = mysqli_query($conn, "SELECT * FROM usercredentials WHERE username='{$username}'");
                    
                    if (mysqli_num_rows($query) == 1){
                        header('Location: login.php');            
                    }
                    else
                        echo "<p style=\"color:rgb(255,0,0);\">'An error occurred and your account was not created.</p>'";
                }
                else
                    echo "<p style=\"color:rgb(255,0,0);\">'The username <i>'.$username.'</i> is already taken. Please use another.</p>'";
                
                }
            else
                echo "<p style=\"color:rgb(255,0,0);\">'Your password is not strong enough. Please use another.</p>'";
            }
        else
            echo "<p style=\"color:rgb(255,0,0);\">'Please fill out all required fields.</p>'";
        }
    }


    
    ?>