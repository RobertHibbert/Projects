<?php 
session_start();
If($_SESSION['user'] == "admin")
{
}
else
{
   header("Location: -WelcomePage.php"); // if a user is not an admin it will send them to the welcome page
}
?>
<!DOCTYPE html>
<html>
	<head>
	<title>Admin Edit</title>
		<link rel="stylesheet" type="text/css" href="-Style.css" /> <!-- Stylesheet link -->
	</head>
	<body>
		<header class="header" > <!-- this is the header for this page -->
			<h1>Smart Irrigation System - Edit Account</h1> 
		</header>
		<div class="container">
			<?php
			if (isset( $_POST['submit'] ))
			{
				include '-MyConnect.php';

				$updatequery ="UPDATE users SET firstname=?, surname=?, email=?, password=? WHERE ID=?";
				
				$password = mysqli_real_escape_string($mysqli, $_POST['pass']);	// helps to prevents against sql injection
				$email = mysqli_real_escape_string($mysqli, $_POST['email']); // helps to prevents against sql injection
				$sname = mysqli_real_escape_string($mysqli, $_POST['sname']); // helps to prevents against sql injection
				$fname = mysqli_real_escape_string($mysqli, $_POST['fname']); // helps to prevents against sql injection
				
				$stmt = $mysqli->prepare($updatequery);
				$hashpw = password_hash($password, PASSWORD_DEFAULT);
				$stmt->bind_param('sssss',$fname, $sname, $email, $hashpw, $_GET['id']);
				
				if (!$stmt->execute()) {
					echo "Error: ".$mysqli->error;
				}
				else 
				{
					header("Location: -Display.php");
				} 
				$mysqli->close();
			}
			else
			{
				include '-MyConnect.php';
				
				$populatequery = "SELECT * from users WHERE ID=?";
				$stmt = $mysqli->prepare($populatequery);
				$stmt->bind_param('s', $_GET['id']);
				$stmt->execute();
				$result = $stmt->get_result();

				$user = $result->fetch_assoc();
				$fn = $user['firstname'];
				$sn = $user['surname'];
				$em = $user['email'];
			}
			?>
			
			<form class="content" action="-Edit.php?id=<?php echo $_GET['id']; ?>" method="post" >
				<h1>Edit Account:</h1>
				<hr>
				   Firstname: <br><input  type="text" id="fname" name="fname" required/><br>
				   Surname: <br><input  type="text" id="sname" name="sname" required/><br>
				   Email: <br><input  type="email" id="email" name="email"  required/><br>
				   Password: <br><input  type="password" id="pass" name="pass" pattern=".{8,}" required title="8 characters minimum" required/><br>
				<a class ="close" href="-Display.php" >Cancel</a>
				<input class ="button" type="submit" id="submit" name="submit" value="submit">
			</form>	
			
		</div>
	</body>
</html>