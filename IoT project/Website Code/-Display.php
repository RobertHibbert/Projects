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
	<title>Admin Display</title>
	<link rel="stylesheet" type="text/css" href="-Style.css" /> <!-- Stylesheet link -->
	</head>
	<body>
		<header class="header" > <!-- this is the header for this page -->
			<h1>Smart Irrigation System - Home Page</h1> 
		</header>
		
			
		<div class="dropdown">
			<button class="dropdowntext">My Account</button>
			<div class="dropdown-content">
				<a href='-Logout.php'>Logout</a>
			</div>
		</div>
		
		<div >
			<h3>Records:</h3>
			
			<?php
			include '-MyConnect.php';

			$sql = "SELECT ID, firstname, surname, email FROM users";
			$result = $mysqli->query ($sql);

			if($result)
			{
				if ($result->num_rows > 0)
				 { // shows the names of rows that will be displayed 
					echo "<table id= table>";
					echo "<thead>";
					echo "<tr>";
					echo "<th>ID</th>";
					echo "<th>Firstname</th>";
					echo "<th>Surname</th>";
					echo "<th>Email</th>";
					echo "</tr>";
					echo "</thead>";
					while($row = $result->fetch_assoc()) 
						{
							// this outputs the data for each row in the database 
							echo "<tr>";
							echo "<td>".$row['ID']."</td>";
							echo "<td>".$row['firstname']."</td>";
							echo "<td>".$row['surname']."</td>";
							echo "<td>".$row['email']."</td>";
							echo'<td><a href="-Edit.php?id='.$row["ID"].'">Edit</a></td>';
							echo'<td><a href="-Delete.php?id='.$row["ID"].'">Delete</a></td>';
							echo "</tr>";
						}
					echo "</table>";
				  
				  } 
				else 
				{
					echo "0 results";
				}
			$result->close();
			$mysqli->close();
			}
			?>
		</div>
	</body>
</html>