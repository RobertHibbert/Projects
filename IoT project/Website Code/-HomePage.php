<?php 
session_start();
If($_SESSION['login'] == TRUE)// if a user is logged in
{
}
else// if a user is not logged in 
{
	header("Location: -WelcomePage.php");
}
?>

<!DOCTYPE html>
<html lang = "en"> 
	
	<head>
		<link rel="stylesheet" type="text/css" href="-Style.css" /> <!-- link to the stylesheet -->
		<meta charset = "utf-8"> 
		<title>Home Page</title> 
	</head>
	
	<body>
	
		<header class="header" > <!-- This is the header for this page -->
			<h1>Smart Irrigation System - Home Page</h1> 
		</header>
		
		<div class = "nav"><!-- this links all of the pages together with links to each one-->
			<a>Home Page</a>
			<a href="-Statistics.php">Statistics</a>
			<a href="-WaterUsage.php">Water Usage</a>
			<a href="-ContactPage.php">Contact Page</a>
		</div>
		
		<!-- The code below is a drop down box to allow the user to sign out -->
		<div class="dropdown">
			<button class="dropdowntext">My Account</button>
			<div class="dropdown-content">
				<a href='-Logout.php'>Logout</a>
			</div>
		</div>
		
			<table id="hometext"> 
				<tr>
					<th>Welcome</th> <!-- These are the headings for the text on the home page-->	
					<th>News today</th>
				</tr>
				<tr>
					<td><p> Welcome to the Smart Irrigation System home page, please use the navigation bar at the top</p></td>
					<td><p> Any news about product recalls or software updates will be displayed here</p></td>
				</tr>
			</table>
			
	</body>
</html>