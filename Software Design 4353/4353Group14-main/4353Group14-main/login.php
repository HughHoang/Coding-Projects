<?php
include "connect.php";
session_start();

if(isset($_SESSION['user']) && isset($_SESSION['id'])){
    header('Location: home.php');
}
$login = file_get_contents('login.html');
echo $login;
if(isset($_POST['butlogin'])){
       
    $uname = mysqli_real_escape_string($conn,$_POST['username']);
    $password = mysqli_real_escape_string($conn,$_POST['password']);
 
                
    if ($uname != "" && $password != ""){
        $sql_query = "SELECT COUNT(*) AS 'count' FROM usercredentials WHERE username='".$uname."' and password='".$password."'";
        $result = mysqli_query($conn,$sql_query);
        $rows = mysqli_fetch_array($result);
        
        if($rows['count'] > 0){
           
            $sql_query = "SELECT id FROM usercredentials WHERE username='".$uname."' and password='".$password."'";
            $result = mysqli_query($conn,$sql_query);
            $id=mysqli_fetch_array($result)['id'];
            
            $result = mysqli_query($conn,"SELECT * FROM clientinformation WHERE id=".$id."");
            $rows=mysqli_fetch_array($result);
 
            if(mysqli_num_rows($result) == 0){
                header('Location: profilemanagement.php');
                $_SESSION['user'] = $uname;
                $_SESSION['id'] = $id;
            }else{
                $_SESSION['user'] = $uname;
                $_SESSION['id'] = $id;
                $_SESSION['info'] = $rows;
                header('Location: home.php');
            }
        }else{
            echo "<p style=\"color:rgb(255,0,0);\">Invalid username and password</p>";
        }
    }
        
}



?>