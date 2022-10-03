<?php
require_once ("-MyConnect.php");

if (!empty($_POST["moisture"]))
{
	$moisture= $_POST['moisture'];
	$temperature= $_POST['temp'];

	$query = "INSERT INTO Project (Moisture, Temp) VALUES ('$moisture', '$temperature')";
	$result = mysqli_query($mysqli, $query);
	echo "sent";
} 
else 
{
echo "return=nothing sent";
}


?>
