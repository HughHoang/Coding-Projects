<?php
include('connect.php');
session_start();

if(!(isset($_SESSION['user']) && isset($_SESSION['id']))){
    header('Location: login.php');
}else if(!(isset($_SESSION['info']))){
    header('Location: profilemanagement.php');
}else{
    $hist = file_get_contents('fuelquoteshistory.html');
    echo $hist;

    $id = $_SESSION['id'];
    $result = mysqli_query($conn,"SELECT * FROM fuelquote WHERE userID=".$id."");
    $rows=mysqli_fetch_array($result);

    if(mysqli_num_rows($result)!=0){
        echo "<table class=\"center\" border=1>";  

        for ($row = 0; $row < mysqli_num_rows($result); $row++) {
            echo "<tr>";
            
            echo "<td>".$rows['gallons']."</td>";
            echo "<td class = \"address\">".$rows['deliveryAdd']."</td>";
            echo "<td class = \"date\">".$rows['deliveryDate']."</td>";
            echo "<td>".$rows['price']."</td>";
            echo "<td>".$rows['totalDue']."</td>";

            echo "</tr>";
        }
        echo "</table>";
    }
}
?>