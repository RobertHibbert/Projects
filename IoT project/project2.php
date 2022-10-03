<?php
require_once ("-MyConnect.php");

if (!empty($_POST["water"]))
{	
	$query = "UPDATE Project2 SET Water= (Water+0.1) WHERE ID='1'";
	$result = mysqli_query($mysqli, $query);
	echo "sent";
} 
else 
{
echo "return=nothing sent";
}


?>