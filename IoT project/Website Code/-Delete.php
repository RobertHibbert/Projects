<!DOCTYPE html>

<html>
<head>
<title>Admin Delete</title>
	<link rel="stylesheet" type="text/css" href="-Style.css" /> <!-- Stylesheet link -->
</head>
<body>
	<header class="header" > <!-- This is the header for this page -->
		<h1>Preston Cars - Delete Account</h1> 
	</header>
	
	<form class="content" >
		<h1>Are you sure?</h1>
		<hr>
		<button class ="close" formaction="-Display.php" >No - Go back</button>
	 	<a class="button" href="-Delete.php?id=<?php echo $_GET['id']?>&sure=TRUE">Yes</a>
    </form>	
		
	<?php
	if(isset($_GET['sure'])){
		if($_GET['sure'] == TRUE){
			include '-MyConnect.php';

			$deletequery = "DELETE FROM users WHERE ID=?";
			$stmt = $mysqli->prepare($deletequery);
			$stmt->bind_param('s', $_GET['id']);
			$stmt->execute();

			header("location: -Display.php");
		}
	}
	?>
</body>
</html>