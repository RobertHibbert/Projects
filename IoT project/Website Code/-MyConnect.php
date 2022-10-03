<?php

// Create connection
$mysqli = mysqli_connect("localhost", "rthibbert", "UqkB3188", "rthibbert");
// Check connection
if ($mysqli->connect_error) {
    die("Connection failed: " . $mysqli->connect_error);
}
?> 