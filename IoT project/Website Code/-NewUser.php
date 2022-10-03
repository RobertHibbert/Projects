<!DOCTYPE html>
<html>
<head>
	<link rel="stylesheet" type="text/css" href="-Style.css" /> <!-- stylesheet link -->
		<meta charset = "utf-8"> 
<title>New user</title>
<script src="https://ajax.googleapis.com/ajax/libs/jquery/3.4.1/jquery.min.js"></script>
<script src="checkscript.js"></script>
<script>
  $( document ).ready(function()
  {
      $("#submit").prop('disabled',true);
  });
</script>
</head>
<body>
		<header class="header" > <!-- This is the header for this page -->
		<h1>Smart Irrigation System - New User</h1> 
		</header>

<?php
if ($_SERVER['REQUEST_METHOD'] == 'POST')
{
include '-MyConnect.php';
	if (!isset( $_POST['submit'] ))
	{
		echo "<p>ERROR form was not submitted</p>";
	}
	else 
	{
		$password = mysqli_real_escape_string($mysqli, $_POST['pass']);	// helps to prevents against sql injection
		$email = mysqli_real_escape_string($mysqli, $_POST['email']); // helps to prevents against sql injection
		$sname = mysqli_real_escape_string($mysqli, $_POST['sname']); // helps to prevents against sql injection
		$fname = mysqli_real_escape_string($mysqli, $_POST['fname']); // helps to prevents against sql injection
		
		$hashpw = password_hash($password, PASSWORD_DEFAULT);
		$sql = "insert into users (firstname, surname, email, password) values (?,?,?,?)";
		$stmt = $mysqli->prepare($sql);
		$stmt->bind_param('ssss', $fname, $sname, $email, $hashpw);
		if (!$stmt->execute()) 
		{
			echo "Error: ". $mysqli->error;
		}
		else 
		{
			header("Location: -login.php");
		} 
		$mysqli->close();
	}
}
?>

<div class="container">

	<form class="content" method="POST" action="-NewUser.php" >
		<h3>Create new user</h3>
		<hr>
	   Firstname: <br><input  type="text" id="fname" name="fname" required/><br>
	   Surname: <br><input  type="text" id="sname" name="sname" required/><br>
	   Email: <br><input  type="email" id="email" name="email" onblur="checkUser()" required/><span id="message"></span><br>
	   Password: <br><input  type="password" id="pass" name="pass" pattern=".{8,}" required title="8 characters minimum" required/><br>

	   <a class ="close" href="-WelcomePage.php" >Cancel</a>
	   <input class ="button" type="submit" name="submit" value="submit"/>
	</form>
</div>

</body>
</html>




