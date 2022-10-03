<?php 
	session_start();
	include '-MyConnect.php'; //connects to the database
	If($_SESSION['login'] == TRUE) // if a user is logged in
	{
	}
	else // if a user is not logged in 
	{
	   header("Location: -WelcomePage.php");
	}
?>

<!DOCTYPE html>
<html lang = "en"> 
	
	<head>
		<link rel="stylesheet" type="text/css" href="-Style.css" /> <!-- link to the stylesheet -->
		<meta charset = "utf-8"> 
		<title>Statistics Page</title> 
		
		<!-- the following script is gathered from https://www.gstatic.com/charts/loader.js and is used to create a scatter chart -->
		<script type="text/javascript" src="https://www.gstatic.com/charts/loader.js"></script>
		<script type="text/javascript">
		  google.charts.load('current', {'packages':['corechart']});
		  google.charts.setOnLoadCallback(drawChart);

		  function drawChart() {
			var data = google.visualization.arrayToDataTable([
			  ['Moisture', 'Moisture/Temperature'],
			  	
		// the php script gathers the data from the database for the moisture and temperature values
		<?php 
		$query = "SELECT * FROM Project";
		$result = mysqli_query($mysqli, $query);
		while($row = mysqli_fetch_assoc($result)) 
		{
			?> [ <?php echo $row["Moisture"]; ?> , <?php echo $row["Temp"]; ?> ], <?php
		}
		?>
		
		]);

			var options = {
			  title: 'Temperaturer and Moisture comparison',
			  hAxis: {title: 'Moisture (Percentage)', minValue: 0, maxValue: 100},
			  vAxis: {title: 'Temperature (Fahrenheit)', minValue: 0, maxValue: 100},
			  legend: 'none'
			};

			var chart = new google.visualization.ScatterChart(document.getElementById('chart_div'));

			chart.draw(data, options);
		  }
		</script>
	</head>
	
	<body>
		
		<header class="header" > <!-- This is the header for this page -->
			<h1>Smart Irrigation System - Statistics</h1> 
		</header>
		
		<div class = "nav"><!-- this links all of the pages together with links to each one-->
			<a href="-HomePage.php">Home Page</a>
			<a>Statistics</a>
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
		
		<table id= table> 
			<thead>
			<tr>
			<th>Temperature (Fahrenheit)</th> <!-- table header name-->
			<th>Moisture (Percentage)</th> <!-- table header name-->
			</tr>
			</thead>
			
			<tr>
			<td> <!-- average temp value gathered from database-->
			<?php 
				$sql = "SELECT AVG(Temp) AS average_temp FROM Project";
				$query1 = $mysqli->query($sql);
				$row1 = $query1->fetch_assoc();
				echo "Average Temperature Value: ".$row1['average_temp'];
			?>
			°F
			</td>
			<td> <!-- average moisture value gathered from database-->
			<?php 
				$sql = "SELECT AVG(Moisture) AS average_moisture FROM Project";
				$query1 = $mysqli->query($sql);
				$row1 = $query1->fetch_assoc();
				echo "Average Moisture Percentage: ".$row1['average_moisture'];
			?>
			%
			</td>
			</tr>
			
			<tr>
			<td> <!-- max temp value gathered from database-->
			<?php 
				$sql = "SELECT MAX(Temp) AS highest_temp FROM Project";
				$query1 = $mysqli->query($sql);
				$row1 = $query1->fetch_assoc();
				echo "Highest Temperature Value: ".$row1['highest_temp'];
			?>
			°F
			</td>
			<td> <!-- max moisture value gathered from database-->
			<?php 
				$sql = "SELECT MAX(Moisture) AS highest_moisture FROM Project";
				$query1 = $mysqli->query($sql);
				$row1 = $query1->fetch_assoc();
				echo "Highest Moisture Percentage: ".$row1['highest_moisture'];
			?>
			%
			</td>
			</tr>
			
			<tr>
			<td> <!-- min temp value gathered from database-->
			<?php 
				$sql = "SELECT MIN(Temp) AS min_temp FROM Project";
				$query1 = $mysqli->query($sql);
				$row1 = $query1->fetch_assoc();
				echo "Minimum Temperature Value: ".$row1['min_temp'];
			?>
			°F
			</td>
			<td> <!-- min moisture value gathered from database-->
			<?php 
				$sql = "SELECT MIN(Moisture) AS min_moisture FROM Project";
				$query1 = $mysqli->query($sql);
				$row1 = $query1->fetch_assoc();
				echo "Minimum Moisture Percentage: ".$row1['min_moisture'];
			?>
			%
			</td>
			</tr>
			
		</table>
		   
		<br>
		<div id="chart_div"></div> <!-- creates a scatter chart. The code is from - https://www.gstatic.com/charts/loader.js -->
		
	</body>
</html>