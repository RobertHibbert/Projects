<?php 
session_start();
If($_SESSION['login'] == TRUE) // if a user is logged in they will be taken to the welcome page
{
	session_destroy();
	header("Location: -WelcomePage.php"); 
}
else// if no user is logged in they will still be taken to the welcome page
{
   header("Location: -WelcomePage.php");
}
?>
<!DOCTYPE html>
<html>
<head>
<title>Logout</title>
</head>
<body>

</body>
</html>