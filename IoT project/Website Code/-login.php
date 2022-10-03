<!DOCTYPE html>
<html>
<head>
	<link rel="stylesheet" type="text/css" href="-Style.css" /> <!-- Stylesheet link -->
	<title>Login Page</title>
	</head>
<body>
	    <header class="header" > <!-- this is the header for this page -->
		<h1>Smart Irrigation System - Log In</h1> 
		</header>
	
<?php 
include '-MyConnect.php';
if (isset($_POST['submit'])){

$email = mysqli_real_escape_string($mysqli, $_POST['email']); // helps to prevents against sql injection
$password = mysqli_real_escape_string($mysqli, $_POST['password']);	// helps to prevents against sql injection

$stmt = $mysqli->prepare("SELECT * FROM users WHERE email = ?");
$stmt->bind_param('s', $email);

$stmt->execute();

$user = $stmt->get_result()->fetch_assoc();

if (!empty($user['email'])) 
{ 
	$newPass = $user['password'];
    if (password_verify($password, "$newPass"))
    {
        session_start();
        
        $_SESSION['login'] = TRUE;
        $_SESSION['user'] = $user['email'];
        
        If($_SESSION['user'] == "admin")
		{
			header("Location: -Display.php"); //admin page
	    }
        else
        {
			header("Location: -HomePage.php"); // normal home page
		}
         
    } 
	else 
	{
		echo "<p>Login Failed</p>";
    }
} 
else 
{
    echo "<p>Login Failed</p>";
}

$stmt->close();
$mysqli->close();
	}
?>
	
<div class="container">
	<form class="content" method="POST" action="-login.php">
		<h1>Login</h1>
		<hr>
		Email:<br><input type="text" name="email" id="email"/>
		<br>
		Password:<br><input type="password" name="password" id="password"/>
		<br>
		<button class ="close" formaction="-WelcomePage.php" >Cancel</button>
		<input class ="button" type="submit" name="submit" value="Login"/>
	</form>
</div>
</body>
</html>




